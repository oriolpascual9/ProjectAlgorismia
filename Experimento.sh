#!/bin/bash
if [ $# -eq 0 ];
then
    echo "\nUsage: sh Experimento.sh RGG/BRG nr_nodes [focus]\n"
else
    ./main.exe $1 $2 $3 $4
    python3 diagram.py $1
fi
