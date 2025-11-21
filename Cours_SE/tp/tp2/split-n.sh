#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <fichier> <nombre_de_parties>"
    exit 1
fi

if [ ! -f "$1" ]; then
    echo "Erreur : '$1' n'est pas un fichier."
    exit 1
fi

if ! [[ "$2" =~ ^[0-9]+$ ]]; then
    echo "Erreur : '$2' n'est pas un entier positif."
    exit 1
fi


rm -f split-n.sh.sp*
fichier="$1"
n="$2"
name=$(basename "$0")
nb_carac=$(wc -c < "$fichier")
part_size=$(( nb_carac / n ))
reste=$(( nb_carac % n ))

cp "$fichier" "temp.txt"

for ((i=1; i<=n; i++)); 
do
    taille=$part_size

    if [ $i -le $reste ]; then
        taille=$((taille + 1))
    fi
    echo "$n $fichier" >> "$name.sp${i}"

    # taille premiers octets du fichier de base stockés dans temp.txt
    head -c "$taille" "temp.txt" >> "${name}.sp${i}"

    # on les retire pour changer le head au prochain tour de boucle et on déplace dans un 2eme fichier temp
    tail -c +$((taille + 1)) "temp.txt" > "temp_rest.txt"
    # écraser le fichier temp 
    mv "temp_rest.txt" "temp.txt"
done

rm -f "temp.txt"

echo "Découpage terminé !"
