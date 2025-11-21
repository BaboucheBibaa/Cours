#!/bin/bash


v=`echo $1 | cut -d'=' -f1`
if [ $v == p ]; 
then
    p=`echo $1 | cut -d'=' -f2`
else 
    n=`echo $1 | cut -d'=' -f2`
fi

v=`echo $2 | cut -d'=' -f1`
if [ $v == p ];
then
    p=`echo $2 | cut -d'=' -f2`
else 
    p=`echo $2 | cut -d'=' -f2`
fi
echo p=$p, n=$n;


if [ $# -ne 2 ]; then
    exit 2
fi

for i in $(seq $p)
do
    echo $((n * i))
done