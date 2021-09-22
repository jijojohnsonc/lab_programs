#!/bin/bash

read -p "Enter file name : " f_name
if [ -f $f_name ]; then
    read -p "Enter the string to be searched : " s_search
    grep -q $s_search $f_name && echo "String found" || echo "String not found"
else
    echo "File not found"
fi