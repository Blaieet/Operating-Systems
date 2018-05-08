#Autors --> Sergi Martorell Tello i Blai Ras Jimenez

#mirem tots els processos que s'estan executant
#agafem el procés de principal
#del procés de principal agafem el pid (segona columna)
#i enviem una senyal SIGTERM a principal

s=$(ps aux | grep principal | grep -v grep | awk '{print $2}')
kill -s TERM $s

