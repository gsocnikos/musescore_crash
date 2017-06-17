#!/bin/bash

sym_id=`head -n 1 $1 | awk '{ print $4}'`

echo $sym_id
sym_dir=./symbols/qt_example.pdb/$sym_id
mkdir -p $sym_dir
mv $1 $sym_dir
