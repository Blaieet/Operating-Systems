#autors --> Sergi Martorell Tello i Blai Ras Jimenez

#enviem senyal SIGALRM per a principal per imprmir el contador
s=$(ps aux | grep principal | grep -v grep | awk '{print $2}')
kill -s ALRM $s

#agafar la hora del sistema i imprimir
hora=$(date | awk '{ print $4}')

echo "System time is:" $hora

