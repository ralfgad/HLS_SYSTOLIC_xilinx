//  Copyright (c) 2020 Intel Corporation                                  
//  SPDX-License-Identifier: MIT                                          

//si que va y las layer tienen argumentos
//voy a ver si puedo quitar el buffer del streaming
//voy a intentar un stream loop en la primera capa
//añado las tres capas
//lo hago fp16
//trabajo con memorias embebidas a 64 bits
//TRASPONGO B2 POR SOFTWARE NO EN EL COMPONENTE

//la solucion 24 es una solucion basada en 21 con los siguientes cambios

//solo para FPhalf
//con BLOCK_SIZE=4 para que entre en una de1_soc
//ambas cuestiones las comparte con la version 23
//lo que la diferencia es que en las capas verticales, el sumadorio deslizante lo diseño como un punto fijo de 32 bits
//lo cual obliga a cambiar las funciones que hacen el q=a*b+c ya que q y c serán un punto fijo de 32 bits
//y al final la tanh tambien la tengo que cambiar para hacerla de punto fijo 32 bits a FPhalf

#include <stdio.h>
#include <stdlib.h>
#ifdef __INTELFPGA_COMPILER__ 
#include "HLS/ac_int.h" 
#else 
#include "ref/ac_int.h" 
#endif
#include "HLS/hls.h"
#include "HLS/hls_float.h"
#include "HLS/hls_float_math.h"

#include "libreria/float_lib12.h"
#ifndef tipo_oper
#define tipo_oper FPsingle
#endif
#ifndef noper
#define noper 1
#endif

#define t_oper ihc::tipo_oper
#ifndef tabla 
#define tabla false
#endif
#ifndef BLOCK_SIZE
#define BLOCK_SIZE 4
#endif

#if noper==1
#include "Mis_tasks_mejora_grano_fino_V_H_V_best21.h"
#endif

#if noper==3
#include "Mis_tasks_mejora_grano_fino_V_H_V_best24_half.h"
#endif


#define LOOPS_SIZE 1024




unsigned constexpr ID = 42; // can be any unique value
unsigned constexpr CAPACITY = 128;//divido por 8
using MiSistema = TaskSystem<ID, t_oper, float, CAPACITY, BLOCK_SIZE  >;
//extern	TaskSystem<ID, t_oper, float, CAPACITY, BLOCK_SIZE  >  misistema1;
hls_avalon_slave_component
component void MVM_opcion_systolic_ddr( 
	hls_avalon_slave_register_argument int LL,  //B3_width
	hls_avalon_slave_register_argument int KK,  //B2_width
	hls_avalon_slave_register_argument int MM,  //B1_width
	hls_avalon_slave_register_argument int NN,  //A_width

	hls_avalon_slave_register_argument MiSistema::ACTIVACIONIN & aa,
	hls_avalon_slave_register_argument MiSistema::PESO1 & bb1,
	hls_avalon_slave_register_argument MiSistema::PESO2 & bb2,
	hls_avalon_slave_register_argument MiSistema::PESO3 & bb3,
	hls_avalon_slave_register_argument MiSistema::ACTIVACIONOUT & cc)
{ 


ihc::launch<MiSistema::producerb1_idea>(&bb1, MM, NN);
ihc::launch<MiSistema::producera_idea>(&aa,NN);
ihc::launch<MiSistema::layer1_SYS_control>(MM,NN);

ihc::launch_always_run<MiSistema::PE_v0>();
ihc::launch_always_run<MiSistema::PE_v1>();
ihc::launch_always_run<MiSistema::PE_v2>();
//ihc::launch_always_run<MiSistema::PE_v3>();
//ihc::launch_always_run<MiSistema::PE_v4>();
//ihc::launch_always_run<MiSistema::PE_v5>();
//ihc::launch_always_run<MiSistema::PE_v6>();
ihc::launch_always_run<MiSistema::PE_v7>();

ihc::launch<MiSistema::producerb2_alt_idea>(&bb2, KK, MM);
ihc::launch<MiSistema::layer2_SYS_control>(KK, MM);

ihc::launch_always_run<MiSistema::PE_h0>();
ihc::launch_always_run<MiSistema::PE_h1>();
ihc::launch_always_run<MiSistema::PE_h2>();
//ihc::launch_always_run<MiSistema::PE_h3>();
//ihc::launch_always_run<MiSistema::PE_h4>();
//ihc::launch_always_run<MiSistema::PE_h5>();
//ihc::launch_always_run<MiSistema::PE_h6>();
ihc::launch_always_run<MiSistema::PE_h7>();

ihc::launch<MiSistema::producerb3_idea>(&bb3, LL, KK);
ihc::launch<MiSistema::layer3_SYS_control>(LL, KK);

ihc::launch_always_run<MiSistema::PE_vf0>();
ihc::launch_always_run<MiSistema::PE_vf1>();
ihc::launch_always_run<MiSistema::PE_vf2>();
//ihc::launch_always_run<MiSistema::PE_vf3>();
//ihc::launch_always_run<MiSistema::PE_vf4>();
//ihc::launch_always_run<MiSistema::PE_vf5>();
//ihc::launch_always_run<MiSistema::PE_vf6>();
ihc::launch_always_run<MiSistema::PE_vf7>();





ihc::launch<MiSistema::consumer>(&cc,LL);




/*
ihc::collect<MiSistema::producerb1_SYS>();
ihc::collect<MiSistema::producera_SYS>();
ihc::collect<MiSistema::layer1_SYS>();

ihc::collect<MiSistema::producerb2_alt>();
ihc::collect<MiSistema::layer2_alt>();

ihc::collect<MiSistema::producerb3>();
ihc::collect<MiSistema::layer3>();
*/
ihc::collect<MiSistema::consumer>();

}



