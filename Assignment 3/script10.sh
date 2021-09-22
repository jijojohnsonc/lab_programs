#!/bin/bash

read -p "Enter the character : " ch
let count=$(ls | grep -c ^$ch)
echo "No. of files beginning with $ch = $count"