#autors --> Sergi Martorell Tello i Blai Ras Jimenez

#File: limpiar.sh

#Starting with ./horas
#matem els processos horas, minnutos, segundos i principal

kill $(ps aux | grep horas | grep -v grep | awk '{print $2}')

#Follow with minutos, segundos and finally principal

kill $(ps aux | grep minutos | grep -v grep | awk '{print $2}')

kill $(ps aux | grep segundos | grep -v grep | awk '{print $2}')

kill $(ps aux | grep principal | grep -v grep | awk '{print $2}')

#Last but not least, we remove the .pid files

rm *.pid



