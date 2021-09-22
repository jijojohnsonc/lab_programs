#!/bin/bash

read -p "Enter the value of n : " n
if [ $n -lt 0 ]; then
    echo "Enter a positive integer (or zero)"
else
    let sum=0
    while [ $n -ne 0 ]
    do
    let sum=$sum+$n
    let n=$n-1
    done
    echo "Sum = $sum"
fi