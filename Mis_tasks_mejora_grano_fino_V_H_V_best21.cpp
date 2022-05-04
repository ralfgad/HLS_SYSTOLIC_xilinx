#include "data_flow_modelo18.h"
#include <hls_math.h>

#ifndef n_entradas
#define n_entradas 1024 // default value max
#endif
#ifndef n_ocultas1
#define n_ocultas1 128 // default value max
#endif

#ifndef n_ocultas2
#define n_ocultas2 64 // default value max
#endif
#ifndef n_salidas
#define n_salidas 16 // default value max
#endif





#define genial_v (n_entradas*n_ocultas1)/BLOCK_SIZE
#define genial_h (n_ocultas1*(n_ocultas2))/BLOCK_SIZE
#define genial (n_ocultas2*(n_salidas))/BLOCK_SIZE

#define semigenial_v 256
#define semigenial_h n_ocultas2
#define semigenial n_salidas


//#define hardware false

#define BUFFER_SIZE 256
typedef union
{
	uint64_t llv;
	float fv[2];
} pareja;



template<class T_oper, class T_com, unsigned LEVELS > class TaskSystem {

public:

	static void producera_SYS(T_com *activacion, int ORIGEN, hls::stream<T_oper> a[LEVELS])
	{
		for (ap_int<10> al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos += LEVELS)
		{

			// #pragma HLS unroll
			for (ap_int<8> i = 0; i < LEVELS; ++i) {
				a[i].write(activacion[al* LEVELS + i]);
			}

		}

	}





	static void producerb1_SYS(T_com * weight, int DESTINO, int ORIGEN, hls::stream<T_oper> b1[LEVELS])
	{
		for (ap_int<10> al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos += LEVELS)
		{
			for (ap_int<8> j = 0; j < DESTINO; ++j)
			{

				for (int i = 0; i < LEVELS; ++i) {
					b1[i].write(weight[j*(ORIGEN)+al * LEVELS + i]);
				}

			}
		}
	}



/*

	static void producerb2_alt_SYS(PESO2 * weight, int DESTINO, int ORIGEN, hls::stream<T_oper> b2[LEVELS])
	{
		for (ap_int<8> al = 0, veamos = 0; veamos < DESTINO; al += 1, veamos += LEVELS)
		{
			for (ap_int<8> j = 0; j < ORIGEN; ++j)
			{

				for (ap_int<8> i = 0; i < LEVELS; ++i) {
					b2[i].write((*weight)[j*(DESTINO)+al * LEVELS + i]);
				}

			}
		}
	}


	static void producerb3_SYS(PESO3 * weight, int DESTINO, int ORIGEN,hls::stream<T_oper> b3[LEVELS])
	{
		for (ap_int<8> al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos += LEVELS)
		{
			for (ap_int<8> j = 0; j < DESTINO; ++j)
			{

				for (ap_int<8> i = 0; i < LEVELS; ++i) {
					b3[i].write((*weight)[j*(ORIGEN)+al * LEVELS + i]);
				}

			}
		}
	}
*/
	static void layer1_SYS_control(int DESTINO, int ORIGEN,
			hls::stream<bool>& controlB1_n_BLOCK_SIZE,hls::stream<bool>& controlB1_ultimo_BLOCK_SIZE,hls::stream<bool>& controlwih1,hls::stream<bool>& termination )
	{

		//short idea = 0;
		//short cuenta_total;
		bool primer_block = true;
		bool ultimo_block = false;
		bool primer_peso_block = false;
		bool terminar=false;
//#pragma loop_coalesce
		for (ap_int<10> al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos +=  LEVELS)

		{

			for (ap_int<8> j = 0; j < DESTINO; ++j)
			{
				//cuenta_total = al * (DESTINO) + j;
				if (j == 0)
					primer_peso_block = true;
				else
					primer_peso_block = false;
				controlwih1.write(primer_peso_block);
				if (al == 0)
					primer_block = true;
				else
					primer_block = false;
				controlB1_n_BLOCK_SIZE.write(primer_block);
				if ((al + 1)*LEVELS >= ORIGEN) {
					ultimo_block = true;
					if (j == DESTINO-1)
						terminar= true;
					else
						terminar = false;
				}
				else
				{
					ultimo_block = false;
					terminar= false;
				}
				controlB1_ultimo_BLOCK_SIZE.write(ultimo_block);
				termination.write(terminar);
			}
		}


	}


	static void PE_v(hls::stream<bool>& controlB1_n_BLOCK_SIZE_in, hls::stream<bool>& controlB1_ultimo_BLOCK_SIZE_in,hls::stream<bool>& controlwih1_in,hls::stream<bool>& termination_in,
			hls::stream<bool>& controlB1_n_BLOCK_SIZE_out,hls::stream<bool>& controlB1_ultimo_BLOCK_SIZE_out,hls::stream<bool>& controlwih1_out,hls::stream<bool>& termination_out ,
			hls::stream<T_oper>& b1_in, hls::stream<T_oper>& a_in, hls::stream<T_oper>& layer1_in, hls::stream<T_oper>& layer1_out,hls::stream<T_oper>& layer1_loop_in,hls::stream<T_oper>& layer1_layer2, ap_int<8> indice
	)

	{
		//float weight[genial_v];//hidden
		T_oper temp=0;
		T_oper temp2;
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		bool terminar=false;
		//short cuenta_total;
		while (terminar!=true)
		{
			
			terminar=termination_in.read();
			idea=controlwih1_in.read();
			//cuenta_total=controlwih1t_0::read();
			n_BLOCK_SIZE =controlB1_n_BLOCK_SIZE_in.read();
			ultimo_BLOCK_SIZE=controlB1_ultimo_BLOCK_SIZE_in.read();


			peso= b1_in.read();
			if (indice==0)
				if (n_BLOCK_SIZE ==true)	{
					operando1 = temp;
				}
				else {
					operando1 = layer1_loop_in.read();
				}
			else {
				operando1=layer1_in.read();
			}

			if (idea == true) {
				operando2 = a_in.read();
			}

			resultado = operando2 * peso + operando1;
			//layer1_out.write(resultado);

			if (ultimo_BLOCK_SIZE == true && indice==LEVELS-1) {
				temp2 = tanh(resultado);
				//layer1_layer2::write(temp2);
				layer1_layer2.write(temp2);
			}

			else {
				layer1_out.write(resultado);
			}

			controlwih1_out.write(idea);
			termination_out.write(terminar);
			controlB1_n_BLOCK_SIZE_out.write(n_BLOCK_SIZE);
			controlB1_ultimo_BLOCK_SIZE_out.write(ultimo_BLOCK_SIZE);
		}


	}

	static void cascaded_PE_v(
			hls::stream<bool,semigenial_v> controlB1_n_BLOCK_SIZE[LEVELS], hls::stream<bool,semigenial_v> controlB1_ultimo_BLOCK_SIZE[LEVELS],hls::stream<bool,semigenial_v> controlwih1[LEVELS],hls::stream<bool,semigenial_v> termination[LEVELS],
			
			hls::stream<T_oper> b1[LEVELS], hls::stream<T_oper> a[LEVELS], hls::stream<T_oper> layer1[LEVELS],hls::stream<T_oper>& layer1_layer2

	) {

	compute_loop:
	    for (int i = 0; i < LEVELS; i++) {
	#pragma HLS UNROLL
	        // total 4 units of adder(). each is compute vector addition
	        // and sending result to immediate next unit using stream
	        // datatype
	        PE_v(controlB1_n_BLOCK_SIZE[i], controlB1_ultimo_BLOCK_SIZE[i], controlwih1[i], termination[i],
	        	 controlB1_n_BLOCK_SIZE[i+1], controlB1_ultimo_BLOCK_SIZE[i+1], controlwih1[i+1], termination[i+1],
	        	b1[i], a[i], layer1[i-1],layer1[i],layer1[LEVELS],layer1_layer2,
					i);
	    }
	}

static	void consumer(hls::stream<T_oper> &ss,T_com *activacion,  ap_int<8> DESTINO)
	{
		for (ap_int<8> j = 0; j < DESTINO; ++j) {
			activacion[j] = ss.read();
		}
	}
};




