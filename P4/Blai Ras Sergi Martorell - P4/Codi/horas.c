//autors --> Sergi Martorell Tello i Blai Ras Jimenez

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include "rw_pid.h"

int minuts; //variable per saber quants minuts portem
int working = 0;
int descriptorPrincipal, pidPrincipal;

//mètode per tractar la senyal SIGCONT
void tractarSenyal(int signal) {
        if (signal == SIGCONT) {
		//si minuts és -1, vol dir que és el primer cop que rebem aquesta senyal
		if (minuts == -1) {
			//iniciem el contador a 0
			minuts = 0;
		}else {
		//si minuts és diferent de 59, incrementem el contador
                	if(minuts != 59){
				minuts = minuts + 1;
			//si el contador arriba a 59
			}else{
				//reiniciem el contador i enviem una senyal SIGCONT a principal
				minuts = 0;
				kill(pidPrincipal, SIGCONT);
			}
        	}
	}
}

//mètode per tractar la senyal SIGTERM
void tractarSigterm(int signal) {
	//posem working a 1 per acabar el procés netament
	if (signal == SIGTERM) {
		working = 1;
	}
}

int main(void) {

	minuts = -1;
	//agafem el pid de horas.c
        int pid = getpid();
	char horas[20] = "horas.pid";
	//escrivim el pid a un fitxer
	write_fitxer(horas,pid);

	//assignem les següents senyals amb els mètodes corresponents
	signal(SIGCONT, tractarSenyal);
	signal(SIGTERM, tractarSigterm);

	pause();

	//llegim el pid de principal del fitxer principal.pid
	char principal[20] = "principal.pid";
	pidPrincipal = read_fitxer(principal);

	while(working == 0){
		pause();
	}

        return 0;
}

