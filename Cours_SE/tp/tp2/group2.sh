#!/bin/bash

if [ $(ls | grep "$1" | wc -l) -ne 2 ]; then
    echo "IL y a plus de 2 fichiers contenant ce préfixe !"
    exit 1
fi

contenu_file_1=$(ls | grep "$1" | head -1);
contenu_file_2=$(ls | grep "$1" | tail -1);


cat "$contenu_file_1" "$contenu_file_2" > "tst"
