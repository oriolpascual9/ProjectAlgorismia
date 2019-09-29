#!/bin/bash
if [ ! -e main.exe ];
then
    make
fi
./main.exe $1 $2
python3 diagram.py $1
