Compte rendu Séance 1

Nous avons d’abord mis sur papier le schéma de notre parking avec les éléments dont nous avions besoins pour sa construction.


![image](https://user-images.githubusercontent.com/120109320/207105447-f79cc5eb-8227-4680-b3ba-ad3b023a3b0c.png)


Nous avons ensuite pris en main le matériel nécessaire (écran LCD, badge RFID, servomoteur, capteur ultrason, ruban LED…), il nous faudra encore 2 voitures pour notre projet. 
Pour rentrer dans le parking, une voiture doit avoir soit un badge soit une télécommande avec un code unique pour que notre programme le garde en mémoire. Nous avons donc opté pour les badges RFID qui sont encore à tester car le programme n’a pas encore été fait.

Commencement des premiers programmes avec un programme pour les 2 barrières. Programme qui permet pour l’instant d’initialiser la barrière à 0° (vers le haut) et de lever la barrière à 90° (position à plat pour que la voiture passe). 


![image](https://user-images.githubusercontent.com/120109320/207105382-268c2b2f-7591-41e0-ac0b-b00f4675f372.png)



Ce programme a été ensuite testé (voir branchement ci-dessus)

Il faudra donc ajouter un capteur d’ultrason pour que la barrière ne se relève pas sur la voiture, et associer l’ouverture avec les badges RFID. 
