#!/bin/bash

let flag=0
while [ $flag -ne 1 ]
do
    echo "Enter your choice (1-7 - Display the corresponding day, 0 - Exit)"
    read -p ": " c
    case $c in
        1) echo "Sunday" ;;
        2) echo "Monday" ;;
        3) echo "Tuesday" ;;
        4) echo "Wednesday" ;;
        5) echo "Thursday" ;;
        6) echo "Friday" ;;
        7) echo "Saturday" ;;
        0) let flag=1 ;;
        *) echo "Invalid choice!" ;;
    esac
done