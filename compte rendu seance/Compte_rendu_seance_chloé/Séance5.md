Compte rendu séance 5

Aujourd’hui nous avons décidé de commencer à relier les programmes entre eux.

Le but étant lors de cette séance de commander la première barrière d’entrée. 
J’ai donc relié 3 programmes entre eux : celui qui gère l’accès au parking grâce au badge RFID, celui qui baisse et monte la barrière avec le servomoteur et celui qui détecte la présence d’une voiture avec les capteurs de proximité ultra-son.

J’ai donc tout d’abord relié le programme d’accès avec le programme de la gestion des barrières : le but est de lever la barrière si le badge d’accès est détecté et reconnu par le capteur. 
La principale modification est donc dans la loop. (Voir ci-dessous). 
Après avoir effectué les branchements, les deux programmes ensembles marchaient : on avait bien la barrière qui descendait lors du passage du badge.

![image](https://user-images.githubusercontent.com/120109320/216581908-5f539ef8-0ba1-4ee1-8cea-ab009c9d5792.png)


J’ai donc ensuite relié le code des avec les capteurs de proximité ultra-son pour bloquer la barrière si une voiture se trouve au-dessus de la barrière. 
J’ai rencontré des problèmes lors de se programme et ai donc demander de l’aide à Quentin. 
Il s’agissait finalement de problème lié à certains délais. J’ai pu ainsi finir le programme en ajoutant les conditions nécessaires pour relever correctement la barrière. 
Finalement après avoir tester plusieurs fois, le code fonctionne correctement : la barrière descend au passage du badge, ne remonte pas si la voiture est encore au-dessus de celle-ci, puis remonte quand la voiture est passée.
Dans le programme ci-dessous, on déclare d'abord toutes les variables nécessaires ainsi que les biblihotèques.


![image](https://user-images.githubusercontent.com/120109320/216586985-f754666f-241b-48f4-881b-5018ad5a2c50.png)

Puis on initialise les éléments nécessaires au programme.


![image](https://user-images.githubusercontent.com/120109320/216587061-9e404893-f070-4c84-87d2-e0b6d85f03e5.png)

Une fois que le badge est détecté et que la barrière est descendue, les capteurs de proximité vont pourvoir nous dire si la voiture est toujours présente ou non. 
Tant que la réponse est positive, la barrière est en bas ; quand la réponse devient négative on peut remonter la barrière.


![image](https://user-images.githubusercontent.com/120109320/216587247-740473f4-b9df-4d1b-b2d4-7c30a8769791.png)

