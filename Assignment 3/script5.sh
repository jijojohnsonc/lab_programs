#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Enter two strings as arguments"
else
    test $1 = $2 && echo "The strings are equal." || echo "The strings are not equal."
fi