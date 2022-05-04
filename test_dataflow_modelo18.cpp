

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data_flow_modelo18.h"

#define SEED 4



int main(void) {

	float A[TEST_SIZE_N];
	float B1[TEST_SIZE_M*TEST_SIZE_N];
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
			B1[j*TEST_SIZE_N+i] = (getRand() - 0.5) / 2;

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
/*
	ACTIVACIONIN mm_A(A, TEST_SIZE_N * sizeof(float));
	PESO mm_B1(B1, TEST_SIZE_N*TEST_SIZE_M * sizeof(float));
	//ihc::mm_host<float, ihc::aspace<5>, ihc::dwidth<16>, ihc::awidth<32>, ihc::waitrequest<true>, ihc::latency<0> >mm_B2(B2, TEST_SIZE_K*TEST_SIZE_M * sizeof(float));
	//ihc::mm_host<float, ihc::aspace<6>, ihc::dwidth<16>, ihc::awidth<32>, ihc::waitrequest<true>, ihc::latency<0> >mm_B3(B3, TEST_SIZE_L*TEST_SIZE_K * sizeof(float));
	ACTIVACIONOUT mm_C(C, TEST_SIZE_M * sizeof(float));
*/

	// Run the component
	MVM_opcion_sistolica( A, B1, C,TEST_SIZE_M, TEST_SIZE_N );

	// Check the output
	bool passed = true;
	for (int i = 0; i < TEST_SIZE_M; ++i) {
		float obtenido;
		float target;
		temp = 0;
		for (int j = 0; j < TEST_SIZE_N; ++j) {
			temp = A[j] * B1[i*TEST_SIZE_N+j] + temp;
		}

		target = tanh(temp);
	//	target = temp;
		target1[i] = target;
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

