#!/bin/bash

myfile=$1

file_no_ext="${myfile%.*}"


sym_id=`head -n 1 $myfile | awk '{ print $4}'`

echo $sym_id
sym_dir="./symbols/$file_no_ext".pdb"/$sym_id"
mkdir -p $sym_dir
mv $myfile $sym_dir