using MiSistema = TaskSystem<float, float,  BLOCK_SIZE  >;
    void MVM_opcion_sistolica(float *input1, float *input2, float *output, int MM, int NN) {
    #pragma HLS INTERFACE m_axi port = input1 depth = 16 offset = slave bundle = gmem
    #pragma HLS INTERFACE m_axi port = input2 depth = 16*8 offset = slave bundle = gmem
    #pragma HLS INTERFACE m_axi port = output depth = 8 offset = slave bundle = gmem
    #pragma HLS INTERFACE s_axilite port = input1 bundle = control
    #pragma HLS INTERFACE s_axilite port = input2 bundle = control
    #pragma HLS INTERFACE s_axilite port = output bundle = control
    #pragma HLS INTERFACE s_axilite port = MM bundle = control
    #pragma HLS INTERFACE s_axilite port = NN bundle = control
    #pragma HLS INTERFACE s_axilite port = return bundle = control
    #pragma HLS INTERFACE ap_ctrl_chain port = return bundle = control

    	 hls::stream<	float,64> layer1_layer2;
    	//hls::stream<float, ihc::buffer<K>> layer2_layer3;
    	 hls::stream<	float,64> a[BLOCK_SIZE];
    	 hls::stream<	float,64> b1[BLOCK_SIZE];
    	 hls::stream<	bool,semigenial_v> controlB1_ultimo_BLOCK_SIZE[BLOCK_SIZE];
    	 hls::stream<	bool,semigenial_v> controlB1_n_BLOCK_SIZE[BLOCK_SIZE];
    	 hls::stream<	bool,semigenial_v> controlwih1[BLOCK_SIZE];
    	 hls::stream<	bool,semigenial_v> termination[BLOCK_SIZE];
    	 hls::stream<	float,64> layer1[BLOCK_SIZE];
       #pragma HLS dataflow
       #pragma HLS inline recursive
        //one read input unit for data read
    	MiSistema::producera_SYS(input1, NN,a);
    	MiSistema::producerb1_SYS(input2, MM, NN,b1);
    	MiSistema::layer1_SYS_control(MM,NN, controlB1_n_BLOCK_SIZE[0],controlB1_ultimo_BLOCK_SIZE[0],controlwih1[0],termination[0] );
    	MiSistema::cascaded_PE_v(controlB1_n_BLOCK_SIZE,controlB1_ultimo_BLOCK_SIZE,controlwih1,termination,b1,a,layer1, layer1_layer2);
        //one write result unit to write result back to global Memory
    	MiSistema::consumer(layer1_layer2,output,  MM);
    }




