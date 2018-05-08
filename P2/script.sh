#Problema 2
#Author: Blai Ras

#!/bin/bash     

#Removing myprog executable file (error if the file doesnt exist)
rm myprog

#Clear all the output in the console
clear

echo "Compiling files.."

gcc -c main.c -o main.o
gcc -c calculator.c -o calculator.o
gcc -c counter.c -o count.o

echo "Linking files.."

gcc main.o calculator.o count.o -o myprog -lm

echo "Cleaning files"
rm -f *.o *~
echo "Executing myprog.."
./myprog
echo "Done!"
