#!/bin/bash

if [ $# -eq 2 ]; then
for i in $(seq $1)
do
    echo $(expr $i \* $2)
done
fi