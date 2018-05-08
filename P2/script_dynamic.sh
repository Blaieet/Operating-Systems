#Problema 4
#Author: Blai Ras

echo "Creating .o main file"

gcc -c main.c -o main.o

#1

echo "Creating .o files with fPIC option"

gcc -c -fPIC calculator.c counter.c

echo "Creating the dynamic library"

gcc -shared -o libmyutils.so calculator.o counter.o

echo "Creating the executable with the created library"

gcc main.o -o myprog ./libmyutils.so -lm

echo "Executing"

./myprog
