#!/bin/bash

# Vérifier le préfixe
if [ $(ls split-n.sh.${1}* 2>/dev/null | wc -l) -eq 0 ]; then
    echo "Aucun fichier possède ce préfixe !"
    exit 1
fi

> temp.txt

nb_divisions=$(head -n 1 split-n.sh.${1}1 | cut -d' ' -f1)
nom_fichier=$(head -n 1 split-n.sh.${1}1 | cut -d' ' -f2)

cp "split-n.sh.${1}1" temp.txt

for ((i=2; i<=nb_divisions; i++)); do
    tail -n +2 "split-n.sh.${1}${i}" >> temp.txt
done

# Copier le résultat final
cp temp.txt "$nom_fichier"

# Nettoyage
rm temp.txt

echo "✅ Fichier recomposé dans '$nom_fichier'"
