#include "data_flow_example2.h"
#include <hls_math.h>

#define ide1 TEST_SIZE_M*TEST_SIZE_N

float tanh_soft(float x)
{
	return  (1.0 - exp(-2 * x)) / (1.0 + exp(-2 * x));
}

void producer(hls::stream<float> &aa,hls::stream<float> &bb1,float *activacion, float * weight,  int DESTINO, int ORIGEN)
{
	for (int j = 0; j < DESTINO; ++j)
	{
		for (int i = 0; i < ORIGEN; ++i) {
			aa.write(activacion[i]);
			bb1.write(weight[j*ORIGEN + i]);
		}

	}
}


void layer1(hls::stream<float> &aa,hls::stream<float> &bb1,hls::stream<float> &ss, int DESTINO, int ORIGEN)
{



		float current;
		float temp;
		float temp2;
		float a_fp16;
		float b_fp16;

		for (ap_int<8> j = 0; j < DESTINO; ++j) {
			temp=0;
			for (ap_int<8> i = 0; i < ORIGEN; ++i) {
				a_fp16 = aa.read();
				b_fp16 = bb1.read();

				temp = a_fp16 * b_fp16 + temp;
			}
			temp2=tanh_soft(temp);
			ss.write(temp2);
		}



}

void consumer(hls::stream<float> &ss,float *activacion,  int DESTINO)
{
	for (int j = 0; j < DESTINO; ++j) {
		activacion[j] = ss.read();
	}
}




void MVM_opcion7_super_mejorada(float *input1, float *input2, float *output, int MM, int NN) {
#pragma HLS INTERFACE m_axi port = input1 depth = 64 offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = input2 depth = 32*64 offset = slave bundle = gmem
#pragma HLS INTERFACE m_axi port = output depth = 32 offset = slave bundle = gmem
#pragma HLS INTERFACE s_axilite port = input1 bundle = control
#pragma HLS INTERFACE s_axilite port = input2 bundle = control
#pragma HLS INTERFACE s_axilite port = output bundle = control
#pragma HLS INTERFACE s_axilite port = MM bundle = control
#pragma HLS INTERFACE s_axilite port = NN bundle = control
#pragma HLS INTERFACE s_axilite port = return bundle = control

	hls::stream<	float> layer1_layer2;
	//hls::stream<float, ihc::buffer<K>> layer2_layer3;
	hls::stream<	float> a;
	hls::stream<	float> b1;

   #pragma HLS dataflow
    //one read input unit for data read
    producer(a,b1,input1, input2, MM, NN);
    layer1(a,b1,layer1_layer2,MM,NN);
    //one write result unit to write result back to global Memory
    consumer(layer1_layer2,output,  MM);
}

