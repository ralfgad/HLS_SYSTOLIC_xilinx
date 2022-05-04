#include <ap_int.h>
#include <hls_stream.h>
#include <string.h>

#ifndef BLOCK_SIZE
#define BLOCK_SIZE 16
#endif

#define L 10
#define K 50
#define M 10
#define N 78
hls::stream<	float> layer1_layer2;
//hls::stream<float, ihc::buffer<K>> layer2_layer3;
hls::stream<	float> a;
hls::stream<	float> b1;


void producer(float *activacion, float * weight,  int DESTINO, int ORIGEN)
{
	for (int j = 0; j < DESTINO; ++j)
	{
		for (int i = 0; i < ORIGEN; ++i) {
			a.write(activacion[i]);
			b1.write(weight[j*ORIGEN + i]);
		}

	}
}


void layer1(int DESTINO, int ORIGEN)
{



		float current;
		float temp;
		float temp2;
		float a_fp16;
		float b_fp16;

		for (ap_int<8> j = 0; j < DESTINO; ++j) {
			float intermedios[BLOCK_SIZE] ;


			for (ap_int<8> i = 0; i < ORIGEN; ++i) {
				a_fp16 = a.read();
				b_fp16 = b1.read();

				current = a_fp16 * b_fp16 + intermedios[0];
#pragma unroll
				for (ap_int<8> k = 0; k < BLOCK_SIZE-1; ++k) {
					intermedios[k] = intermedios[k + 1];
				}
				intermedios[BLOCK_SIZE - 1] = current;
			}
			temp = 0;
#pragma unroll
			for (ap_int<8> k = 0; k < BLOCK_SIZE ; ++k) {
				temp = intermedios[k] + temp;
			}
			temp2 = tanh(temp);
			layer1_layer2.write(temp2);
		}



}

void consumer(float *activacion,  int DESTINO)
{
	for (int j = 0; j < DESTINO; ++j) {
		activacion[j] = layer1_layer2.read();
	}
}




void MVM_opcion7_super_mejorada(float *input1, float *input2, float *output, int MM, int NN) {
#pragma HLS INTERFACE m_axi port = input1 offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = input2 offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = output offset = slave bundle = gmem
#pragma HLS INTERFACE s_axilite port = input1 bundle = control
#pragma HLS INTERFACE s_axilite port = input2 bundle = control
#pragma HLS INTERFACE s_axilite port = output bundle = control
#pragma HLS INTERFACE s_axilite port = MM bundle = control
#pragma HLS INTERFACE s_axilite port = NN bundle = control
#pragma HLS INTERFACE s_axilite port = return bundle = control



   #pragma HLS dataflow
    //one read input unit for data read
    producer(input1, input2, MM, NN);
    layer1(MM,NN);
    //one write result unit to write result back to global Memory
    consumer(output,  MM);
}

