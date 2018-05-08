#Problema 7
#Author: Blai Ras

#Removing myprog executable file (error if the file doesnt exist)
rm myprog

#Clear all the output in the console
clear

echo "Compiling files.."

gcc -c main2.c -o main2.o
gcc -c calculator.c -o calculator.o
gcc -c counter.c -o count.o

echo "Linking files.."
gcc main2.o calculator.o count.o -o myprog2 -lm

echo "Cleaning files"
rm -f *.o *~
echo "Myprog2 executable created!\nType ./myprog2 + arguments to run it"

