#!/bin/bash

i=`pwd`

while [ $i != / ]
do
    val=`ls $i`;
    i=`dirname $i`
    echo $i
    echo $val
done
echo $i;
echo `ls $i`;

exit 0



