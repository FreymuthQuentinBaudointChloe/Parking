Compte rendu n°4 :

Aujourd’hui je me suis de nouveau intéressée au capteur RFID. 
Nous avons fait des modifications au niveau du projet global. 
Comme il s’agit s’un parking privé ; il faudra tout d’abord que l’ID du badge soit reconnu auquel cas nous pourront actionner les barrières.Sinon elles resteront fermées. 
J’ai donc modifié le premier code que j’avais fait à la dernière séance et créée un fonction (voir ci-dessous) qui compare les bytes avec un modèle donné. 
Je ne s’avait pas comment comparer les bytes avec une référence. J’ai donc calculé chacun des bytes associé au badge pour pouvoir les comparer. 
  

