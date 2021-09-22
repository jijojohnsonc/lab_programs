#!/bin/bash

head -1 school.dat > school_temp.dat
tail -n +2 school.dat | sort -k 3nr >> school_temp.dat
rm school.dat
mv school_temp.dat school.dat