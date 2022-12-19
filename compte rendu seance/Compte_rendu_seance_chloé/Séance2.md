Compte rendu séance 2

Je me suis intéressée aujourd’hui aux capteurs d’ultra son ainsi qu’au ruban LED pour savoir si une voiture est présente sur la place ou non. 
Premièrement, j’ai d’abord fait un programme pour connaître la distance entre le capteur et un objet. 
J’ai vérifié que celui-ci marchait en affichant sur le moniteur les distances (en centimètres) que le capteur récupérait.  
Dans un deuxième temps, je me suis intéressée au ruban LED. 
En récupérant le programme donné par Mr Masson et en le modifiant pour ne prendre que ce qui m’étais utile, j’ai affiché dans premier temps du rouge sur une des 5 LEDS disponibles puis sur deux LEDS et enfin du vert (voir ci-dessous). 

![image](https://user-images.githubusercontent.com/120109320/208505590-347a71f0-b75c-4c80-8512-871a29983a3e.png)






Finalement, j’ai combiné les deux programmes pour n’en faire qu’un seul. 
Il s’agit d’allumer la LED en vert quand la place est libre, ici quand il n’y a pas d’objet sur 8cm (la valeur sera probablement à changer en fonction de la taille de la maquette finale) et s’allume en rouge quand la place est prise donc quand il y a un obstacle sur c’est 8cm. J’ai donc testé le programme pour 1 place. 
La LED est bien rouge quand nous avons un obstacle sur la distance définie(8cm) et est bien verte dans le cas contraire.

Pour notre projet, nous voulons avoir 2 places de parking. 
J’ai donc « dupliqué » mon programme pour le faire pour une deuxième place (j’ai donc utilisé un autre capteur d’ultra-sonde et la dernière LED du ruban de LEDS qui est la 5ème).
J’ai rencontré un problème avec le deuxième capteur puisqu’il m’affichait toujours une distance de 0. 
J’ai donc changé de port pour ECHO et TRIGG mais il ne marchait toujours pas. 
J’ai ensuite échangé mes deux capteurs mais le problème n’était pas résolu. 
Le problème était donc dans le code. En effet, je déclenchais mes deux capteurs en même temps puis récupérais leur durée, or il fallait d’abord déclencher le premier puis récupérer la durée et ensuite faire de même avec le deuxième dû à des problèmes de timer sur la carte Arduino.

Finalement j’obtiens le montage final ainsi que le programme ci-dessous :

![image](https://user-images.githubusercontent.com/120109320/208504808-28dab41f-4c84-4c56-a938-a96c1d834fdb.png)
![image](https://user-images.githubusercontent.com/120109320/208505380-bc29330f-1481-42c9-93f7-a1909b6a0870.png)
![image](https://user-images.githubusercontent.com/120109320/208505409-8ed1bc57-977b-4abd-af73-a623369409ca.png)
![image](https://user-images.githubusercontent.com/120109320/208505446-af283029-8bae-44a0-a9ed-7934f2c98f05.png)











