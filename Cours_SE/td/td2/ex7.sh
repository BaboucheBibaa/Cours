#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Au moins un paramètre requis"
    exit 1
fi

i=1
val=$1
while [ "$i" -ne "$(($#+1))" ]
do
    current=${!i}
    if [ "$current" -lt  "$val" ]; then
        val=$current
    fi
    i=$((i+1))
done

echo "Minimum : $val"