#define TEST_SIZE_L 10
#define TEST_SIZE_K 56
#define TEST_SIZE_M 100
#define TEST_SIZE_N 784
#define SEED 4

int main(void) {

	float A[TEST_SIZE_N];
	float B1[TEST_SIZE_M][TEST_SIZE_N];
	float B1_ALT[TEST_SIZE_N][TEST_SIZE_M];
	float B2[TEST_SIZE_K][TEST_SIZE_M];
	float B2_ALT[TEST_SIZE_M][TEST_SIZE_K];
	float B3[TEST_SIZE_L][TEST_SIZE_K];
	float C[TEST_SIZE_L];

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
			B1_ALT[i][j] = B1[j][i];

		}
	}
	for (int i = 0; i < TEST_SIZE_M; ++i) {
		for (int j = 0; j < TEST_SIZE_K; ++j) {
			B2[j][i] = (getRand() - 0.5) / 2;
			B2_ALT[i][j] = B2[j][i];

		}
	}

	for (int i = 0; i < TEST_SIZE_K; ++i) {
		for (int j = 0; j < TEST_SIZE_L; ++j) {
			B3[j][i] = (getRand() - 0.5) / 2;

		}
	}

	//create de mm_host

	MiSistema::ACTIVACIONIN mm_A(A, TEST_SIZE_N * sizeof(float));
	MiSistema::PESO1 mm_B1(B1, TEST_SIZE_N*TEST_SIZE_M * sizeof(float));
	MiSistema::PESO2 mm_B2(B2_ALT, TEST_SIZE_K*TEST_SIZE_M * sizeof(float));
	MiSistema::PESO3 mm_B3(B3, TEST_SIZE_L*TEST_SIZE_K * sizeof(float));
	MiSistema::ACTIVACIONOUT mm_C(C, TEST_SIZE_L * sizeof(float));


	// Run the component
	MVM_opcion_systolic_ddr(TEST_SIZE_L, TEST_SIZE_K,TEST_SIZE_M, TEST_SIZE_N,  mm_A, mm_B1, mm_B2, mm_B3, mm_C);

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

		/*
		target = tanh(temp);

		obtenido = C[i];
		bool data_okay = fequal(obtenido, target, 0.02);
		passed &= data_okay;
		if (!data_okay) {
			printf("ERROR: C_obtenido[%d] = %f != %f\n", i, obtenido, target);
		   }
		   */
	}
	for (int i = 0; i < TEST_SIZE_K; ++i) {
		float obtenido;
		float target;
		temp = 0;
		for (int j = 0; j < TEST_SIZE_M; ++j) {
			temp = target1[j] * B2[i][j] + temp;
		}
		target2[i] = tanh(temp);
		/*
		target = tanh(temp);

		obtenido = C[i];
		bool data_okay = fequal(obtenido, target, 0.02);
		passed &= data_okay;
		if (!data_okay) {
			printf("ERROR: C_obtenido[%d] = %f != %f\n", i, obtenido, target);
		}
		*/
	}
	
	for (int i = 0; i < TEST_SIZE_L; ++i) {
		float obtenido;
		float target;
		temp = 0;
		for (int j = 0; j < TEST_SIZE_K; ++j) {
			temp = target2[j] * B3[i][j] + temp;
		}
		target = tanh(temp);
		obtenido = C[i];
		bool data_okay = fequal(obtenido, target, 0.01);
		passed &= data_okay;
		if (!data_okay) {
			printf("ERROR: C_obtenido[%d] = %f != %f\n", i, obtenido, target);

		}
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
/*
T_oper tanh_hard(T_oper x)
{
#if tabla==false
	return  (1.0 - ihc::ihc_exp(-2 * x)) / (1.0 + ihc::ihc_exp(-2 * x));
#else
#if T_oper==ihc::bfloat16
	return my_tanhbfloat16(x);
#endif
#if T_oper==ihc::FPhalf
	return my_tanhfp16(x);
#endif
#if T_oper==ihc::FPsingle
	return my_tanhFPsingle(x);
#endif

#endif
}
*/