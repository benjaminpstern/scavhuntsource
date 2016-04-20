#!/bin/bash

lineno=1
num=`cat scroll_adjectives | wc -l`
for file in `ls scrolls`:
do
    adj=`sed "${lineno}q;d" scroll_adjectives`
    echo $file ${adj}_scroll
    mv scrolls/$file ${adj}_scroll
    lineno=$((lineno + 1))
    if [ $lineno -ge $num ]
    then
        break
    fi
done
