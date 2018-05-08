#Problema 6
#Author: Blai Ras

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)

default: myprog

# To create the executable file myprog we need the object files
# main.o, calculator.o, counter.o:

#myprog: target
#main.o, calculator.o, counter.o : dependencies
# <tab> : command

myprog: main.o calculator.o counter.o 
	gcc main.o calculator.o counter.o -o myprog -lm
	

# Creating object files
#Program goes here cause he's searching for the main.o file
main.o: main.c  
	gcc -c main.c

#Now it goes here for the calculator.o file
calculator.o: calculator.c
	gcc -c calculator.c

#And finally here for the counter.o file. Afterwards, he goes to the command
counter.o: counter.c
	gcc -c counter.c


# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) myprog *.o *~

