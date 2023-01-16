Compte rendu n°4 :

Aujourd’hui je me suis de nouveau intéressée au capteur RFID. 
Nous avons fait des modifications au niveau du projet global. 
Comme il s’agit s’un parking privé ; il faudra tout d’abord que l’ID du badge soit reconnu auquel cas nous pourront actionner les barrières.Sinon elles resteront fermées. 
J’ai donc modifié le premier code que j’avais fait à la dernière séance et créée un fonction (voir ci-dessous) qui compare les bytes avec un modèle donné. 
Je ne s’avait pas comment comparer les bytes avec une référence. J’ai donc calculé chacun des bytes associé au badge pour pouvoir les comparer. 

![image](https://user-images.githubusercontent.com/120109320/212725155-5d46dbdc-2ef7-4e73-8136-e5a3be9180cb.png)

J'ai donc mis une condition dans mon programme qui quand on a une réponse positive de la fonction on ouvre la barrière.
Il faudra donc ensuite ajouter le code pour ouvrire la barrière à la place de notre "print("ouvrir la barrière")". 
Et j'ai testé avec un badge qui ne sera pas utilisé par nos voiture, et donc non reconnu par la capteur

![image](https://user-images.githubusercontent.com/120109320/212725943-496ced6a-5925-44c0-90c3-94a7c9e9041b.png)
![image](https://user-images.githubusercontent.com/120109320/212726367-7b5cbc9f-80f6-4b45-8be5-0394118ea769.png)



