/*
 * Copyright 2021 Xilinx, Inc.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "example.h"

int dut(hls::stream<int> s_in[M], hls::stream<int> s_out[M]) {
#pragma HLS INTERFACE axis port=s_in
#pragma HLS INTERFACE axis port=s_out
    
  int sum = 0;
  for (unsigned j = 0; j < M; j++) {
      for (unsigned i = 0; i < 10; i++) {
          int val = s_in[j].read();
          s_out[j].write(val + 2);
          sum += val;
      }
  }
  return sum;
}


