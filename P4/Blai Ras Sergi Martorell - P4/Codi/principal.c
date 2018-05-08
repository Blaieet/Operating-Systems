//autors --> Sergi Martorell Tello i Blai Ras Jimenez

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include "rw_pid.h"

#define SIZE 100
int len, working, pidSegons, pidMinuts, pidHores, activat;
activat = 0;
int hh, mm, ss;
char buffer[SIZE];
char buffer2[SIZE];
int times = 0;
working = 0;

//mètode per tractar la senyal SIGTERM
void tractarSenyalTerm(int senyal) {
	times = times+1;
	if (senyal == SIGTERM) {
		char segundos[20] = "segundos.pid";
                char minutos[20] = "minutos.pid";
                char horas[20] = "horas.pid";

		//llegim els pids dels processos de segons, minuts i hores
		int pidSegons = read_fitxer(segundos);
                int pidMinuts = read_fitxer(minutos);
                int pidHores = read_fitxer(horas);

		//enviem senyal SIGTERM als processos per matar-los
		kill(pidSegons,SIGTERM);
                kill(pidMinuts,SIGTERM);
                kill(pidHores,SIGTERM);

		//Imprimim el temps final del contador amb la funció write per sortida estàndart
		sprintf(buffer,"Timer stopped at: %02d:%02d:%02d\n", hh, mm, ss);
                len = strlen(buffer);
                write(1, buffer, len);

		//Imprimim la hora del sistema
		time_t current;
		char* timeString;
		current = time(NULL);
		timeString=ctime(&current);

		sprintf(buffer2, "System time is: %s\n", timeString);
		len = strlen(buffer2);
		write(1,buffer2,len);

		working = 1;

	}

}

//mètode per tractar les senyals SIGUSR1 i SIGUSR2
void tractarSenyalsSigusr(int senyal){
	//si la senyal és SIGUSR1, vol dir que arriba de segons
	//i hem d'anar incrementant el contador de segons
	 if(senyal == SIGUSR1){
		if(ss != 59){
			ss = ss + 1;
		}else{
			ss = 0;
		}
	//si la senyal és SIGUSR2, vol dir que arriba de minuts
	//i hem d'anar augmentant el contador de minuts
	} else if (senyal == SIGUSR2) {
		if(mm != 59){
                        mm = mm + 1;
                }else{
                        mm = 0;
                }
	}
}

//mètode per tractar la senyal SIGCONT
void tractarSenyal(int senyal) {
        char text;
        int longitud, descriptorSegons, descriptorMinuts, descriptorHores, pidSegons, pidMinuts, pidHores;
        if (senyal == SIGCONT) {
		//Si activat és 0
                if (activat == 0) {
			//és el primer cop que rebem la senyal SIGCONT per tant llegim els pids dels processos
			char segundos[20] = "segundos.pid";
			char minutos[20] = "minutos.pid";
			char horas[20] = "horas.pid";
                        pidSegons = read_fitxer(segundos);
                        pidMinuts = read_fitxer(minutos);
                        pidHores = read_fitxer(horas);

			//enviem senyal SIGCONT als processos per inicialitzar els contadors a 0
			kill(pidSegons, SIGCONT);
                        kill(pidMinuts, SIGCONT);
                        kill(pidHores, SIGCONT);

			activat = activat+1;
		} else {
			//si activat és 1
			if (activat == 1) {
				//enviem la senyal SIGCONT als processos per iniciar el contador
				kill(pidSegons, SIGCONT);
				kill(pidMinuts, SIGCONT);
				kill(pidHores, SIGCONT);
				activat = activat+1;
			} else {
			//si activat és 2, vol dir que hem rebut la senyal de hores i hem d'augmentar el contador
                        	if(hh != 23){
                                	hh = hh + 1;
                        	}else{
                                	hh = 0;
				}
                        }
                }
        }
}

//mètode per tractar la senyal SIGALRM
void tractarSenyalAlarma(int senyal){
        if(senyal == SIGALRM){
		//imprimim el contador
                sprintf(buffer, "%02d:%02d:%02d\n", hh, mm, ss);
                len = strlen(buffer);
                write(1, buffer, len);
        }
}


int main(void){

	ss = 0;
        mm = 0;
        hh = 0;

	//Imprimim l'estat inicial del contador
        sprintf(buffer, "%02d:%02d:%02d\n", hh, mm, ss);
        len = strlen(buffer);
        write(1, buffer, len);

	//escrivim el pid de principal a un fitxer
        char principal[20]="principal.pid";
        int pid;
        pid = getpid();
        write_fitxer(principal,pid);

	//imprimim el pid de principal
        sprintf(buffer, "PID P: %d\n", pid);
        len = strlen(buffer);
        write(1, buffer, len);

	//assignem cada senyal amb el seu mètode corresponent
        signal(SIGCONT, tractarSenyal);
        signal(SIGUSR1, tractarSenyalsSigusr);
        signal(SIGUSR2, tractarSenyalsSigusr);
        signal(SIGALRM, tractarSenyalAlarma);
	signal(SIGTERM, tractarSenyalTerm);

        while(working == 0) {
                pause();
        }

        return 0;
}


