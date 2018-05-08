#Problema 3
#Author: Blai Ras

#!/bin/bash     

#Removing myprog file (error if theres no myprog file)

rm myprog

echo "Compiling files.."

gcc -c counter.c -o counter.o
gcc -c main.c -o main.o
gcc -c calculator.c -o calculator.o

#1

echo "Creating the static library"

ar rcs libmyutils.a calculator.o counter.o

echo "Building the executable with the created library"

gcc main.o -o myprog libmyutils.a -lm

echo "Executing"

./myprog
