#autors --> Sergi Martorell Tello i Blai Ras Jimenez

#fitxer per crear els executables
default: principal segundos minutos horas

principal: principal.o rw_pid.o
	gcc principal.o rw_pid.o -o principal

segundos: segundos.o rw_pid.o
	gcc segundos.o rw_pid.o -o segundos

minutos: minutos.o rw_pid.o
	gcc minutos.o rw_pid.o -o minutos

horas: horas.o rw_pid.o
	gcc horas.o rw_pid.o -o horas

principal.o: principal.c
	gcc -c principal.c

segundos.o: segundos.c
	gcc -c segundos.c

minutos.o: minutos.c
	gcc -c minutos.c

horas.o: horas.c
	gcc -c horas.c

rw_pid.o: rw_pid.c
	gcc -c rw_pid.c

clean:
	rm *.o principal horas segundos minutos 

