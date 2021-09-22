#!/bin/bash

read -p "Enter the file name : " f1
if [ -f $f1 ]; then
    read -p "Enter the new file name : " f2
    cat $f1 | tr 'aeiou' 'AEIOU' > $f2
else
    echo "$f1 doesn't exist"
fi