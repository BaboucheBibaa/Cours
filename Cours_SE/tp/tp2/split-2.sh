#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Il faut uniquement un paramètre (un fichier)";
    exit 1
fi

if [ ! -e "$0" ]; then 
    echo "Le fichier n'existe pas !"
    exit 1
fi

if [ -d "$1" ]; then
    echo "Le fichier ne peut être un répertoire"
    exit 1
fi

if [ ! -s "$1" ]; then
    echo "Le fichier est vide"
    exit 1
fi

name=$(basename $0);
nb_carac=$(wc -c < "$1");
nb_moitie_carac=$(($nb_carac/2))
if [ $(($nb_carac % 2)) -ne 0 ]; then
    moitie_inferieure=$(head -c $(($nb_moitie_carac)) $1);
    moitie_superieure=$(tail -c $(($nb_moitie_carac+1)) $1);
    cat <<< "$moitie_inferieure" > $name.sp1;
    cat <<< "$moitie_superieure" > $name.sp2;
    echo $nb_carac;
    echo $(($nb_carac/2));
    exit 0
fi

moitie_inferieure=$(head -c $(($nb_carac/2)) $1);
moitie_superieure=$(tail -c $(($nb_carac/2)) $1);
cat <<< "$moitie_inferieure" > $name.sp1;
cat <<< "$moitie_superieure" > $name.sp2;
exit 0



