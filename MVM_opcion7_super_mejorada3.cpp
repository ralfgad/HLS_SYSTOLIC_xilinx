//  Copyright (c) 2020 Intel Corporation                                  
//  SPDX-License-Identifier: MIT                 


//simplemente he aumentado el tama�o del shift a 4 
//HAGO EL TAMA�O DEL SHIFTER EN BASE A UN PARAMETRO BLOCK_SIZE

#include <stdio.h>
#include <stdlib.h>
#include "HLS/hls.h"
#include "HLS/hls_float.h"

#include "libreria/float_lib12.h"

#ifndef BLOCK_SIZE
#define BLOCK_SIZE 16
#endif

#define L 10
#define K 50
#define M 10
#define N 78
ihc::stream<	ihc::bfloat16, ihc::buffer<M>> layer1_layer2;
ihc::stream<float, ihc::buffer<K>> layer2_layer3;
ihc::stream<	ihc::bfloat16, ihc::buffer<N * M>> a;
ihc::stream<	ihc::bfloat16, ihc::buffer<N*M >> b1;
ihc::stream<float, ihc::buffer<M*K>> b2;
ihc::stream<float, ihc::buffer<K*L >> b3;
ihc::stream<	ihc::bfloat16, ihc::buffer<L >> sal;

typedef ihc::mm_host<float, ihc::aspace<1>, ihc::dwidth<32>, ihc::awidth<32> > ACTIVACIONIN;
typedef ihc::mm_host<float, ihc::aspace<2>, ihc::dwidth<32>, ihc::awidth<32> > PESO;
typedef ihc::mm_host<float, ihc::aspace<3>, ihc::dwidth<32>, ihc::awidth<32> > ACTIVACIONOUT;


void producer(ACTIVACIONIN *activacion, PESO * weight,  int DESTINO, int ORIGEN)
{
	for (int j = 0; j < DESTINO; ++j)
	{
		for (int i = 0; i < ORIGEN; ++i) {
			a.write((*activacion)[i]);
			b1.write((*weight)[j*ORIGEN + i]);
		}

	}
}


void layer1(int DESTINO, int ORIGEN)
{



		ihc::bfloat16 current;
		ihc::bfloat16 temp;
		ihc::bfloat16 temp2;
		ihc::bfloat16 a_fp16;
		ihc::bfloat16 b_fp16;

		for (uint8 j = 0; j < DESTINO; ++j) {
			ihc::bfloat16 intermedios[BLOCK_SIZE] = {[0 ... BLOCK_SIZE-1] =0 };


			for (uint8 i = 0; i < ORIGEN; ++i) {
				a_fp16 = a.read();
				b_fp16 = b1.read();

				current = a_fp16 * b_fp16 + intermedios[0];
#pragma unroll 
				for (uint8 k = 0; k < BLOCK_SIZE-1; ++k) {
					intermedios[k] = intermedios[k + 1];
				}
				intermedios[BLOCK_SIZE - 1] = current;
			}
			temp = 0;
#pragma unroll
			for (uint8 k = 0; k < BLOCK_SIZE ; ++k) {
				temp = intermedios[k] + temp;
			}
			temp2 = my_tanhfp16(temp);
			layer1_layer2.write(temp2);
		}



}

void consumer(ACTIVACIONOUT *activacion,  int DESTINO)
{
	for (int j = 0; j < DESTINO; ++j) {
		(*activacion)[j] = layer1_layer2.read();
	}
}
/*
template <ihc::stream<float> &ENTRADA, ihc::stream<float> &PESO, ihc::stream<float> &SALIDA>
	void layer2()
{

	float temp, temp2;
	float a_fp16;
	float b_fp16;

	for (int j = 0; j < K; ++j) {
		temp = 0;

		for (int i = 0; i < M; ++i) {

			a_fp16 = ENTRADA.read();
			b_fp16 = PESO.read();
			temp = a_fp16 * b_fp16 + temp;
		}
		temp2 = tanh_soft(temp);
		SALIDA.write(temp2);
	}
}
template <ihc::stream<float> &ENTRADA, ihc::stream<float> &PESO, ihc::stream<float> &SALIDA>
void layer3()
{

	float temp, temp2;
	float a_fp16;
	float b_fp16;

	for (int j = 0; j < L; ++j) {
		temp = 0;

		for (int i = 0; i < K; ++i) {

			a_fp16 = ENTRADA.read();
			b_fp16 = PESO.read();
			temp = a_fp16 * b_fp16 + temp;
		}
		temp2 = tanh_soft(temp);
		SALIDA.write(temp2);
	}
}
*/
hls_avalon_slave_component
void component MVM_opcion7_super_mejorada( 
	//hls_avalon_slave_register_argument int LL,  //B3_width
	//hls_avalon_slave_register_argument int KK,  //B2_width
	hls_avalon_slave_register_argument int MM,  //B1_width
	hls_avalon_slave_register_argument int NN,  //A_width

	hls_avalon_slave_register_argument ACTIVACIONIN & aa,
	hls_avalon_slave_register_argument PESO & bb,
	hls_avalon_slave_register_argument ACTIVACIONOUT & cc)
{ 



ihc::launch<producer>(&aa,&bb,MM,NN);
ihc::launch<layer1>(MM,NN);
ihc::launch<consumer>(&cc,MM);
ihc::collect<producer>();
ihc::collect<layer1>();
ihc::collect<consumer>();

}



