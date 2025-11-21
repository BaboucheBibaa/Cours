#!/bin/bash

eval set `echo $1 | tr [/] [ ]`
echo $1;

i=$1;
if [ ! -f $i ] || [ ! -d $i ]; then
    echo $i n existe pas;
fi

i=`dirname $i`;

while [ $i != / ]
do
    if [ ! -d $i ]; then
        echo $i n existe pas
    fi
    i=`dirname $i`;
done
