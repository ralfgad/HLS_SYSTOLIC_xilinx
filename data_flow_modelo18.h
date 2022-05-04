#include <ap_int.h>
#include <hls_stream.h>
#include <string.h>


#ifndef BLOCK_SIZE
#define BLOCK_SIZE 2
#endif


#define TEST_SIZE_L 10
#define TEST_SIZE_K 50
#define TEST_SIZE_M 16
#define TEST_SIZE_N 4

float tanh_soft(float x);




//top function
void MVM_opcion_sistolica(float *input1, float *input2, float *output, int MM, int NN) ;
//other functions
