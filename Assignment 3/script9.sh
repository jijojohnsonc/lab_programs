#!/bin/bash

if [ $# -eq 3 ]; then
    if [ -f $1 ] && [ -f $2 ]; then
        head $1 > $3
        head $2 >> $3
    elif [ -f $1 ]; then
        echo "$2 doesn't exist"
    else
        echo "$1 doesn't exist"
    fi
else
    echo "Invalid argument(s)"
fi