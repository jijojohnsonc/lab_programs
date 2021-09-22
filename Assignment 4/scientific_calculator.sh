#!/bin/bash

echo "Enter the arithmetic expression: "
echo -e "Operations:\n+  Addition\t\t-  Subtraction\n*  Multiplication\t/  Division\n%  Modulus\t\t** Exponential"
read exp
echo "Answer: $(awk "BEGIN{print $exp}")"