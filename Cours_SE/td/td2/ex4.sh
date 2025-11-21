#!/bin/bash

if [ ! -f /var/spoon/$USER ]; then
    echo "Pas de courrier pour $USER"
    exit 0
else 
    x = 'stat /var/spoon/$USER | grep Acc | tail -1 | cut -d":" -f 2,3,4,5'
    y = 'stat /var/spoon/$USER | grep Cr | tail -1 | cut -d":" -f 2,3,4,5'
    xd = 'echo $x|cut $d" " -f 1'
    xh = 'echo $x|cut $d" " -f 2'
    yh = 'echo $y|cut $d" " -f 2'
    yd = 'echo $y|cut $d" " -f 1'

    if [ $yd == $yx ]; then if [ $xh > $yh ]; then echo "Courrier en retard";
    else echo Nouveau Courrier
    fi
fi