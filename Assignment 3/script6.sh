#!/bin/bash

echo "No. of parameters passed = $#"
if [ $# -eq 1 ]; then
    if [ -f $1 ]; then
        echo "$1 exists"
    else
        echo "$1 doesn't exist"
    fi
elif [ $# -eq 2 ]; then
    if [ -f $1 ]; then
        mv $1 $2
        echo "$1 renamed as $2"
    else
        echo "$1 doesn't exist"
    fi
fi