Compte rendu n°4 :

Aujourd’hui je me suis de nouveau intéressée au capteur RFID. 
Nous avons fait des modifications au niveau du projet global. 
Comme il s’agit s’un parking privé ; il faudra tout d’abord que l’ID du badge soit reconnu auquel cas nous pourront actionner les barrières.Sinon elles resteront fermées. 
J’ai donc modifié le premier code que j’avais fait à la dernière séance et créée un fonction (voir ci-dessous) qui compare les bytes avec un modèle donné. 
Je ne s’avait pas comment comparer les bytes avec une référence. J’ai donc calculé chacun des bytes associé au badge pour pouvoir les comparer. 

![image](https://user-images.githubusercontent.com/120109320/212728468-1ed93b73-0164-4c25-be57-37478cad50dc.png)

J'ai donc mis une condition dans mon programme qui, quand on a une réponse positive de la fonction va permettre d'ouvrire la barrière.
Il faudra donc ensuite ajouter le code pour ouvrire la barrière à la place de notre "print("ouvrir la barrière")". 
Et j'ai testé avec un badge qui ne sera pas utilisé par nos voitures, et donc non reconnu par le capteur.

![image](https://user-images.githubusercontent.com/120109320/212725943-496ced6a-5925-44c0-90c3-94a7c9e9041b.png)
![image](https://user-images.githubusercontent.com/120109320/212726512-6752e176-4767-462e-81de-f1e7461554a9.png)

Suite à l'oral, on nous a conseillé de ne pas utiliser de capteur ultrason au niveau de la barrière. Initialement, nous voulions vérifier si aucun objet n'était présent au-dessus de la barrière avec la distance que le capteur nous rendrait. Nous allons donc opter pour des capteurs infrarouges, situés des deux cotés de la barrière. Ils seront plus fiable pour notre projet.

![image](https://user-images.githubusercontent.com/120109320/212728124-148f9c29-0068-444e-9afe-c507471fe8da.png)


J'ai donc repris le code de Quentin sur les barrières, mais je n'arrive pas encore à brancher correctement les deux capteurs. 

