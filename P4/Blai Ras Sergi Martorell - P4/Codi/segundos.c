//autors --> Sergi Martorell Tello i Blai Ras Jimenez

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include "rw_pid.h"

int ss = -1;
int working;

int descriptorMinuts, pidMinuts, descriptorPrincipal, pidPrincipal;

//mètode per tractar la alarma
void tractarAlarma(int signum){
	//augmentem el contador
	if (ss == 59) {
		ss = 0;
	}
        ss = ss + 1;

	//enviem senyals SIGCONT i SIGUSR1
        kill(pidMinuts, SIGCONT);
        kill(pidPrincipal, SIGUSR1);

	//generem una altre alarma de 1s
	alarm(1);
}

//mètode per tractar la senyal SIGCONT
void tractarSenyal(int signal) {
	if (signal == SIGCONT) {
		//si és el primer cop que entrem iniciem el contador a 0
		if (ss == -1) {
			ss = 0;
		} else {
			//Generem una alarma que enviarà senyal en 1s
			alarm(1);
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
	working =0;
        char segons[20] = "segundos.pid";
        int pid = getpid();
        write_fitxer(segons,pid);

        signal (SIGCONT, tractarSenyal);
        signal (SIGALRM, tractarAlarma);
	signal (SIGTERM, tractarSigterm);

        pause();

        char minuts[20] = "minutos.pid";
        char principal[20] = "principal.pid";

        pidMinuts = read_fitxer(minuts);
        pidPrincipal = read_fitxer(principal);

        while (working == 0) {
                pause();
        }

        return 0;
}

