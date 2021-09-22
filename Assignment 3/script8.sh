#!/bin/bash

read -p "Enter file 1 : " file1
if [ -f $file1 ]; then
    read -p "Enter file 2 : " file2
    cat $file1 >> $file2
else
    echo "File not found"
fi