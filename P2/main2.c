//Problema 7
//Author: Blai Ras

//Includes

#include "calculator.h"
#include "counter.h"
#include <stdio.h>
#include <string.h> //For strcmp function
#include <stdlib.h> //For atoi function

int main(int argc, char *argv[]) {

	//Check if theres arguments
	if (argc == 0) {
		printf("You forgot the arguments!\n");
		exit(0);
	} else {
		int i;

		//For every argument
		for (i = 1; i < argc; i ++) {
			printf("Argument: %s\n",argv[i]);

			//If its an "-e"
			if (strcmp(argv[i],"-e")==0){

				//Do the Euclidean distance
				printf("Euclidean Distance: %f\n", euclideanDistance(atoi(argv[i+1]), atoi(argv[i+2]), atoi(argv[i+3]), atoi(argv[i+4])));

				//Move 4 arguments just in case there are more arguments
				i = i+4;

			//If its an "-m"
			}else if (strcmp(argv[i],"-m")==0){

				//Do the Manhattan distance
				printf("Manhattan Distance: %f\n", manhattanDistance(atoi(argv[i+1]), atoi(argv[i+2]), atoi(argv[i+3]), atoi(argv[i+4])));

				//Move 4 positions to catch another argument
				i = i+4;

			//If its an "-w"
			}else if (strcmp(argv[i],"-w")==0){

				//Count the words
				printf("Number of words of the sentence: %d\n", countWords(argv[i+1]));		

				//Now move only 1 position (the sentence)
				i++;

			//If its and "-o"
			}else if (strcmp(argv[i],"-o")==0){

				//Count how many times the char repeats.
				printf("Number of ocurrences: %d\n", countOccurrences(argv[i+1],argv[i+2][0]));

				//Move 2 positions, the sentence and the char
				i = i+2;
			}else{

				//Error
				printf("Unknow command! Quitting...\n");
				exit(0);
			}
		}
	}
	return 0;
}
