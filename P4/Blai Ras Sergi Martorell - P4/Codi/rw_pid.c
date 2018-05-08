//autors --> Sergi Martorell Tello i Blai Ras Jimenez

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "rw_pid.h"

//mètode per escriure el pid a un fitxer
void write_fitxer(char nomFitxer[20], int pid) {

	int descriptor;
	descriptor = open(nomFitxer, O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR );
        if (descriptor < 0) {
                write(2,"Error al obrir el fitxer\n",25);
        }

        write(descriptor,&pid,4);
        close(descriptor);
}

//mètode per llegir el pid d'un procés guardat a un fitxer
int read_fitxer(char nomFitxer[20]){
	int descriptor, pidFitxer;
	descriptor=open(nomFitxer,O_RDONLY);
        read(descriptor,&pidFitxer,4);
        close(descriptor);
	return pidFitxer;
}
