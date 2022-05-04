#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
extern "C" void MVM_opcion_sistolica(int*, int, int, int, int, int);
extern "C" void apatb_MVM_opcion_sistolica_hw(volatile void * __xlx_apatb_param_input1, volatile void * __xlx_apatb_param_input2, volatile void * __xlx_apatb_param_output, int __xlx_apatb_param_MM, int __xlx_apatb_param_NN) {
  // Collect __xlx_input1_input2_output__tmp_vec
  vector<sc_bv<32> >__xlx_input1_input2_output__tmp_vec;
  for (int j = 0, e = 16; j != e; ++j) {
    __xlx_input1_input2_output__tmp_vec.push_back(((int*)__xlx_apatb_param_input1)[j]);
  }
  int __xlx_size_param_input1 = 16;
  int __xlx_offset_param_input1 = 0;
  int __xlx_offset_byte_param_input1 = 0*4;
  for (int j = 0, e = 128; j != e; ++j) {
    __xlx_input1_input2_output__tmp_vec.push_back(((int*)__xlx_apatb_param_input2)[j]);
  }
  int __xlx_size_param_input2 = 128;
  int __xlx_offset_param_input2 = 16;
  int __xlx_offset_byte_param_input2 = 16*4;
  for (int j = 0, e = 8; j != e; ++j) {
    __xlx_input1_input2_output__tmp_vec.push_back(((int*)__xlx_apatb_param_output)[j]);
  }
  int __xlx_size_param_output = 8;
  int __xlx_offset_param_output = 144;
  int __xlx_offset_byte_param_output = 144*4;
  int* __xlx_input1_input2_output__input_buffer= new int[__xlx_input1_input2_output__tmp_vec.size()];
  for (int i = 0; i < __xlx_input1_input2_output__tmp_vec.size(); ++i) {
    __xlx_input1_input2_output__input_buffer[i] = __xlx_input1_input2_output__tmp_vec[i].range(31, 0).to_uint64();
  }
  // DUT call
  MVM_opcion_sistolica(__xlx_input1_input2_output__input_buffer, __xlx_offset_byte_param_input1, __xlx_offset_byte_param_input2, __xlx_offset_byte_param_output, __xlx_apatb_param_MM, __xlx_apatb_param_NN);
// print __xlx_apatb_param_input1
  sc_bv<32>*__xlx_input1_output_buffer = new sc_bv<32>[__xlx_size_param_input1];
  for (int i = 0; i < __xlx_size_param_input1; ++i) {
    __xlx_input1_output_buffer[i] = __xlx_input1_input2_output__input_buffer[i+__xlx_offset_param_input1];
  }
  for (int i = 0; i < __xlx_size_param_input1; ++i) {
    ((int*)__xlx_apatb_param_input1)[i] = __xlx_input1_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_input2
  sc_bv<32>*__xlx_input2_output_buffer = new sc_bv<32>[__xlx_size_param_input2];
  for (int i = 0; i < __xlx_size_param_input2; ++i) {
    __xlx_input2_output_buffer[i] = __xlx_input1_input2_output__input_buffer[i+__xlx_offset_param_input2];
  }
  for (int i = 0; i < __xlx_size_param_input2; ++i) {
    ((int*)__xlx_apatb_param_input2)[i] = __xlx_input2_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_output
  sc_bv<32>*__xlx_output_output_buffer = new sc_bv<32>[__xlx_size_param_output];
  for (int i = 0; i < __xlx_size_param_output; ++i) {
    __xlx_output_output_buffer[i] = __xlx_input1_input2_output__input_buffer[i+__xlx_offset_param_output];
  }
  for (int i = 0; i < __xlx_size_param_output; ++i) {
    ((int*)__xlx_apatb_param_output)[i] = __xlx_output_output_buffer[i].to_uint64();
  }
}
