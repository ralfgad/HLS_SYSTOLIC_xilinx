include <ap_int.h>
#include <hls_stream.h>
#include <string.h>

#ifndef BLOCK_SIZE
#define BLOCK_SIZE 16
#endif

//read_input(): Read Data from Global Memory and write into Stream inStream
static void read_input(int *input, hls::stream<int> &inStream, int size) {
mem_rd:
    for (int i = 0; i < size; i++) {
       #pragma HLS PIPELINE II=1
       #pragma HLS LOOP_TRIPCOUNT min=c_size max=c_size
        //Blocking write command to inStream
        inStream << input[i];
    }
}

//adder(): Read Input data from inStream and write the result into outStream
static void adder(hls::stream<int> &inStream,
                  hls::stream<int> &outStream,
                  int incr,
                  int size) {
execute:
    for (int i = 0; i < size; i++) {
       #pragma HLS PIPELINE II=1
       #pragma HLS LOOP_TRIPCOUNT min=c_size max=c_size
        int inVar = inStream.read();
        int adderedVal = inVar + incr;
        //Blocking read command from inStream and Blocking write command
        //to outStream
        outStream << adderedVal;
    }
}

//write_result(): Read result from outStream and write the result to Global Memory
static void write_result(int *output, hls::stream<int> &outStream, int size) {
mem_wr:
    for (int i = 0; i < size; i++) {
       #pragma HLS PIPELINE II=1
       #pragma HLS LOOP_TRIPCOUNT min=c_size max=c_size
        //Blocking read command from OutStream
        output[i] = outStream.read();
    }
}

extern "C" {
void N_stage_Adders(int *input, int *output, int incr, int size) {
#pragma HLS INTERFACE m_axi port = input offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = output offset = slave bundle = gmem
#pragma HLS INTERFACE s_axilite port = input bundle = control
#pragma HLS INTERFACE s_axilite port = output bundle = control
#pragma HLS INTERFACE s_axilite port = incr bundle = control
#pragma HLS INTERFACE s_axilite port = size bundle = control
#pragma HLS INTERFACE s_axilite port = return bundle = control

    //array of stream declaration
    static hls::stream<int> streamArray[STAGES + 1];

   #pragma HLS dataflow
    //one read input unit for data read
    read_input(input, streamArray[0], size);
compute_loop:
    for (int i = 0; i < STAGES; i++) {
       #pragma HLS UNROLL
        // total 4 units of adder(). each is compute vector addition
        // and sending result to immediate next unit using stream
        // datatype
        adder(streamArray[i], streamArray[i + 1], incr, size);
    }
    //one write result unit to write result back to global Memory
    write_result(output, streamArray[STAGES], size);
}
}
