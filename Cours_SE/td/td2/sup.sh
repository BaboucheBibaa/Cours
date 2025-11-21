#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Deux paramètres uniquement !"
    exit 1
fi

if [[ ! -d $1 && ! -d $2 ]]; then
    echo "IL faut des dossiers comme paramètres"
    exit 1
fi

nb_file1=$(ls -l $1 | wc -l);
nb_file2=$(ls -l $2 |wc -l);

if [ $nb_file1 -eq $nb_file2 ]; then
    echo "dossiers ayant le même nombre d'entrées"
    exit 0
fi

if [ $nb_file1 -gt $nb_file2 ]; then
    echo "$1 contient plus de fichiers que $2"
    exit 0
else
    echo "$2 contient plus de fichiers que $1"
    exit 0
fi