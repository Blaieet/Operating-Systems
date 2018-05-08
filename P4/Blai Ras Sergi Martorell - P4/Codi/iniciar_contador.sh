#autors --> Sergi Martorell Tello i Blai Ras Jimenez

#enviem senyal SIGCONT a principal
s=$(ps aux | grep principal | grep -v grep | awk '{print $2}')
kill -s CONT $s

#agafem la hora del sistema
hora=$(date | awk '{ print $4}')

echo "Timer started at:" $hora

