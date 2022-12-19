Compte rendu séance 2

Je me suis intéressée aujourd’hui aux capteurs d’ultrason ainsi qu’au ruban LED pour savoir si une voiture est présente sur la place ou non. 
Premièrement, j’ai d’abord fait un programme pour connaître la distance entre le capteur et un objet. 
J’ai vérifié que celui-ci marchait en affichant sur le moniteur les distances (en centimètres) obtenues. J'ai donc récupéré la durée de l'écho donnée par le capteur puis l'ai converti pour avoir la distance en centimètre. 
Dans un deuxième temps, je me suis intéressée au ruban LED. 
En récupérant le programme donné par Mr Masson et en le modifiant pour ne prendre que ce qui m’étais utile, j’ai affiché d'abord affiché du rouge sur une des 5 LEDS disponibles puis sur deux LEDS et enfin j'ai affiché du vert sur ces mêmes leds (voir ci-dessous). 

![image](https://user-images.githubusercontent.com/120109320/208505590-347a71f0-b75c-4c80-8512-871a29983a3e.png)






Finalement, j’ai combiné les deux programmes pour n’en faire qu’un seul. 
Le but étant d’allumer la LED en vert quand la place est libre, ici quand il n’y a pas d’objet sur 8cm (la valeur sera probablement à changer en fonction de la taille de la maquette finale) et en rouge quand la place est prise donc quand il y a un obstacle sur c’est 8cm. J’ai donc testé le programme pour 1 place. 
La LED est bien rouge quand nous avons un obstacle sur la distance définie(8cm) et est bien verte dans le cas contraire.

Pour notre projet, nous voulons avoir 2 places de parking. 
J’ai donc « dupliqué » mon programme pour le faire pour une deuxième place (j’ai ainsi utilisé un autre capteur d’ultra-son et la dernière LED du ruban de LEDS qui est la 5ème).
J’ai rencontré un problème avec le deuxième capteur, puisque celui-ci m’affichait toujours une distance de 0 et une durée de 20. 
J’ai alors changé de port PIN pour ECHO et TRIGG mais le capteur ne marchait toujours pas. 
J’ai ensuite échangé mes deux capteurs mais le problème n’était pas résolu. 
J'en ai conclu que le problème était donc dans le code. En effet, je déclenchais mes deux capteurs en même temps puis récupérais leur durée, or il fallait d’abord déclencher le premier puis récupérer la durée et ensuite faire de même avec le deuxième capteur dû à des problèmes de timer sur la carte Arduino.

Finalement j’obtiens le montage final ainsi que le programme ci-dessous :

![image](https://user-images.githubusercontent.com/120109320/208504808-28dab41f-4c84-4c56-a938-a96c1d834fdb.png)


Code : 

![image](https://user-images.githubusercontent.com/120109320/208505767-5fb5cce6-dd55-472e-9cb6-899c77660a38.png)

 
![image](https://user-images.githubusercontent.com/120109320/208505843-34022143-b7a6-4956-9db2-46aff478e39c.png)

 
![image](https://user-images.githubusercontent.com/120109320/208505874-da054ec8-69be-4572-9388-94724973df23.png)











