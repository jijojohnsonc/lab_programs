#!/bin/bash

read -p "Enter 1st number : " num1
read -p "Enter 2nd number : " num2
read -p "Enter the operation (+, -, *, or /) : " opr
let res=$num1$opr$num2
echo "$num1 $opr $num2 = $res"