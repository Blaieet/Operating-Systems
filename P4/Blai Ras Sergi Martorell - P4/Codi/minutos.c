//autors --> Sergi Matorell Tello i Blai Ras Jimenez

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include "rw_pid.h"

int working= 0;
int segons = -1;
int descriptorPrincipal, pidPrincipal, descriptorHoras, pidHoras;

//mètode per tractar la senyal SIGCONT
void tractarSenyal(int signal) {

        if (signal == SIGCONT) {
		if (segons == -1) {
			segons = 0;
		} else {
			if(segons != 59){
				segons = segons + 1;
			}else{
				segons = 0;
				kill(pidPrincipal, SIGUSR2);
				kill(pidHoras, SIGCONT);
			}
		}
        }
}

//mètode per tractar senyal SIGTERM
void tractarSigterm(int signal) {
	if (signal == SIGTERM) {
		working = 1;
	}
}


int main(void) {

        int pid = getpid();
	char minutos[20] = "minutos.pid";
	write_fitxer(minutos,pid);


	signal (SIGCONT, tractarSenyal);
	signal (SIGTERM, tractarSigterm);

	pause();

	char principal[20] = "principal.pid";
	char hores[20] = "horas.pid";
	pidHoras = read_fitxer(hores);
	pidPrincipal = read_fitxer(principal);

	while(working == 0){
		pause();
	}

        return 0;
}

