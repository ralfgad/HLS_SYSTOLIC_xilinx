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

// #define con_dsp

#define fin_t 4

#define genial_v (n_entradas*n_ocultas1)/BLOCK_SIZE
#define genial_h (n_ocultas1*(n_ocultas2))/BLOCK_SIZE
#define genial (n_ocultas2*(n_salidas))/BLOCK_SIZE

#define semigenial_v n_ocultas1
#define semigenial_h n_ocultas2
#define semigenial n_salidas


//#define hardware false

#define BUFFER_SIZE 256
typedef union
{
	uint32_t llv;
	__fp16  fv[2];
} pareja;

ihc::stream<ihc::FPsingle, ihc::buffer<128>> layer1_layer2;

template<unsigned ID, class T_oper, class T_com, unsigned pipe_capacity, unsigned arraySize > class TaskSystem {
private:
	template<unsigned SystemID> class InputPipeID {};
	template<unsigned SystemID> class TaskPipeID {};
	template<unsigned SystemID> class OutputPipeID {};
	template <unsigned idx> struct StructIndex;
	template <unsigned idx> struct VerifyIndex {
		static_assert(idx < arraySize, "Index out of bounds");
		using VerifiedPipe = ihc::pipe<StructIndex<idx>, T_com, pipe_capacity>;
	};
	template <unsigned idx> struct VerifyIndex2 {
		static_assert(idx < arraySize, "Index out of bounds");
		using VerifiedPipe2 = ihc::pipe<StructIndex<idx>, T_oper, pipe_capacity>;
	};

public:
	//typedef T_oper pareja[2];

	using input_pipe = ihc::pipe<class InputPipeID<ID>, T_com, pipe_capacity>;
	using output_pipe = ihc::pipe<class OutputPipeID<ID>, T_com, pipe_capacity>;
	using a = ihc::pipe<class TaskPipeID<0>, T_oper, pipe_capacity>;
	using a_0= ihc::pipe<class TaskPipeID<10>, uint32_t, 1>;
	using a_1 = ihc::pipe<class TaskPipeID<11>, uint32_t, 1>;
	using a_2 = ihc::pipe<class TaskPipeID<12>, uint32_t, 1>;
	using a_3 = ihc::pipe<class TaskPipeID<13>, uint32_t, 1>;
	using a_4 = ihc::pipe<class TaskPipeID<14>, uint32_t, 1>;
	using a_5 = ihc::pipe<class TaskPipeID<15>, uint32_t, 1>;
	using a_6 = ihc::pipe<class TaskPipeID<16>, uint32_t, 1>;
	using a_7 = ihc::pipe<class TaskPipeID<17>, uint32_t, 1>;

	using a2_0 = ihc::pipe<class TaskPipeID<60>, T_oper, 1>;
	using a2_1 = ihc::pipe<class TaskPipeID<61>, T_oper, 1>;
	using a2_2 = ihc::pipe<class TaskPipeID<62>, T_oper, 1>;
	using a2_3 = ihc::pipe<class TaskPipeID<63>, T_oper, 1>;
	using a2_4 = ihc::pipe<class TaskPipeID<64>, T_oper, 1>;
	using a2_5 = ihc::pipe<class TaskPipeID<65>, T_oper, 1>;
	using a2_6 = ihc::pipe<class TaskPipeID<66>, T_oper, 1>;
	using a2_7 = ihc::pipe<class TaskPipeID<67>, T_oper, semigenial_v>;


	using b1_0 = ihc::pipe<class TaskPipeID<20>, uint32_t, semigenial_v>;
	using b1_1 = ihc::pipe<class TaskPipeID<21>, uint32_t, semigenial_v>;
	using b1_2 = ihc::pipe<class TaskPipeID<22>, uint32_t, semigenial_v>;
	using b1_3 = ihc::pipe<class TaskPipeID<23>, uint32_t, semigenial_v>;
	using b1_4 = ihc::pipe<class TaskPipeID<24>, uint32_t, semigenial_v>;
	using b1_5 = ihc::pipe<class TaskPipeID<25>, uint32_t, semigenial_v>;
	using b1_6 = ihc::pipe<class TaskPipeID<26>, uint32_t, semigenial_v>;
	using b1_7 = ihc::pipe<class TaskPipeID<27>, uint32_t, semigenial_v>;

	using b2_0 = ihc::pipe<class TaskPipeID<40>, T_oper, semigenial_h>;
	using b2_1 = ihc::pipe<class TaskPipeID<41>, T_oper, semigenial_h>;
	using b2_2 = ihc::pipe<class TaskPipeID<42>, T_oper, semigenial_h>;
	using b2_3 = ihc::pipe<class TaskPipeID<43>, T_oper, semigenial_h>;
	using b2_4 = ihc::pipe<class TaskPipeID<44>, T_oper, semigenial_h>;
	using b2_5 = ihc::pipe<class TaskPipeID<45>, T_oper, semigenial_h>;
	using b2_6 = ihc::pipe<class TaskPipeID<46>, T_oper, semigenial_h>;
	using b2_7 = ihc::pipe<class TaskPipeID<47>, T_oper, semigenial_h>;

	using b3_0 = ihc::pipe<class TaskPipeID<70>, T_oper, semigenial>;
	using b3_1 = ihc::pipe<class TaskPipeID<71>, T_oper, semigenial>;
	using b3_2 = ihc::pipe<class TaskPipeID<72>, T_oper, semigenial>;
	using b3_3 = ihc::pipe<class TaskPipeID<73>, T_oper, semigenial>;
	using b3_4 = ihc::pipe<class TaskPipeID<74>, T_oper, semigenial>;
	using b3_5 = ihc::pipe<class TaskPipeID<75>, T_oper, semigenial>;
	using b3_6 = ihc::pipe<class TaskPipeID<76>, T_oper, semigenial>;
	using b3_7 = ihc::pipe<class TaskPipeID<77>, T_oper, semigenial>;



	using layer1_0 = ihc::pipe<class TaskPipeID<30>, T_oper, semigenial_v>;
	using layer1_1 = ihc::pipe<class TaskPipeID<31>, T_oper, semigenial_v>;
	using layer1_2 = ihc::pipe<class TaskPipeID<32>, T_oper, semigenial_v>;
	using layer1_3 = ihc::pipe<class TaskPipeID<33>, T_oper, semigenial_v>;
	using layer1_4 = ihc::pipe<class TaskPipeID<34>, T_oper, semigenial_v>;
	using layer1_5 = ihc::pipe<class TaskPipeID<35>, T_oper, semigenial_v>;
	using layer1_6 = ihc::pipe<class TaskPipeID<36>, T_oper, semigenial_v>;
	using layer1_7 = ihc::pipe<class TaskPipeID<37>, T_oper, semigenial_v>;

	using layer2_0 = ihc::pipe<class TaskPipeID<50>, T_oper, semigenial_h>;
	using layer2_1 = ihc::pipe<class TaskPipeID<51>, T_oper, semigenial_h>;
	using layer2_2 = ihc::pipe<class TaskPipeID<52>, T_oper, semigenial_h>;
	using layer2_3 = ihc::pipe<class TaskPipeID<53>, T_oper, semigenial_h>;
	using layer2_4 = ihc::pipe<class TaskPipeID<54>, T_oper, semigenial_h>;
	using layer2_5 = ihc::pipe<class TaskPipeID<55>, T_oper, semigenial_h>;
	using layer2_6 = ihc::pipe<class TaskPipeID<56>, T_oper, semigenial_h>;
	using layer2_7 = ihc::pipe<class TaskPipeID<57>, T_oper, semigenial_h>;

	using layer3_0 = ihc::pipe<class TaskPipeID<80>, T_oper, semigenial>;
	using layer3_1 = ihc::pipe<class TaskPipeID<81>, T_oper, semigenial>;
	using layer3_2 = ihc::pipe<class TaskPipeID<82>, T_oper, semigenial>;
	using layer3_3 = ihc::pipe<class TaskPipeID<83>, T_oper, semigenial>;
	using layer3_4 = ihc::pipe<class TaskPipeID<84>, T_oper, semigenial>;
	using layer3_5 = ihc::pipe<class TaskPipeID<85>, T_oper, semigenial>;
	using layer3_6 = ihc::pipe<class TaskPipeID<86>, T_oper, semigenial>;
	using layer3_7 = ihc::pipe<class TaskPipeID<87>, T_oper, semigenial>;



	using b1 = ihc::pipe<class TaskPipeID<1>, T_com, pipe_capacity>;
	using b2 = ihc::pipe<class TaskPipeID<2>, T_com, pipe_capacity>;
	using b3 = ihc::pipe<class TaskPipeID<3>, T_com, pipe_capacity>;

	//using layer1_layer2 = ihc::pipe<class TaskPipeID<4>, T_oper, pipe_capacity>;


	using layer2_layer3 = ihc::pipe<class TaskPipeID<5>, T_com, pipe_capacity>;
	using sal = ihc::pipe<class TaskPipeID<6>, T_oper, pipe_capacity>;
	using loop1 = ihc::pipe<class TaskPipeID<7>, T_com, pipe_capacity>;
	using loop1_op = ihc::pipe<class TaskPipeID<7>, T_oper, pipe_capacity>;
	using loop2 = ihc::pipe<class TaskPipeID<8>, T_com, semigenial_v>;
	using loop3 = ihc::pipe<class TaskPipeID<9>, T_com, semigenial_v>;

	using controlB1_n_BLOCK_SIZE_0 = ihc::pipe<class TaskPipeID<200>, bool, semigenial_v>;
	using controlB1_ultimo_BLOCK_SIZE_0 = ihc::pipe<class TaskPipeID<201>, bool, semigenial_v>;
//	using controlfin1_0 = ihc::pipe<class TaskPipeID<202>, bool, genial_v>;
	using controlwih1_0 = ihc::pipe<class TaskPipeID<203>, bool, genial_v>;
//	using controlwih1t_0 = ihc::pipe<class TaskPipeID<204>, short, genial_v>;

	using controlB1_n_BLOCK_SIZE_1 = ihc::pipe<class TaskPipeID<210>, bool, semigenial_v>;
	using controlB1_ultimo_BLOCK_SIZE_1 = ihc::pipe<class TaskPipeID<211>, bool, semigenial_v>;
//	using controlfin1_1 = ihc::pipe<class TaskPipeID<212>, bool, genial_v>;
	using controlwih1_1 = ihc::pipe<class TaskPipeID<213>, bool, semigenial_v>;
//	using controlwih1t_1 = ihc::pipe<class TaskPipeID<214>, short, genial_v>;

	using controlB1_n_BLOCK_SIZE_2 = ihc::pipe<class TaskPipeID<220>, bool, semigenial_v>;
	using controlB1_ultimo_BLOCK_SIZE_2 = ihc::pipe<class TaskPipeID<221>, bool, semigenial_v>;
//	using controlfin1_2 = ihc::pipe<class TaskPipeID<222>, bool, genial_v>;
	using controlwih1_2 = ihc::pipe<class TaskPipeID<223>, bool, semigenial_v>;
//	using controlwih1t_2 = ihc::pipe<class TaskPipeID<224>, short, genial_v>;

	using controlB1_n_BLOCK_SIZE_3 = ihc::pipe<class TaskPipeID<230>, bool, semigenial_v>;
	using controlB1_ultimo_BLOCK_SIZE_3 = ihc::pipe<class TaskPipeID<231>, bool, semigenial_v>;
//	using controlfin1_3 = ihc::pipe<class TaskPipeID<232>, bool, genial_v>;
	using controlwih1_3 = ihc::pipe<class TaskPipeID<233>, bool, semigenial_v>;
//	using controlwih1t_3 = ihc::pipe<class TaskPipeID<234>, short, genial_v>;

	using controlB1_n_BLOCK_SIZE_4 = ihc::pipe<class TaskPipeID<240>, bool, semigenial_v>;
	using controlB1_ultimo_BLOCK_SIZE_4 = ihc::pipe<class TaskPipeID<241>, bool, semigenial_v>;
//	using controlfin1_4 = ihc::pipe<class TaskPipeID<242>, bool, genial_v>;
	using controlwih1_4 = ihc::pipe<class TaskPipeID<243>, bool, semigenial_v>;
//	using controlwih1t_4 = ihc::pipe<class TaskPipeID<244>, short, genial_v>;

	using controlB1_n_BLOCK_SIZE_5 = ihc::pipe<class TaskPipeID<250>, bool, semigenial_v>;
	using controlB1_ultimo_BLOCK_SIZE_5 = ihc::pipe<class TaskPipeID<251>, bool, semigenial_v>;
//	using controlfin1_5 = ihc::pipe<class TaskPipeID<252>, bool, genial_v>;
	using controlwih1_5 = ihc::pipe<class TaskPipeID<253>, bool, semigenial_v>;
//	using controlwih1t_5 = ihc::pipe<class TaskPipeID<254>, short, genial_v>;

	using controlB1_n_BLOCK_SIZE_6 = ihc::pipe<class TaskPipeID<260>, bool, semigenial_v>;
	using controlB1_ultimo_BLOCK_SIZE_6 = ihc::pipe<class TaskPipeID<261>, bool, semigenial_v>;
//	using controlfin1_6 = ihc::pipe<class TaskPipeID<262>, bool, genial_v>;
	using controlwih1_6 = ihc::pipe<class TaskPipeID<263>, bool, semigenial_v>;
//	using controlwih1t_6 = ihc::pipe<class TaskPipeID<264>, short, genial_v>;

	using controlB1_n_BLOCK_SIZE_7 = ihc::pipe<class TaskPipeID<270>, bool, semigenial_v>;
	using controlB1_ultimo_BLOCK_SIZE_7 = ihc::pipe<class TaskPipeID<271>, bool, semigenial_v>;
//	using controlfin1_7 = ihc::pipe<class TaskPipeID<272>, bool, genial_v>;
	using controlwih1_7 = ihc::pipe<class TaskPipeID<273>, bool, semigenial_v>;
//	using controlwih1t_7 = ihc::pipe<class TaskPipeID<274>, short, genial_v>;

	//empieza la segunda capa de pesos
	using controlB2_n_BLOCK_SIZE_0 = ihc::pipe<class TaskPipeID<400>, bool, semigenial_h>;
	using controlB2_ultimo_BLOCK_SIZE_0 = ihc::pipe<class TaskPipeID<401>, bool, semigenial_h>;
	using controlfin2_0 = ihc::pipe<class TaskPipeID<402>, bool, semigenial_h>;
#ifdef con_dsp
	using controlwih2_0 = ihc::pipe<class TaskPipeID<403>, bool, semigenial_h>;
#endif
	//	using controlwih1t_0 = ihc::pipe<class TaskPipeID<204>, short, genial_v>;

	using controlB2_n_BLOCK_SIZE_1 = ihc::pipe<class TaskPipeID<410>, bool, semigenial_h>;
	using controlB2_ultimo_BLOCK_SIZE_1 = ihc::pipe<class TaskPipeID<411>, bool, semigenial_h>;
	using controlfin2_1 = ihc::pipe<class TaskPipeID<412>, bool, semigenial_h>;
#ifdef con_dsp
	using controlwih2_1 = ihc::pipe<class TaskPipeID<413>, bool, semigenial_h>;
#endif
	//	using controlwih1t_1 = ihc::pipe<class TaskPipeID<214>, short, genial_v>;

	using controlB2_n_BLOCK_SIZE_2 = ihc::pipe<class TaskPipeID<420>, bool, semigenial_h>;
	using controlB2_ultimo_BLOCK_SIZE_2 = ihc::pipe<class TaskPipeID<421>, bool, semigenial_h>;
	using controlfin2_2 = ihc::pipe<class TaskPipeID<422>, bool, semigenial_h>;
#ifdef con_dsp
	using controlwih2_2 = ihc::pipe<class TaskPipeID<423>, bool, semigenial_h>;
#endif
	//	using controlwih1t_2 = ihc::pipe<class TaskPipeID<224>, short, genial_v>;

	using controlB2_n_BLOCK_SIZE_3 = ihc::pipe<class TaskPipeID<430>, bool, semigenial_h>;
	using controlB2_ultimo_BLOCK_SIZE_3 = ihc::pipe<class TaskPipeID<431>, bool, semigenial_h>;
	using controlfin2_3 = ihc::pipe<class TaskPipeID<232>, bool, semigenial_h>;
#ifdef con_dsp
	using controlwih2_3 = ihc::pipe<class TaskPipeID<433>, bool, semigenial_h>;
#endif
	//	using controlwih1t_3 = ihc::pipe<class TaskPipeID<234>, short, genial_v>;

	using controlB2_n_BLOCK_SIZE_4 = ihc::pipe<class TaskPipeID<440>, bool, semigenial_h>;
	using controlB2_ultimo_BLOCK_SIZE_4 = ihc::pipe<class TaskPipeID<441>, bool, semigenial_h>;
	using controlfin2_4 = ihc::pipe<class TaskPipeID<442>, bool, semigenial_h>;
#ifdef con_dsp
	using controlwih2_4 = ihc::pipe<class TaskPipeID<443>, bool, semigenial_h>;
#endif
	//	using controlwih1t_4 = ihc::pipe<class TaskPipeID<244>, short, genial_v>;

	using controlB2_n_BLOCK_SIZE_5 = ihc::pipe<class TaskPipeID<450>, bool, semigenial_h>;
	using controlB2_ultimo_BLOCK_SIZE_5 = ihc::pipe<class TaskPipeID<451>, bool, semigenial_h>;
	using controlfin2_5 = ihc::pipe<class TaskPipeID<452>, bool, semigenial_h>;
#ifdef con_dsp
	using controlwih2_5 = ihc::pipe<class TaskPipeID<453>, bool, semigenial_h>;
#endif
	//	using controlwih1t_5 = ihc::pipe<class TaskPipeID<254>, short, genial_v>;

	using controlB2_n_BLOCK_SIZE_6 = ihc::pipe<class TaskPipeID<460>, bool, semigenial_h>;
	using controlB2_ultimo_BLOCK_SIZE_6 = ihc::pipe<class TaskPipeID<461>, bool, semigenial_h>;
	using controlfin2_6 = ihc::pipe<class TaskPipeID<462>, bool, semigenial_h>;
#ifdef con_dsp
	using controlwih2_6 = ihc::pipe<class TaskPipeID<463>, bool, semigenial_h>;
#endif
	//	using controlwih1t_6 = ihc::pipe<class TaskPipeID<264>, short, genial_v>;

	using controlB2_n_BLOCK_SIZE_7 = ihc::pipe<class TaskPipeID<470>, bool, semigenial_h>;
	using controlB2_ultimo_BLOCK_SIZE_7 = ihc::pipe<class TaskPipeID<471>, bool, semigenial_h>;
	using controlfin2_7 = ihc::pipe<class TaskPipeID<472>, bool, semigenial_h>;
#ifdef con_dsp
	using controlwih2_7 = ihc::pipe<class TaskPipeID<473>, bool, semigenial_h>;
#endif
	//	using controlwih1t_7 = ihc::pipe<class TaskPipeID<274>, short, genial_v>;

	//tercera capa de pesos
	using controlB3_n_BLOCK_SIZE_0 = ihc::pipe<class TaskPipeID<600>, bool, semigenial>;
	using controlB3_ultimo_BLOCK_SIZE_0 = ihc::pipe<class TaskPipeID<601>, bool, semigenial>;
	//	using controlfin1_0 = ihc::pipe<class TaskPipeID<202>, bool, genial_v>;
	using controlwih3_0 = ihc::pipe<class TaskPipeID<603>, bool, semigenial>;
	//	using controlwih1t_0 = ihc::pipe<class TaskPipeID<204>, short, genial_v>;

	using controlB3_n_BLOCK_SIZE_1 = ihc::pipe<class TaskPipeID<610>, bool, semigenial>;
	using controlB3_ultimo_BLOCK_SIZE_1 = ihc::pipe<class TaskPipeID<611>, bool, semigenial>;
	//	using controlfin1_1 = ihc::pipe<class TaskPipeID<212>, bool, genial_v>;
	using controlwih3_1 = ihc::pipe<class TaskPipeID<613>, bool, semigenial>;
	//	using controlwih1t_1 = ihc::pipe<class TaskPipeID<214>, short, genial_v>;

	using controlB3_n_BLOCK_SIZE_2 = ihc::pipe<class TaskPipeID<620>, bool, semigenial>;
	using controlB3_ultimo_BLOCK_SIZE_2 = ihc::pipe<class TaskPipeID<621>, bool, semigenial>;
	//	using controlfin1_2 = ihc::pipe<class TaskPipeID<222>, bool, genial_v>;
	using controlwih3_2 = ihc::pipe<class TaskPipeID<623>, bool, semigenial>;
	//	using controlwih1t_2 = ihc::pipe<class TaskPipeID<224>, short, genial_v>;

	using controlB3_n_BLOCK_SIZE_3 = ihc::pipe<class TaskPipeID<630>, bool, semigenial>;
	using controlB3_ultimo_BLOCK_SIZE_3 = ihc::pipe<class TaskPipeID<631>, bool, semigenial>;
	//	using controlfin1_3 = ihc::pipe<class TaskPipeID<232>, bool, genial_v>;
	using controlwih3_3 = ihc::pipe<class TaskPipeID<633>, bool, semigenial>;
	//	using controlwih1t_3 = ihc::pipe<class TaskPipeID<234>, short, genial_v>;

	using controlB3_n_BLOCK_SIZE_4 = ihc::pipe<class TaskPipeID<640>, bool, semigenial>;
	using controlB3_ultimo_BLOCK_SIZE_4 = ihc::pipe<class TaskPipeID<641>, bool, semigenial>;
	//	using controlfin1_4 = ihc::pipe<class TaskPipeID<242>, bool, genial_v>;
	using controlwih3_4 = ihc::pipe<class TaskPipeID<643>, bool, semigenial>;
	//	using controlwih1t_4 = ihc::pipe<class TaskPipeID<244>, short, genial_v>;

	using controlB3_n_BLOCK_SIZE_5 = ihc::pipe<class TaskPipeID<650>, bool, genial>;
	using controlB3_ultimo_BLOCK_SIZE_5 = ihc::pipe<class TaskPipeID<651>, bool, genial>;
	//	using controlfin1_5 = ihc::pipe<class TaskPipeID<252>, bool, genial_v>;
	using controlwih3_5 = ihc::pipe<class TaskPipeID<653>, bool, genial>;
	//	using controlwih1t_5 = ihc::pipe<class TaskPipeID<254>, short, genial_v>;

	using controlB3_n_BLOCK_SIZE_6 = ihc::pipe<class TaskPipeID<660>, bool, semigenial>;
	using controlB3_ultimo_BLOCK_SIZE_6 = ihc::pipe<class TaskPipeID<661>, bool, semigenial>;
	//	using controlfin1_6 = ihc::pipe<class TaskPipeID<262>, bool, genial_v>;
	using controlwih3_6 = ihc::pipe<class TaskPipeID<663>, bool, semigenial>;
	//	using controlwih1t_6 = ihc::pipe<class TaskPipeID<264>, short, genial_v>;

	using controlB3_n_BLOCK_SIZE_7 = ihc::pipe<class TaskPipeID<670>, bool, semigenial>;
	using controlB3_ultimo_BLOCK_SIZE_7 = ihc::pipe<class TaskPipeID<671>, bool, semigenial>;
	//	using controlfin1_7 = ihc::pipe<class TaskPipeID<272>, bool, genial_v>;
	using controlwih3_7 = ihc::pipe<class TaskPipeID<673>, bool, semigenial>;
	//	using controlwih1t_7 = ihc::pipe<class TaskPipeID<274>, short, genial_v>;


	template <unsigned idx>
	using a_array = typename VerifyIndex<idx>::VerifiedPipe;
	template <unsigned idx>
	using b1_array = typename VerifyIndex<idx>::VerifiedPipe;
	template <unsigned idx>
	using layer1_array = typename VerifyIndex2<idx>::VerifiedPipe2;



	typedef ihc::mm_host<T_com, ihc::aspace<1>, ihc::dwidth<256>, ihc::awidth<32> > ACTIVACIONIN;
	typedef ihc::mm_host<T_com, ihc::aspace<2>, ihc::dwidth<256>, ihc::awidth<32>, ihc::waitrequest<true>, ihc::latency<0> > PESO1;
	typedef ihc::mm_host<T_com, ihc::aspace<4>, ihc::dwidth<256>, ihc::awidth<32>, ihc::waitrequest<true>, ihc::latency<0> > PESO2;
	typedef ihc::mm_host<T_com, ihc::aspace<5>, ihc::dwidth<256>, ihc::awidth<32>, ihc::waitrequest<true>, ihc::latency<0> > PESO3;
	typedef ihc::mm_host<T_com, ihc::aspace<3>, ihc::dwidth<32>, ihc::awidth<32> > ACTIVACIONOUT;


	static void producera(ACTIVACIONIN *activacion, int ORIGEN)

	{
		for (int i = 0; i < ORIGEN; ++i) {
			a::write((*activacion)[i]);
			//a.write((*activacion)[i]);
		}

	}

	static void producera_SYS(ACTIVACIONIN *activacion, int ORIGEN)
	{
		for (size_t al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos += BLOCK_SIZE)
		{

			a_0::write((*activacion)[al* BLOCK_SIZE + 0]);
			a_1::write((*activacion)[al* BLOCK_SIZE + 1]);
			a_2::write((*activacion)[al* BLOCK_SIZE + 2]);
			a_3::write((*activacion)[al* BLOCK_SIZE + 3]);
			a_4::write((*activacion)[al* BLOCK_SIZE + 4]);
			a_5::write((*activacion)[al* BLOCK_SIZE + 5]);
			a_6::write((*activacion)[al* BLOCK_SIZE + 6]);
			a_7::write((*activacion)[al* BLOCK_SIZE + 7]);
			/*
			#pragma unroll
			for (int i = 0; i < BLOCK_SIZE; ++i) {
				a_array<i>::write((*activacion)[al* BLOCK_SIZE + i]);
				//a.write((*activacion)[i]);
			}
			*/
		}

	}
	static void producera_idea(ACTIVACIONIN *activacion, int ORIGEN)
	{
		float temp[BLOCK_SIZE];
		for (uint10 al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos += BLOCK_SIZE)
		{
#pragma unroll
			for (uint4 k = 0; k < BLOCK_SIZE; k++)
			{
				temp[k] = (*activacion)[al * BLOCK_SIZE + k];
			}

			a_0::write(temp[0]);
			a_1::write(temp[1]);
			a_2::write(temp[2]);
			a_3::write(temp[3]);
			a_4::write(temp[4]);
			a_5::write(temp[5]);
			a_6::write(temp[6]);
			a_7::write(temp[7]);
			/*
			#pragma unroll
			for (int i = 0; i < BLOCK_SIZE; ++i) {
				a_array<i>::write((*activacion)[al* BLOCK_SIZE + i]);
				//a.write((*activacion)[i]);
			}
			*/
		}

	}

	static void producera_idea2_par(ACTIVACIONIN *activacion, int ORIGEN)
	{
		pareja temp[BLOCK_SIZE];
		float temp1[BLOCK_SIZE];
		for (uint10 al = 0, veamos = 0; veamos < ORIGEN; al += 2, veamos += 2 * BLOCK_SIZE)
		{
#pragma unroll
			for (uint4 k = 0; k < BLOCK_SIZE; k++)
			{
				temp[k].fv[0] = (*activacion)[al * BLOCK_SIZE + k];
			}
#pragma unroll
			for (uint4 k = 0; k < BLOCK_SIZE; k++)
			{
				temp[k].fv[1] = (*activacion)[al * BLOCK_SIZE + BLOCK_SIZE + k];
			}
			a_0::write(temp[0].llv);
			a_1::write(temp[1].llv);
			a_2::write(temp[2].llv);
			a_3::write(temp[3].llv);
			a_4::write(temp[4].llv);
			a_5::write(temp[5].llv);
			a_6::write(temp[6].llv);
			a_7::write(temp[7].llv);

		}
	}
	static void producerb1(PESO1 * weight, int DESTINO, int ORIGEN)
	{
		for (int j = 0; j < DESTINO; ++j)
		{
			for (int i = 0; i < ORIGEN; ++i) {
				b1::write((*weight)[j*ORIGEN + i]);
			}

		}
	}

	static void producerb1_idea(PESO1 * weight, int DESTINO, int ORIGEN)
	{
		float temp[BLOCK_SIZE];
#pragma loop_coalesce
		for (uint10 al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos += BLOCK_SIZE)
		{
			for (uint8 j = 0; j < DESTINO; ++j)
			{
#pragma unroll
				for (uint4 k = 0; k < BLOCK_SIZE; k++)
				{
					temp[k] = (*weight)[j*ORIGEN + al * BLOCK_SIZE + k];
				}
				b1_0::write(temp[0]);
				b1_1::write(temp[1]);
				b1_2::write(temp[2]);
				b1_3::write(temp[3]);
				b1_4::write(temp[4]);
				b1_5::write(temp[5]);
				b1_6::write(temp[6]);
				b1_7::write(temp[7]);
			}

		}
	}
	static void producerb1_SYS(PESO1 * weight, int DESTINO, int ORIGEN)
	{
		for (size_t al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos += BLOCK_SIZE)
		{
			for (int j = 0; j < DESTINO; ++j)
			{
				b1_0::write((*weight)[j*ORIGEN + al * BLOCK_SIZE+ 0]);
				b1_1::write((*weight)[j*ORIGEN + al * BLOCK_SIZE+ 1]);
				b1_2::write((*weight)[j*ORIGEN + al * BLOCK_SIZE+ 2]);
				b1_3::write((*weight)[j*ORIGEN + al * BLOCK_SIZE+ 3]);
				b1_4::write((*weight)[j*ORIGEN + al * BLOCK_SIZE+ 4]);
				b1_5::write((*weight)[j*ORIGEN + al * BLOCK_SIZE+ 5]);
				b1_6::write((*weight)[j*ORIGEN + al * BLOCK_SIZE+ 6]);
				b1_7::write((*weight)[j*ORIGEN + al * BLOCK_SIZE+ 7]);
				/*
#pragma unroll
				for (int i = 0; i < BLOCK_SIZE; ++i) {
					b1_array<i>::write((*weight)[j*(ORIGEN)+al * BLOCK_SIZE + i]);
				}
				*/
			}
		}
	}
	static void producerb1_idea2_par(PESO1 * weight, int DESTINO, int ORIGEN)
	{
		pareja temp[BLOCK_SIZE];
	//	float temp1[BLOCK_SIZE];
#pragma loop_coalesce
		for (uint10 al = 0, veamos = 0; veamos < ORIGEN; al += 2, veamos += 2 * BLOCK_SIZE)
		{
			for (uint8 j = 0; j < DESTINO; ++j)
			{
#pragma unroll
				for (uint4 k = 0; k < BLOCK_SIZE; k++)
				{
					temp[k].fv[0] = (*weight)[j*ORIGEN + al * BLOCK_SIZE + k];
				}
#pragma unroll
				for (uint4 k = 0; k < BLOCK_SIZE; k++)
				{
					temp[k].fv[1] = (*weight)[j*ORIGEN + al * BLOCK_SIZE + BLOCK_SIZE + k];
				}
				b1_0::write(temp[0].llv);
				b1_1::write(temp[1].llv);
				b1_2::write(temp[2].llv);
				b1_3::write(temp[3].llv);
				b1_4::write(temp[4].llv);
				b1_5::write(temp[5].llv);
				b1_6::write(temp[6].llv);
				b1_7::write(temp[7].llv);


			}

		}
	}
	static void producerb1_alt(PESO1 * weight, int DESTINO, int ORIGEN)
	{
		for (int j = 0; j < ORIGEN; ++j)
		{
			for (int i = 0; i < DESTINO; ++i) {
				b1::write((*weight)[i*ORIGEN + j]);
			}

		}
	}
	static void producerb2(PESO2 * weight, int DESTINO, int ORIGEN)
	{
		for (int j = 0; j < DESTINO; ++j)
		{
			for (int i = 0; i < ORIGEN; ++i) {
				b2::write((*weight)[j*ORIGEN + i]);
			}

		}
	}
	static void producerb2_SYS(PESO2 * weight, int DESTINO, int ORIGEN)
	{
		for (size_t al = 0, veamos = 0; veamos < DESTINO; al += 1, veamos += BLOCK_SIZE)
		{
			for (int j = 0; j < ORIGEN; ++j)
			{
				b2_0::write((*weight)[(al * BLOCK_SIZE + 0)*ORIGEN + j]);
				b2_1::write((*weight)[(al * BLOCK_SIZE + 1)*ORIGEN + j]);
				b2_2::write((*weight)[(al * BLOCK_SIZE + 2)*ORIGEN + j]);
				b2_3::write((*weight)[(al * BLOCK_SIZE + 3)*ORIGEN + j]);
				b2_4::write((*weight)[(al * BLOCK_SIZE + 4)*ORIGEN + j]);
				b2_5::write((*weight)[(al * BLOCK_SIZE + 5)*ORIGEN + j]);
				b2_6::write((*weight)[(al * BLOCK_SIZE + 6)*ORIGEN + j]);
				b2_7::write((*weight)[(al * BLOCK_SIZE + 7)*ORIGEN + j]);
				/*
#pragma unroll
				for (int i = 0; i < BLOCK_SIZE; ++i) {
					b1_array<i>::write((*weight)[j*(ORIGEN)+al * BLOCK_SIZE + i]);
				}
				*/
			}
		}
	}


	static void producerb2_alt_SYS(PESO2 * weight, int DESTINO, int ORIGEN)
	{
		for (size_t al = 0, veamos = 0; veamos < DESTINO; al += 1, veamos += BLOCK_SIZE)
		{
			for (int j = 0; j < ORIGEN; ++j)
			{
				b2_0::write((*weight)[j*DESTINO + al * BLOCK_SIZE + 0]);
				b2_1::write((*weight)[j*DESTINO + al * BLOCK_SIZE + 1]);
				b2_2::write((*weight)[j*DESTINO + al * BLOCK_SIZE + 2]);
				b2_3::write((*weight)[j*DESTINO + al * BLOCK_SIZE + 3]);
				b2_4::write((*weight)[j*DESTINO + al * BLOCK_SIZE + 4]);
				b2_5::write((*weight)[j*DESTINO + al * BLOCK_SIZE + 5]);
				b2_6::write((*weight)[j*DESTINO + al * BLOCK_SIZE + 6]);
				b2_7::write((*weight)[j*DESTINO + al * BLOCK_SIZE + 7]);
				/*
#pragma unroll
				for (int i = 0; i < BLOCK_SIZE; ++i) {
					b1_array<i>::write((*weight)[j*(ORIGEN)+al * BLOCK_SIZE + i]);
				}
				*/
			}
		}
	}

	static void producerb2_alt_idea(PESO2 * weight, int DESTINO, int ORIGEN)
	{
		float temp[BLOCK_SIZE];
#pragma loop_coalesce
		for (uint8 al = 0, veamos = 0; veamos < DESTINO; al += 1, veamos += BLOCK_SIZE)
		{
			for (uint8 j = 0; j < ORIGEN; ++j)
			{
#pragma unroll
				for (uint4 k = 0; k < BLOCK_SIZE; k++)
				{
					temp[k] = (*weight)[j*DESTINO + al * BLOCK_SIZE + k];
				}
				b2_0::write(temp[0]);
				b2_1::write(temp[1]);
				b2_2::write(temp[2]);
				b2_3::write(temp[3]);
				b2_4::write(temp[4]);
				b2_5::write(temp[5]);
				b2_6::write(temp[6]);
				b2_7::write(temp[7]);
				/*
#pragma unroll
				for (int i = 0; i < BLOCK_SIZE; ++i) {
					b1_array<i>::write((*weight)[j*(ORIGEN)+al * BLOCK_SIZE + i]);
				}
				*/
			}
		}
	}


	static void producerb2_alt(PESO2 * weight, int DESTINO, int ORIGEN)
	{
		for (int j = 0; j < ORIGEN; ++j)
		{
			for (int i = 0; i < DESTINO; ++i) {
				b2::write((*weight)[i*ORIGEN + j]);
			}

		}
	}
	static void producerb3(PESO3 * weight, int DESTINO, int ORIGEN)
	{
		for (int j = 0; j < DESTINO; ++j)
		{
			for (int i = 0; i < ORIGEN; ++i) {
				b3::write((*weight)[j*ORIGEN + i]);
			}

		}
	}
	static void producerb3_alt(PESO3 * weight, int DESTINO, int ORIGEN)
	{
		for (int j = 0; j < ORIGEN; ++j)
		{
			for (int i = 0; i < DESTINO; ++i) {
				b3::write((*weight)[i*ORIGEN + j]);
			}

		}
	}
	static void producerb3_SYS(PESO3 * weight, int DESTINO, int ORIGEN)
	{
		for (size_t al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos += BLOCK_SIZE)
		{
			for (int j = 0; j < DESTINO; ++j)
			{
				b3_0::write((*weight)[j*ORIGEN + al * BLOCK_SIZE + 0]);
				b3_1::write((*weight)[j*ORIGEN + al * BLOCK_SIZE + 1]);
				b3_2::write((*weight)[j*ORIGEN + al * BLOCK_SIZE + 2]);
				b3_3::write((*weight)[j*ORIGEN + al * BLOCK_SIZE + 3]);
				b3_4::write((*weight)[j*ORIGEN + al * BLOCK_SIZE + 4]);
				b3_5::write((*weight)[j*ORIGEN + al * BLOCK_SIZE + 5]);
				b3_6::write((*weight)[j*ORIGEN + al * BLOCK_SIZE + 6]);
				b3_7::write((*weight)[j*ORIGEN + al * BLOCK_SIZE + 7]);
				/*
#pragma unroll
				for (int i = 0; i < BLOCK_SIZE; ++i) {
					b1_array<i>::write((*weight)[j*(ORIGEN)+al * BLOCK_SIZE + i]);
				}
				*/
			}
		}
	}
	static void producerb3_idea(PESO3 * weight, int DESTINO, int ORIGEN)
	{
		float temp[BLOCK_SIZE];
#pragma loop_coalesce
		for (uint8 al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos += BLOCK_SIZE)
		{
			for (uint4 j = 0; j < DESTINO; ++j)
			{
#pragma unroll
				for (uint4 k = 0; k < BLOCK_SIZE; k++)
				{
					temp[k] = (*weight)[j*ORIGEN + al * BLOCK_SIZE + k];
				}
				b3_0::write(temp[0]);
				b3_1::write(temp[1]);
				b3_2::write(temp[2]);
				b3_3::write(temp[3]);
				b3_4::write(temp[4]);
				b3_5::write(temp[5]);
				b3_6::write(temp[6]);
				b3_7::write(temp[7]);
				/*
#pragma unroll
				for (int i = 0; i < BLOCK_SIZE; ++i) {
					b1_array<i>::write((*weight)[j*(ORIGEN)+al * BLOCK_SIZE + i]);
				}
				*/
			}
		}
	}
	static void layer1(int DESTINO, int ORIGEN)
	{

		T_oper temp;
		T_com temp2;
		T_oper a_fp16;
		T_oper b_fp16;

		/*
		float temp, temp2;
		float a_fp16;
		float b_fp16;
		*/
		float tanh_soft(float x);
		for (int j = 0; j < DESTINO; ++j) {
			temp = 0;
#pragma max_interleaving 0
			for (int i = 0; i < ORIGEN; ++i) {
				if (j == 0)
					a_fp16 = a::read();
				else
					a_fp16 = loop1::read();
				b_fp16 = b1::read();
				temp = a_fp16 * b_fp16 + temp;
				if (j != DESTINO - 1)
					loop1::write(a_fp16);
			}
			temp2 = my_tanhfp162fd(temp);
			layer1_layer2::write(temp2);
		}
	}
	static void PE_v0()
	{
		//float weight[genial_v];//hidden
		T_oper temp=0;
		pareja peso;
		T_oper operando1;
		pareja operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{
			

			idea=controlwih1_0::read();
			//cuenta_total=controlwih1t_0::read();
			n_BLOCK_SIZE =controlB1_n_BLOCK_SIZE_0::read();
			ultimo_BLOCK_SIZE=controlB1_ultimo_BLOCK_SIZE_0::read();


			peso.llv= b1_0::read();
			if (n_BLOCK_SIZE ==false)	{
				operando1 = layer1_7::read();
			}
			else {
				operando1 = temp;
			}

			if (idea == true) {
				operando2.llv = a_0::read();
			}

#ifdef con_dsp

			resultado = my_ffplusf_2_cyv_half(operando1, peso.fv[0], operando2.fv[0], peso.fv[1], operando2.fv[1]);


#else
			resultado = operando2.fv[0] * peso.fv[0] + operando2.fv[1] * peso.fv[1] + operando1;
#endif
			layer1_0::write(resultado);

			controlwih1_1::write(idea);
			//controlwih1t_1::write(cuenta_total);
			controlB1_n_BLOCK_SIZE_1::write(n_BLOCK_SIZE);
			controlB1_ultimo_BLOCK_SIZE_1::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_v1()
	{
		//float weight[genial_v];//hidden
		pareja peso;
		T_oper operando1;
		pareja operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih1_1::read();
			//cuenta_total = controlwih1t_1::read();
			n_BLOCK_SIZE = controlB1_n_BLOCK_SIZE_1::read();
			ultimo_BLOCK_SIZE = controlB1_ultimo_BLOCK_SIZE_1::read();


			peso.llv = b1_1::read();
			operando1 = layer1_0::read();
			if (idea == true) {
				operando2.llv = a_1::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_2_cyv_half(operando1, peso.fv[0], operando2.fv[0], peso.fv[1], operando2.fv[1]);

#else
			resultado = operando2.fv[0] * peso.fv[0] + operando2.fv[1] * peso.fv[1] + operando1;
#endif
			layer1_1::write(resultado);

			controlwih1_2::write(idea);
			//controlwih1t_2::write(cuenta_total);
			controlB1_n_BLOCK_SIZE_2::write(n_BLOCK_SIZE);
			controlB1_ultimo_BLOCK_SIZE_2::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_v2()
	{
		//float weight[genial_v];//hidden
		pareja peso;
		T_oper operando1;
		pareja operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih1_2::read();
			//cuenta_total = controlwih1t_2::read();
			n_BLOCK_SIZE = controlB1_n_BLOCK_SIZE_2::read();
			ultimo_BLOCK_SIZE = controlB1_ultimo_BLOCK_SIZE_2::read();


			peso.llv = b1_2::read();
			operando1 = layer1_1::read();
			if (idea == true) {
				operando2.llv = a_2::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_2_cyv_half(operando1, peso.fv[0], operando2.fv[0], peso.fv[1], operando2.fv[1]);

#else
			resultado = operando2.fv[0] * peso.fv[0] + operando2.fv[1] * peso.fv[1] + operando1;
#endif
			layer1_2::write(resultado);

			controlwih1_3::write(idea);
			//controlwih1t_3::write(cuenta_total);
			controlB1_n_BLOCK_SIZE_3::write(n_BLOCK_SIZE);
			controlB1_ultimo_BLOCK_SIZE_3::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_v3()
	{
		//float weight[genial_v];//hidden
		pareja peso;
		T_oper operando1;
		pareja operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih1_3::read();
			//cuenta_total = controlwih1t_3::read();
			n_BLOCK_SIZE = controlB1_n_BLOCK_SIZE_3::read();
			ultimo_BLOCK_SIZE = controlB1_ultimo_BLOCK_SIZE_3::read();


			peso.llv = b1_3::read();
			operando1 = layer1_2::read();
			if (idea == true) {
				operando2.llv = a_3::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_2_cyv_half(operando1, peso.fv[0], operando2.fv[0], peso.fv[1], operando2.fv[1]);

#else
			resultado = operando2.fv[0] * peso.fv[0] + operando2.fv[1] * peso.fv[1] + operando1;
#endif
			layer1_3::write(resultado);

			controlwih1_4::write(idea);
			//controlwih1t_4::write(cuenta_total);
			controlB1_n_BLOCK_SIZE_4::write(n_BLOCK_SIZE);
			controlB1_ultimo_BLOCK_SIZE_4::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_v4()
	{
		//float weight[genial_v];//hidden
		pareja peso;
		T_oper operando1;
		pareja operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih1_4::read();
			//cuenta_total = controlwih1t_4::read();
			n_BLOCK_SIZE = controlB1_n_BLOCK_SIZE_4::read();
			ultimo_BLOCK_SIZE = controlB1_ultimo_BLOCK_SIZE_4::read();


			peso.llv = b1_4::read();
			operando1 = layer1_3::read();
			if (idea == true) {
				operando2.llv = a_4::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_2_cyv_half(operando1, peso.fv[0], operando2.fv[0], peso.fv[1], operando2.fv[1]);

#else
			resultado = operando2.fv[0] * peso.fv[0] + operando2.fv[1] * peso.fv[1] + operando1;
#endif
			layer1_4::write(resultado);

			controlwih1_5::write(idea);
			//controlwih1t_5::write(cuenta_total);
			controlB1_n_BLOCK_SIZE_5::write(n_BLOCK_SIZE);
			controlB1_ultimo_BLOCK_SIZE_5::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_v5()
	{
		//float weight[genial_v];//hidden
		pareja peso;
		T_oper operando1;
		pareja operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih1_5::read();
			//cuenta_total = controlwih1t_5::read();
			n_BLOCK_SIZE = controlB1_n_BLOCK_SIZE_5::read();
			ultimo_BLOCK_SIZE = controlB1_ultimo_BLOCK_SIZE_5::read();


			peso.llv = b1_5::read();
			operando1 = layer1_4::read();
			if (idea == true) {
				operando2.llv = a_5::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_2_cyv_half(operando1, peso.fv[0], operando2.fv[0], peso.fv[1], operando2.fv[1]);

#else
			resultado = operando2.fv[0] * peso.fv[0] + operando2.fv[1] * peso.fv[1] + operando1;
#endif
			layer1_5::write(resultado);

			controlwih1_6::write(idea);
			//controlwih1t_6::write(cuenta_total);
			controlB1_n_BLOCK_SIZE_6::write(n_BLOCK_SIZE);
			controlB1_ultimo_BLOCK_SIZE_6::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_v6()
	{
		//float weight[genial_v];//hidden
		pareja peso;
		T_oper operando1;
		pareja operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih1_6::read();
			//cuenta_total = controlwih1t_6::read();
			n_BLOCK_SIZE = controlB1_n_BLOCK_SIZE_6::read();
			ultimo_BLOCK_SIZE = controlB1_ultimo_BLOCK_SIZE_6::read();


			peso.llv = b1_6::read();
			operando1 = layer1_5::read();
			if (idea == true) {
				operando2.llv = a_6::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_2_cyv_half(operando1, peso.fv[0], operando2.fv[0], peso.fv[1], operando2.fv[1]);

#else
			resultado = operando2.fv[0] * peso.fv[0] + operando2.fv[1] * peso.fv[1] + operando1;
#endif
			layer1_6::write(resultado);

			controlwih1_7::write(idea);
			//controlwih1t_7::write(cuenta_total);
			controlB1_n_BLOCK_SIZE_7::write(n_BLOCK_SIZE);
			controlB1_ultimo_BLOCK_SIZE_7::write(ultimo_BLOCK_SIZE);
		}


	}


    static void PE_v7()
	{
		//float weight[genial_v];//hidden
		pareja peso;
		T_oper operando1;
		pareja operando2;
		T_oper resultado;
		T_oper temp2;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		T_oper tanh_hard(T_oper x);
		//short cuenta_total;  
		while (1)
		{

			idea = controlwih1_7::read();
			//cuenta_total = controlwih1t_7::read();
			n_BLOCK_SIZE = controlB1_n_BLOCK_SIZE_7::read();
			ultimo_BLOCK_SIZE = controlB1_ultimo_BLOCK_SIZE_7::read();


			peso.llv = b1_7::read();
			operando1 = layer1_6::read();
			if (idea == true) {
				operando2.llv = a_7::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_2_cyv_half(operando1, peso.fv[0], operando2.fv[0], peso.fv[1], operando2.fv[1]);

#else
			resultado = operando2.fv[0] * peso.fv[0] + operando2.fv[1] * peso.fv[1] + operando1;
#endif
			if (ultimo_BLOCK_SIZE == true) {
				temp2 = TaskSystem::tanh_hard(resultado);
				//layer1_layer2::write(temp2);
				layer1_layer2.write(temp2);
			}

			else {
				layer1_7::write(resultado);
			}

		}


	}

	static void layer1_SYS_control(int DESTINO, int ORIGEN)
	{

		//short idea = 0;
		//short cuenta_total;
		bool primer_block = true;
		bool ultimo_block = false;
		bool primer_peso_block = false;
#pragma loop_coalesce
		for (uint10 al = 0, veamos = 0; veamos < ORIGEN; al += 2, veamos += 2 * BLOCK_SIZE)

		{

			for (uint8 j = 0; j < DESTINO; ++j)
			{
				//cuenta_total = al * (DESTINO) + j;
				if (j == 0)
					primer_peso_block = true;
				else
					primer_peso_block = false;
				controlwih1_0::write(primer_peso_block);
				if (al == 0)
					primer_block = true;
				else
					primer_block = false;
				controlB1_n_BLOCK_SIZE_0::write(primer_block);
				if ((al + 2)*BLOCK_SIZE >= ORIGEN) {
					ultimo_block = true;
				}
				else
					ultimo_block = false;
				controlB1_ultimo_BLOCK_SIZE_0::write(ultimo_block);
			}
		}


	}

	static void PE_h0()
	{
		//float weight[genial_v];//hidden
		T_oper acumulado = 0;
		T_oper temp, temp3;
		T_com temp2;
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool principio = true;
		bool finalizo = false;
		bool ultimo_BLOCK_SIZE = false;
		T_oper tanh_hard(T_oper x);
		//short cuenta_total;
		while (1)
		{


			finalizo = controlfin2_0::read();

			//cuenta_total=controlwih1t_0::read();
			n_BLOCK_SIZE = controlB2_n_BLOCK_SIZE_0::read();
			ultimo_BLOCK_SIZE = controlB2_ultimo_BLOCK_SIZE_0::read();


			peso = b2_0::read();
			if (n_BLOCK_SIZE == true) {
				//operando2 = layer1_layer2::read();
				operando2 = layer1_layer2.read();
			}
			else {
				operando2 = a2_7::read();
			}
			//mejora para evitar que parte del acumulado entre en la siguiente activacion
			/*
			if (idea == true) {
				temp = acumulado;
				acumulado = 0;
				temp3 = operando2 * peso + temp;
				temp2 = tanh_soft(temp3);
				layer2_0::write(temp2);
			}
			else
				acumulado = operando2 * peso + acumulado;
			*/
#ifdef con_dsp

			principio = controlwih2_0::read();

			acumulado = my_ffaccf_cyv_half(principio, operando2, peso);

#else
			acumulado = operando2 * peso + acumulado;
#endif


			if (finalizo == true) {
				temp2 = TaskSystem::tanh_hard(acumulado);
				layer2_0::write(temp2);
#ifndef con_dsp			
				acumulado = 0;
#endif
			}

			a2_0::write(operando2);
#ifdef con_dsp
			controlwih2_1::write(principio);
#endif

			controlfin2_1::write(finalizo);
			controlB2_n_BLOCK_SIZE_1::write(n_BLOCK_SIZE);
			controlB2_ultimo_BLOCK_SIZE_1::write(ultimo_BLOCK_SIZE);
		}


	}

	static void PE_h1()
	{
		//float weight[genial_v];//hidden
		T_oper acumulado = 0;
		T_oper temp, temp3;
		T_com temp2;
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool principio = true;
		bool finalizo = false;
		bool ultimo_BLOCK_SIZE = false;
		T_oper tanh_hard(T_oper x);
		//short cuenta_total;
		while (1)
		{


			finalizo = controlfin2_1::read();
			//cuenta_total=controlwih1t_0::read();
			n_BLOCK_SIZE = controlB2_n_BLOCK_SIZE_1::read();
			ultimo_BLOCK_SIZE = controlB2_ultimo_BLOCK_SIZE_1::read();


			peso = b2_1::read();
			operando2 = a2_0::read();
			/*
			//mejora para evitar que parte del acumulado entre en la siguiente activacion
			if (idea == true) {
				temp = acumulado;
				acumulado = 0;
				temp3 = operando2 * peso + temp;
				temp2 = tanh_soft(temp3);
				layer2_1::write(temp2);
			}
			else
				acumulado = operando2 * peso + acumulado;
			*/
			
#ifdef con_dsp

			principio = controlwih2_1::read();

			acumulado = my_ffaccf_cyv_half(principio, operando2, peso);


#else
			acumulado = operando2 * peso + acumulado;

#endif
			if (finalizo == true) {
				temp2 = TaskSystem::tanh_hard(acumulado);
				layer2_1::write(temp2);
#ifndef con_dsp			
				acumulado = 0;
#endif
			}
			

			a2_1::write(operando2);
#ifdef con_dsp
			controlwih2_2::write(principio);
#endif
			controlfin2_2::write(finalizo);
			controlB2_n_BLOCK_SIZE_2::write(n_BLOCK_SIZE);
			controlB2_ultimo_BLOCK_SIZE_2::write(ultimo_BLOCK_SIZE);
		}


	}

	static void PE_h2()
	{
		//float weight[genial_v];//hidden
		T_oper acumulado = 0;
		T_oper temp, temp3;
		T_com temp2;
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool principio = true;
		bool finalizo = false;
		bool ultimo_BLOCK_SIZE = false;
		T_oper tanh_hard(T_oper x);
		//short cuenta_total;
		while (1)
		{


			finalizo = controlfin2_2::read();
			//cuenta_total=controlwih1t_0::read();
			n_BLOCK_SIZE = controlB2_n_BLOCK_SIZE_2::read();
			ultimo_BLOCK_SIZE = controlB2_ultimo_BLOCK_SIZE_2::read();


			peso = b2_2::read();
			operando2 = a2_1::read();
			/*
			//mejora para evitar que parte del acumulado entre en la siguiente activacion
			if (idea == true) {
				temp = acumulado;
				acumulado = 0;
				temp3 = operando2 * peso + temp;
				temp2 = tanh_soft(temp3);
				layer2_2::write(temp2);
			}
			else
				acumulado = operando2 * peso + acumulado;
			*/
#ifdef con_dsp

			principio = controlwih2_2::read();
			acumulado = my_ffaccf_cyv_half(principio, operando2, peso);

#else
			acumulado = operando2 * peso + acumulado;
#endif
			if (finalizo == true) {
				temp2 = TaskSystem::tanh_hard(acumulado);
				layer2_2::write(temp2);
#ifndef con_dsp			
				acumulado = 0;
#endif
			}
			

			a2_2::write(operando2);
#ifdef con_dsp
			controlwih2_3::write(principio);
#endif
			controlfin2_3::write(finalizo);
			//controlwih1t_1::write(cuenta_total);
			controlB2_n_BLOCK_SIZE_3::write(n_BLOCK_SIZE);
			controlB2_ultimo_BLOCK_SIZE_3::write(ultimo_BLOCK_SIZE);
		}


	}

	static void PE_h3()
	{
		//float weight[genial_v];//hidden
		T_oper acumulado = 0;
		T_oper temp, temp3;
		T_oper temp2;
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool principio = true;
		bool finalizo = false;
		bool ultimo_BLOCK_SIZE = false;
		T_oper tanh_hard(T_oper x);
		//short cuenta_total;
		while (1)
		{


			finalizo = controlfin2_3::read();
			//cuenta_total=controlwih1t_0::read();
			n_BLOCK_SIZE = controlB2_n_BLOCK_SIZE_3::read();
			ultimo_BLOCK_SIZE = controlB2_ultimo_BLOCK_SIZE_3::read();


			peso = b2_3::read();
			operando2 = a2_2::read();
			/*
			//mejora para evitar que parte del acumulado entre en la siguiente activacion
			if (idea == true) {
				temp = acumulado;
				acumulado = 0;
				temp3 = operando2 * peso + temp;
				temp2 = tanh_soft(temp3);
				layer2_3::write(temp2);
			}
			else
				acumulado = operando2 * peso + acumulado;
			*/
#ifdef con_dsp

			principio = controlwih2_3::read();

			acumulado = my_ffaccf_cyv_half(principio, operando2, peso);

#else
			acumulado = operando2 * peso + acumulado;
#endif
			if (finalizo == true) {
				temp2 = TaskSystem::tanh_hard(acumulado);
				layer2_3::write(temp2);
#ifndef con_dsp			
				acumulado = 0;
#endif
			}
			

			a2_3::write(operando2);
#ifdef con_dsp
			controlwih2_4::write(principio);
#endif
			controlfin2_4::write(finalizo);
			//controlwih1t_1::write(cuenta_total);
			controlB2_n_BLOCK_SIZE_4::write(n_BLOCK_SIZE);
			controlB2_ultimo_BLOCK_SIZE_4::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_h4()
	{
		//float weight[genial_v];//hidden
		T_oper acumulado = 0;
		T_oper temp, temp3;
		T_oper temp2;
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool principio = true;
		bool finalizo = false;
		bool ultimo_BLOCK_SIZE = false;
		T_oper tanh_hard(T_oper x);
		//short cuenta_total;
		while (1)
		{


			finalizo = controlfin2_4::read();
			//cuenta_total=controlwih1t_0::read();
			n_BLOCK_SIZE = controlB2_n_BLOCK_SIZE_4::read();
			ultimo_BLOCK_SIZE = controlB2_ultimo_BLOCK_SIZE_4::read();


			peso = b2_4::read();
			operando2 = a2_3::read();
			/*
			//mejora para evitar que parte del acumulado entre en la siguiente activacion
			if (idea == true) {
				temp = acumulado;
				acumulado = 0;
				temp3 = operando2 * peso + temp;
				temp2 = tanh_soft(temp3);
				layer2_4::write(temp2);
			}
			else
				acumulado = operando2 * peso + acumulado;
			*/
#ifdef con_dsp

			principio = controlwih2_4::read();

			acumulado = my_ffaccf_cyv_half(principio, operando2, peso);

#else
			acumulado = operando2 * peso + acumulado;
#endif
			if (finalizo == true) {
				temp2 = TaskSystem::tanh_hard(acumulado);
				layer2_4::write(temp2);
#ifndef con_dsp			
				acumulado = 0;
#endif
			}
			

			a2_4::write(operando2);
#ifdef con_dsp
			controlwih2_5::write(principio);
#endif
			controlfin2_5::write(finalizo);
			//controlwih1t_1::write(cuenta_total);
			controlB2_n_BLOCK_SIZE_5::write(n_BLOCK_SIZE);
			controlB2_ultimo_BLOCK_SIZE_5::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_h5()
	{
		//float weight[genial_v];//hidden
		T_oper acumulado = 0;
		T_oper temp, temp3;
		T_oper temp2;
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool principio = true;
		bool finalizo = false;
		bool ultimo_BLOCK_SIZE = false;
		T_oper tanh_hard(T_oper x);
		//short cuenta_total;
		while (1)
		{


			finalizo = controlfin2_5::read();
			//cuenta_total=controlwih1t_0::read();
			n_BLOCK_SIZE = controlB2_n_BLOCK_SIZE_5::read();
			ultimo_BLOCK_SIZE = controlB2_ultimo_BLOCK_SIZE_5::read();


			peso = b2_5::read();
			operando2 = a2_4::read();
			/*
			//mejora para evitar que parte del acumulado entre en la siguiente activacion
			if (idea == true) {
				temp = acumulado;
				acumulado = 0;
				temp3 = operando2 * peso + temp;
				temp2 = tanh_soft(temp3);
				layer2_5::write(temp2);
			}
			else
				acumulado = operando2 * peso + acumulado;
			*/
#ifdef con_dsp

			principio = controlwih2_5::read();

			acumulado = my_ffaccf_cyv_half(principio, operando2, peso);

#else
			acumulado = operando2 * peso + acumulado;
#endif
			if (finalizo == true) {
				temp2 = TaskSystem::tanh_hard(acumulado);
				layer2_5::write(temp2);
#ifndef con_dsp			
				acumulado = 0;
#endif
			}
			

			a2_5::write(operando2);
#ifdef con_dsp
			controlwih2_6::write(principio);
#endif
			controlfin2_6::write(finalizo);
			//controlwih1t_1::write(cuenta_total);
			controlB2_n_BLOCK_SIZE_6::write(n_BLOCK_SIZE);
			controlB2_ultimo_BLOCK_SIZE_6::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_h6()
	{
		//float weight[genial_v];//hidden
		T_oper acumulado = 0;
		T_oper temp, temp3;
		T_oper temp2;
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool principio = true;
		bool finalizo = false;
		bool ultimo_BLOCK_SIZE = false;
		T_oper tanh_hard(T_oper x);
		//short cuenta_total;
		while (1)
		{


			finalizo = controlfin2_6::read();
			//cuenta_total=controlwih1t_0::read();
			n_BLOCK_SIZE = controlB2_n_BLOCK_SIZE_6::read();
			ultimo_BLOCK_SIZE = controlB2_ultimo_BLOCK_SIZE_6::read();


			peso = b2_6::read();
			operando2 = a2_5::read();
			/*
			//mejora para evitar que parte del acumulado entre en la siguiente activacion
			if (idea == true) {
				temp = acumulado;
				acumulado = 0;
				temp3 = operando2 * peso + temp;
				temp2 = tanh_soft(temp3);
				layer2_6::write(temp2);
			}
			else
				acumulado = operando2 * peso + acumulado;
			*/
#ifdef con_dsp

			principio = controlwih2_6::read();

			acumulado = my_ffaccf_cyv_half(principio, operando2, peso);

#else
			acumulado = operando2 * peso + acumulado;
#endif
			if (finalizo == true) {
				temp2 = TaskSystem::tanh_hard(acumulado);
				layer2_6::write(temp2);
#ifndef con_dsp			
				acumulado = 0;
#endif
			}
			

			a2_6::write(operando2);
#ifdef con_dsp
			controlwih2_7::write(principio);
#endif
			controlfin2_7::write(finalizo);
			//controlwih1t_1::write(cuenta_total);
			controlB2_n_BLOCK_SIZE_7::write(n_BLOCK_SIZE);
			controlB2_ultimo_BLOCK_SIZE_7::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_h7()
	{
		//float weight[genial_v];//hidden
		T_oper acumulado = 0;
		T_oper temp, temp3;
		T_oper temp2;
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool principio = true;
		bool finalizo = false;
		bool ultimo_BLOCK_SIZE = false;
		T_oper tanh_hard(T_oper x);
		//short cuenta_total;
		while (1)
		{


			finalizo = controlfin2_7::read();
			//cuenta_total=controlwih1t_0::read();
			n_BLOCK_SIZE = controlB2_n_BLOCK_SIZE_7::read();
			ultimo_BLOCK_SIZE = controlB2_ultimo_BLOCK_SIZE_7::read();


			peso = b2_7::read();
			operando2 = a2_6::read();
			/*
			//mejora para evitar que parte del acumulado entre en la siguiente activacion
			if (idea == true) {
				temp = acumulado;
				acumulado = 0;
				temp3 = operando2 * peso + temp;
				temp2 = tanh_soft(temp3);
				layer2_7::write(temp2);
			}
			else
				acumulado = operando2 * peso + acumulado;
			*/
#ifdef con_dsp

			principio = controlwih2_7::read();

			acumulado = my_ffaccf_cyv_half(principio, operando2, peso);

#else
			acumulado = operando2 * peso + acumulado;
#endif
			if (finalizo == true) {
				temp2 = TaskSystem::tanh_hard(acumulado);
				layer2_7::write(temp2);
#ifndef con_dsp			
				acumulado = 0;
#endif
			}
			
			if (!ultimo_BLOCK_SIZE)
				a2_7::write(operando2);


		}


	}
	static void layer2_SYS_control(int DESTINO, int ORIGEN)
	{

		//short idea = 0;
		//short cuenta_total;
		bool primer_block = true;
		bool ultimo_block = false;
#ifdef con_dsp
		bool primer_peso_block = false;
#endif
		bool ultima_activacion = false;
#pragma loop_coalesce
		for (uint8 al = 0, veamos = 0; veamos < DESTINO; al += 1, veamos += BLOCK_SIZE)

		{

			for (uint8 j = 0; j < ORIGEN; ++j)
			{
				//cuenta_total = al * (DESTINO) + j;
#ifdef con_dsp
				if (j == 0)
					primer_peso_block = true;
				else
					primer_peso_block = false;

				controlwih2_0::write(primer_peso_block);
#endif

				if (j == ORIGEN - 1)
					ultima_activacion = true;
				else
					ultima_activacion = false;


				controlfin2_0::write(ultima_activacion);
				if (al == 0)
					primer_block = true;
				else
					primer_block = false;
				controlB2_n_BLOCK_SIZE_0::write(primer_block);
				if ((al + 1)*BLOCK_SIZE >= DESTINO) {
					ultimo_block = true;
				}
				else
					ultimo_block = false;
				controlB2_ultimo_BLOCK_SIZE_0::write(ultimo_block);
			}
		}
	}

	static void PE_vf0()
	{
		//float weight[genial_v];//hidden
		T_oper temp = 0;
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{


			idea = controlwih3_0::read();
			//cuenta_total=controlwih1t_0::read();
			n_BLOCK_SIZE = controlB3_n_BLOCK_SIZE_0::read();
			ultimo_BLOCK_SIZE = controlB3_ultimo_BLOCK_SIZE_0::read();


			peso = b3_0::read();
			if (n_BLOCK_SIZE == false) {
				operando1 = layer3_7::read();
			}
			else {
				operando1 = temp;
			}

			if (idea == true) {
				operando2 = layer2_0::read();
			}
#ifdef con_dsp



			resultado = my_ffplusf_cyv_half(operando1, peso, operando2);

#else
			resultado = operando2 * peso + operando1;
#endif
			layer3_0::write(resultado);

			controlwih3_1::write(idea);
			//controlwih1t_1::write(cuenta_total);
			controlB3_n_BLOCK_SIZE_1::write(n_BLOCK_SIZE);
			controlB3_ultimo_BLOCK_SIZE_1::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_vf1()
	{
		//float weight[genial_v];//hidden
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih3_1::read();
			//cuenta_total = controlwih1t_1::read();
			n_BLOCK_SIZE = controlB3_n_BLOCK_SIZE_1::read();
			ultimo_BLOCK_SIZE = controlB3_ultimo_BLOCK_SIZE_1::read();


			peso = b3_1::read();
			operando1 = layer3_0::read();
			if (idea == true) {
				operando2 = layer2_1::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_cyv_half(operando1, peso, operando2);

#else
			resultado = operando2 * peso + operando1;
#endif
			layer3_1::write(resultado);

			controlwih3_2::write(idea);
			//controlwih1t_2::write(cuenta_total);
			controlB3_n_BLOCK_SIZE_2::write(n_BLOCK_SIZE);
			controlB3_ultimo_BLOCK_SIZE_2::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_vf2()
	{
		//float weight[genial_v];//hidden
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih3_2::read();
			//cuenta_total = controlwih1t_2::read();
			n_BLOCK_SIZE = controlB3_n_BLOCK_SIZE_2::read();
			ultimo_BLOCK_SIZE = controlB3_ultimo_BLOCK_SIZE_2::read();


			peso = b3_2::read();
			operando1 = layer3_1::read();
			if (idea == true) {
				operando2 = layer2_2::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_cyv_half(operando1, peso, operando2);

#else
			resultado = operando2 * peso + operando1;
#endif
			layer3_2::write(resultado);

			controlwih3_3::write(idea);
			//controlwih1t_3::write(cuenta_total);
			controlB3_n_BLOCK_SIZE_3::write(n_BLOCK_SIZE);
			controlB3_ultimo_BLOCK_SIZE_3::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_vf3()
	{
		//float weight[genial_v];//hidden
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih3_3::read();
			//cuenta_total = controlwih1t_3::read();
			n_BLOCK_SIZE = controlB3_n_BLOCK_SIZE_3::read();
			ultimo_BLOCK_SIZE = controlB3_ultimo_BLOCK_SIZE_3::read();


			peso = b3_3::read();
			operando1 = layer3_2::read();
			if (idea == true) {
				operando2 = layer2_3::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_cyv_half(operando1, peso, operando2);

#else
			resultado = operando2 * peso + operando1;
#endif
			layer3_3::write(resultado);

			controlwih3_4::write(idea);
			//controlwih1t_4::write(cuenta_total);
			controlB3_n_BLOCK_SIZE_4::write(n_BLOCK_SIZE);
			controlB3_ultimo_BLOCK_SIZE_4::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_vf4()
	{
		//float weight[genial_v];//hidden
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih3_4::read();
			//cuenta_total = controlwih1t_4::read();
			n_BLOCK_SIZE = controlB3_n_BLOCK_SIZE_4::read();
			ultimo_BLOCK_SIZE = controlB3_ultimo_BLOCK_SIZE_4::read();


			peso = b3_4::read();
			operando1 = layer3_3::read();
			if (idea == true) {
				operando2 = layer2_4::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_cyv_half(operando1, peso, operando2);

#else
			resultado = operando2 * peso + operando1;
#endif
			layer3_4::write(resultado);

			controlwih3_5::write(idea);
			//controlwih1t_5::write(cuenta_total);
			controlB3_n_BLOCK_SIZE_5::write(n_BLOCK_SIZE);
			controlB3_ultimo_BLOCK_SIZE_5::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_vf5()
	{
		//float weight[genial_v];//hidden
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih3_5::read();
			//cuenta_total = controlwih1t_5::read();
			n_BLOCK_SIZE = controlB3_n_BLOCK_SIZE_5::read();
			ultimo_BLOCK_SIZE = controlB3_ultimo_BLOCK_SIZE_5::read();


			peso = b3_5::read();
			operando1 = layer3_4::read();
			if (idea == true) {
				operando2 = layer2_5::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_cyv_half(operando1, peso, operando2);

#else
			resultado = operando2 * peso + operando1;
#endif
			layer3_5::write(resultado);

			controlwih3_6::write(idea);
			//controlwih1t_6::write(cuenta_total);
			controlB3_n_BLOCK_SIZE_6::write(n_BLOCK_SIZE);
			controlB3_ultimo_BLOCK_SIZE_6::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_vf6()
	{
		//float weight[genial_v];//hidden
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		//short cuenta_total;
		while (1)
		{

			idea = controlwih3_6::read();
			//cuenta_total = controlwih1t_6::read();
			n_BLOCK_SIZE = controlB3_n_BLOCK_SIZE_6::read();
			ultimo_BLOCK_SIZE = controlB3_ultimo_BLOCK_SIZE_6::read();


			peso = b3_6::read();
			operando1 = layer3_5::read();
			if (idea == true) {
				operando2 = layer2_6::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_cyv_half(operando1, peso, operando2);

#else
			resultado = operando2 * peso + operando1;
#endif
			layer3_6::write(resultado);

			controlwih3_7::write(idea);
			//controlwih1t_7::write(cuenta_total);
			controlB3_n_BLOCK_SIZE_7::write(n_BLOCK_SIZE);
			controlB3_ultimo_BLOCK_SIZE_7::write(ultimo_BLOCK_SIZE);
		}


	}
	static void PE_vf7()
	{
		//float weight[genial_v];//hidden
		T_oper peso;
		T_oper operando1;
		T_oper operando2;
		T_oper resultado;
		T_oper temp2;
		bool n_BLOCK_SIZE = true;
		bool idea = false;
		bool ultimo_BLOCK_SIZE = false;
		T_oper tanh_hard(T_oper x);
		//short cuenta_total;  
		while (1)
		{

			idea = controlwih3_7::read();
			//cuenta_total = controlwih1t_7::read();
			n_BLOCK_SIZE = controlB3_n_BLOCK_SIZE_7::read();
			ultimo_BLOCK_SIZE = controlB3_ultimo_BLOCK_SIZE_7::read();


			peso = b3_7::read();
			operando1 = layer3_6::read();
			if (idea == true) {
				operando2 = layer2_7::read();
			}
#ifdef con_dsp

			resultado = my_ffplusf_cyv_half(operando1, peso, operando2);

#else
			resultado = operando2 * peso + operando1;
#endif
			if (ultimo_BLOCK_SIZE == true) {
				temp2 = TaskSystem::tanh_hard(resultado);
				sal::write(temp2);
			}

			else {
				layer3_7::write(resultado);
			}

		}


	}

	static void layer3_SYS_control(int DESTINO, int ORIGEN)
	{

		//short idea = 0;
		//short cuenta_total;
		bool primer_block = true;
		bool ultimo_block = false;
		bool primer_peso_block = false;
#pragma loop_coalesce
		for (uint8 al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos += BLOCK_SIZE)

		{

			for (uint4 j = 0; j < DESTINO; ++j)
			{
				//cuenta_total = al * (DESTINO) + j;
				if (j == 0)
					primer_peso_block = true;
				else
					primer_peso_block = false;
				controlwih3_0::write(primer_peso_block);
				if (al == 0)
					primer_block = true;
				else
					primer_block = false;
				controlB3_n_BLOCK_SIZE_0::write(primer_block);
				if ((al + 1)*BLOCK_SIZE >= ORIGEN) {
					ultimo_block = true;
				}
				else
					ultimo_block = false;
				controlB3_ultimo_BLOCK_SIZE_0::write(ultimo_block);
			}
		}
	}

	static void layer1_SYS(int DESTINO, int ORIGEN)
	{

		T_oper temp, temp3;
		T_com temp2;
		T_oper a_fp16[BLOCK_SIZE];
		T_oper b_fp16[BLOCK_SIZE];

		/*
		float temp, temp2;
		float a_fp16;
		float b_fp16;
		*/
		//float tanh_soft(float x);
		for (size_t al = 0, veamos = 0; veamos < ORIGEN; al += 1, veamos += BLOCK_SIZE)

		{
			a_fp16[0] = a_0::read();
			a_fp16[1] = a_1::read();
			a_fp16[2] = a_2::read();
			a_fp16[3] = a_3::read();
			a_fp16[4] = a_4::read();
			a_fp16[5] = a_5::read();
			a_fp16[6] = a_6::read();
			a_fp16[7] = a_7::read();
			for (int j = 0; j < DESTINO; ++j) 
			{
				temp = 0;
				b_fp16[0] = b1_0::read();
				b_fp16[1] = b1_1::read();
				b_fp16[2] = b1_2::read();
				b_fp16[3] = b1_3::read();
				b_fp16[4] = b1_4::read();
				b_fp16[5] = b1_5::read();
				b_fp16[6] = b1_6::read();
				b_fp16[7] = b1_7::read();

				if (al == 0)
					temp = 0;
				else
					temp = layer1_7::read();

				temp3 = a_fp16[0] * b_fp16[0] + temp;
				layer1_0::write(temp3);

				temp = layer1_0::read();
				temp3 = a_fp16[1] * b_fp16[1] + temp;
				layer1_1::write(temp3);

				temp = layer1_1::read();
				temp3 = a_fp16[2] * b_fp16[2] + temp;
				layer1_2::write(temp3);

				temp = layer1_2::read();
				temp3 = a_fp16[3] * b_fp16[3] + temp;
				layer1_3::write(temp3);

				temp = layer1_3::read();
				temp3 = a_fp16[4] * b_fp16[4] + temp;
				layer1_4::write(temp3);

				temp = layer1_4::read();
				temp3 = a_fp16[5] * b_fp16[5] + temp;
				layer1_5::write(temp3);

				temp = layer1_5::read();
				temp3 = a_fp16[6] * b_fp16[6] + temp;
				layer1_6::write(temp3);

				temp = layer1_6::read();
				temp3 = a_fp16[7] * b_fp16[7] + temp;



				if ((al + 1)*BLOCK_SIZE >= ORIGEN) {
					temp2 = my_tanhfp162fd(temp3);
					layer1_layer2::write(temp2);
				}
				else
					layer1_7::write(temp3);

			

				/*
				#pragma unroll  
				for (int i = 0; i < BLOCK_SIZE; ++i) {
					if (i == 0)
						if (al == 0)
							temp = 0;
						else
							temp = loop1::read();
					else
						temp = layer1_array<i - 1>::read();

					temp3 = a_fp16 * b_fp16 + temp;
					if (i == BLOCK_SIZE - 1)
						if ((al + 1)*BLOCK_SIZE >= ORIGEN) {}
					temp2 = my_tanhfp162fd(temp3);
					layer1_layer2::write(temp2);
				}
						else
							loop1::write(temp3);
					else
						layer1_array<i>::write(temp3);
				}
				*/
			}
		}


	}

	static void layer1_alt(int DESTINO, int ORIGEN)
	{

		ihc::bfloat16 temp;
		ihc::bfloat16 temp2[BUFFER_SIZE][BUFFER_SIZE];
		ihc::bfloat16 a_fp16;
		ihc::bfloat16 b_fp16;

		//float temp;
		//float temp2[BUFFER_SIZE][BUFFER_SIZE];
		//float a_fp16;
		//float b_fp16;
		float tanh_soft(float x);
		for (int j = 0; j < ORIGEN; ++j) {
			a_fp16 = MySystem::a::read();
			for (int i = 0; i < DESTINO; ++i) {
				b_fp16 = b1.read();
				if (j == 0)
					temp2[i][j] = 0.0;
				temp2[i][j + 1] = a_fp16 * b_fp16 + temp2[i][j];
				if (j == ORIGEN - 1) {
					temp = my_tanhfp162fd(temp2[i][j + 1]);
					layer1_layer2.write(temp);
				}
			}

		}
	}
	static void consumer(ACTIVACIONOUT *activacion, int DESTINO)
	{
		for (int j = 0; j < DESTINO; ++j) {
			(*activacion)[j] = sal::read();
		}
	}


	static void layer2_alt(int DESTINO, int ORIGEN)
	{

		T_com temp2;
		T_oper temp[BUFFER_SIZE][BUFFER_SIZE];
		T_oper a_fp16;
		T_oper b_fp16;

		//float temp;
		//float temp2[BUFFER_SIZE][BUFFER_SIZE];
		//float a_fp16;
		//float b_fp16;
		float tanh_soft(float x);
		for (int j = 0; j < ORIGEN; ++j) {
			a_fp16 = layer1_layer2::read();
			for (int i = 0; i < DESTINO; ++i) {
				b_fp16 = b2::read();
				if (j == 0)
					temp[i][j] = 0.0;
				temp[i][j + 1] = a_fp16 * b_fp16 + temp[i][j];
				if (j == ORIGEN - 1) {
					temp2 = my_tanhfp162fd(temp[i][j + 1]);
					layer2_layer3::write(temp2);
				}
			}

		}
	}
	static void layer2(int DESTINO, int ORIGEN)
	{

		ihc::bfloat16 temp, temp2;
		ihc::bfloat16 a_fp16;
		ihc::bfloat16 b_fp16;
		/*
		float temp, temp2;
		float a_fp16;
		float b_fp16;
		*/
		float tanh_soft(float x);
		for (int j = 0; j < DESTINO; ++j) {
			temp = 0;

			for (int i = 0; i < ORIGEN; ++i) {
				if (j == 0)
					a_fp16 = layer1_layer2::read();
				else
					a_fp16 = loop2::read();
				b_fp16 = b2::read();
				temp = a_fp16 * b_fp16 + temp;
				if (j != DESTINO - 1)
					loop2::write(a_fp16);
			}
			temp2 = my_tanhfp162fd(temp);
			layer2_layer3::write(temp2);
		}
	}
	static void layer3(int DESTINO, int ORIGEN)
	{

		T_oper temp;
		T_com temp2;
		T_oper a_fp16;
		T_oper b_fp16;
		/*
		float temp, temp2;
		float a_fp16;
		float b_fp16;
		*/
		float tanh_soft(float x);
		for (int j = 0; j < DESTINO; ++j) {
			temp = 0;

			for (int i = 0; i < ORIGEN; ++i) {
				if (j == 0)
					a_fp16 = layer2_layer3::read();
				else
					a_fp16 = loop3::read();
				b_fp16 = b3::read();
				temp = a_fp16 * b_fp16 + temp;
				if (j != DESTINO - 1)
					loop3::write(a_fp16);
			}
			temp2 = my_tanhfp162fd(temp);
			sal::write(temp2);
		}
	}
	static void layer3_from_H(int DESTINO, int ORIGEN)
	{
		int procedencia;
		T_oper temp;
		T_com temp2;
		T_oper a_fp16;
		T_oper b_fp16;
		/*
		float temp, temp2;
		float a_fp16;
		float b_fp16;
		*/
		float tanh_soft(float x);
		for (int j = 0; j < DESTINO; ++j) {
			temp = 0;

			for (int i = 0; i < ORIGEN; ++i) {
				if (j == 0){
					procedencia = i % BLOCK_SIZE;
				switch (procedencia) {
				case 0: a_fp16 = layer2_0::read();
					break;
				case 1: a_fp16 = layer2_1::read();
					break;
				case 2: a_fp16 = layer2_2::read();
					break;
				case 3: a_fp16 = layer2_3::read();
					break;
				case 4: a_fp16 = layer2_4::read();
					break;
				case 5: a_fp16 = layer2_5::read();
					break;
				case 6: a_fp16 = layer2_6::read();
					break;
				case 7: a_fp16 = layer2_7::read();
					break;
				}
			}
				else
					a_fp16 = loop3::read();
				b_fp16 = b3::read();
				temp = a_fp16 * b_fp16 + temp;
				if (j != DESTINO - 1)
					loop3::write(a_fp16);
			}
			temp2 = my_tanhfp162fd(temp);
			sal::write(temp2);
		}
	}
	static void layer3_alt(int DESTINO, int ORIGEN)
	{

		ihc::bfloat16 temp;
		ihc::bfloat16 temp2[BUFFER_SIZE][BUFFER_SIZE];
		ihc::bfloat16 a_fp16;
		ihc::bfloat16 b_fp16;

		//float temp;
		//float temp2[BUFFER_SIZE][BUFFER_SIZE];
		//float a_fp16;
		//float b_fp16;
		float tanh_soft(float x);
		for (int j = 0; j < ORIGEN; ++j) {
			a_fp16 = layer2_layer3.read();
			for (int i = 0; i < DESTINO; ++i) {
				b_fp16 = b3.read();
				if (j == 0)
					temp2[i][j] = 0.0;
				temp2[i][j + 1] = a_fp16 * b_fp16 + temp2[i][j];
				if (j == ORIGEN - 1) {
					temp = my_tanhfp162fd(temp2[i][j + 1]);
					sal.write(temp);
				}
			}

		}
	}

static T_oper tanh_hard(T_oper x)
	{
#if tabla==false
	return  (1.0 - ihc::ihc_exp(-2 * x)) / (1.0 + ihc::ihc_exp(-2 * x));
#else

#if noper==1
	return my_tanhFPsingle(x);
#endif

#if noper==2
	return my_tanhbfloat19(x);
#endif
#if noper==3
	return my_tanhfp16(x);
#endif

#if noper==4
	return my_tanhbfloat16(x);
#endif


#endif
		
	}



}; 

