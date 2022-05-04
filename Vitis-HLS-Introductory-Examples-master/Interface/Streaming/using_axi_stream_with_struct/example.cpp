/*
 * Copyright 2021 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "example.h"

void example(mystream &A, mystream &B) {
#pragma HLS INTERFACE axis port=A
#pragma HLS INTERFACE axis port=B


    data_t tmp_a;
    
    do {
        tmp_a = A.read();
        data_t tmp_b;
        tmp_b.data.real(tmp_a.data.real() + 5);
        tmp_b.data.imag(tmp_a.data.imag() + 1);
        B.write(tmp_b);
    } while (!tmp_a.last);
}

