#include <ap_int.h>
#include <hls_stream.h>
#include <string.h>


#ifndef BLOCK_SIZE
#define BLOCK_SIZE 4
#endif


#define TEST_SIZE_L 10
#define TEST_SIZE_K 50
#define TEST_SIZE_M 32
#define TEST_SIZE_N 64

float tanh_soft(float x);




//top function
void MVM_opcion7_super_mejorada(float *input1, float *input2, float *output, int MM, int NN) ;
//other functions
void producer(float *activacion, float * weight,  int DESTINO, int ORIGEN);
void layer1(int DESTINO, int ORIGEN);
void consumer(float *activacion,  int DESTINO);