#define TEST_SIZE_L 10
#define TEST_SIZE_K 50
#define TEST_SIZE_M 32
#define TEST_SIZE_N 64
#define SEED 4

int main(void) {

	float A[TEST_SIZE_N];
	float B1[TEST_SIZE_M][TEST_SIZE_N];
	float B2[TEST_SIZE_K][TEST_SIZE_M];
	float B3[TEST_SIZE_L][TEST_SIZE_K];
	float C[TEST_SIZE_M];

	float target1[TEST_SIZE_M];
	float target2[TEST_SIZE_K];

	float temp ;

	bool fequal(float a, float b, float epsilon);
	float getRand(void);
	float tanh_soft(float x);
	//ihc::stream_out<float, ihc::bitsPerSymbol<8>, ihc::firstSymbolInHighOrderBits<true>> str_C;


	// Prepare the input data
	srand(SEED);
	for (int i = 0; i < TEST_SIZE_N; ++i) {
		A[i] = (getRand() - 0.5) * 2;
		for (int j = 0; j < TEST_SIZE_M; ++j) {
			B1[j][i] = (getRand() - 0.5) / 2;

		}
	}
	for (int i = 0; i < TEST_SIZE_M; ++i) {
		for (int j = 0; j < TEST_SIZE_K; ++j) {
			B2[j][i] = (getRand() - 0.5) / 2;

		}
	}
	for (int i = 0; i < TEST_SIZE_K; ++i) {
		for (int j = 0; j < TEST_SIZE_L; ++j) {
			B3[j][i] = (getRand() - 0.5) / 2;

		}
	}

	//create de mm_host

	ACTIVACIONIN mm_A(A, TEST_SIZE_N * sizeof(float));
	PESO mm_B1(B1, TEST_SIZE_N*TEST_SIZE_M * sizeof(float));
	//ihc::mm_host<float, ihc::aspace<5>, ihc::dwidth<16>, ihc::awidth<32>, ihc::waitrequest<true>, ihc::latency<0> >mm_B2(B2, TEST_SIZE_K*TEST_SIZE_M * sizeof(float));
	//ihc::mm_host<float, ihc::aspace<6>, ihc::dwidth<16>, ihc::awidth<32>, ihc::waitrequest<true>, ihc::latency<0> >mm_B3(B3, TEST_SIZE_L*TEST_SIZE_K * sizeof(float));
	ACTIVACIONOUT mm_C(C, TEST_SIZE_M * sizeof(float));


	// Run the component
	MVM_opcion7_super_mejorada(TEST_SIZE_M, TEST_SIZE_N,  mm_A, mm_B1, mm_C);

	// Check the output
	bool passed = true;
	for (int i = 0; i < TEST_SIZE_M; ++i) {
		float obtenido;
		float target;
		temp = 0;
		for (int j = 0; j < TEST_SIZE_N; ++j) {
			temp = A[j] * B1[i][j] + temp;
		}
		target1[i] = tanh(temp);
		target = tanh(temp);
		obtenido = C[i];
		bool data_okay = fequal(obtenido, target, 0.02);
		passed &= data_okay;
		if (!data_okay) {
			printf("ERROR: C_obtenido[%d] = %f != %f\n", i, obtenido, target);
	}
		/*
	for (int i = 0; i < TEST_SIZE_K; ++i) {
		temp = 0;
		for (int j = 0; j < TEST_SIZE_M; ++j) {
			temp = target1[j] * B2[i][j] + temp;
		}
		target2[i] = tanh(temp);
	}
	for (int i = 0; i < TEST_SIZE_L; ++i) {
		float obtenido;
		float target;
		temp = 0;
		for (int j = 0; j < TEST_SIZE_K; ++j) {
			temp = target1[j] * B2[i][j] + temp;
		}
		target = tanh(temp);
		obtenido = C[i];
		bool data_okay = fequal(obtenido, target, 0.02);
		passed &= data_okay;
		if (!data_okay) {
			printf("ERROR: C_obtenido[%d] = %f != %f\n", i, obtenido, target);

		}
		*/
	}

	if (passed) {
		printf("PASSED\n");
	}
	else {
		printf("FAILED\n");
	}

	return 0;
}
bool fequal(float a, float b, float epsilon)
{
	return fabs(a - b) < epsilon;
}
float getRand(void)
{
	return ((float)rand()) / (float)RAND_MAX;
}
float tanh_soft(float x)
{
	return  (1.0 - exp(-2 * x)) / (1.0 + exp(-2 * x));
}