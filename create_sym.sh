#!/bin/bash

/usr/local/breakpads/bin/dump_syms ./test > test.sym
sym_id=`head -n 1 test.sym | awk '{ print $4}'`

echo $sym_id
sym_dir=./symbols/test/$sym_id
mkdir -p $sym_dir
mv test.sym $sym_dir

/usr/local/breakpads/bin/minidump_stackwalk 
