#!/bin/bash
./main.exe $1 $2 $3
python3 diagram.py $1 $2
