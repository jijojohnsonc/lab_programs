#!/bin/bash

read -p "Enter the name : " name
echo $name | rev
echo "Length = ${#name}"