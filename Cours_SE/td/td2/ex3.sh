#!/bin/bash

if [ $# -ne 2 ]; then
    exit 2
fi

if [ "$1" -gt "$2" ]; then
    echo "$1"
else
    echo "$2"
fi
