#!/bin/bash
bp_path=/usr/local/breakpads
export PATH=$bp_path/bin:$PATH
export LD_LIBRARY_PATH=$bp_path/lib:$LD_LIBRARY_PATH

g++ -g  -std=c++11 test.cpp -I $bp_path/include/breakpad $bp_path/lib/libbreakpad_client.a -lpthread -o test
