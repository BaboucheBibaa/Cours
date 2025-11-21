#!/bin/bash

#syracuse

if [ $# -ne 1 ]; then
    echo "un paramètre requis"
    exit 2
fi

val=$1

while [ $val -ne 1 ]
do
    if [ $(($val % 2)) -eq 0 ]; then
        val=$((val / 2))
        echo $val
    else 
        val=$((3 * val + 1 ))
        echo $val
    fi
done 

