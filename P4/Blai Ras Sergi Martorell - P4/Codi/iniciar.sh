#autors --> Sergi Martorell Tello i Blai Ras Jimenez

#iniciem els procesos

./segundos &

./minutos &

./horas &

./principal &

#enviem senyal SIGCONT a principal
s=$(ps aux | grep principal | grep -v grep | awk '{print $2}')
kill -s CONT $s

