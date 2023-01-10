Compte rendu séance 3 :

Durant cette séance je me suis intéressée au module RFID pour contrôler l’accès au parking. 
Le but étant de rentrer dans le parking avec un badge ou une carte que l’on présente à un premier lecteur RFID et, suite à cela, ouvrir la barrière. 
Il suffit ensuite de sortir en passant de nouveau son badge/carte sur un lecteur à la sortie pour avoir le temps de stationnement et pouvoir encore une fois ouvrir la barrière de sortie.
J’ai d’abord modifié un programme, pour n’avoir que ce dont j’avais besoin. 
Je voulais tout d’abord pouvoir récupérer l’ID du badge et l’afficher sur le moniteur. 
J’ai donc fait le montage nécessaire pour un seul module RFID, et mon binôme à souder les pattes du lecteur pendant que je commençais les dimensions de notre Parking. 

![image](https://user-images.githubusercontent.com/120109320/211363491-8fdb849d-07b6-4105-a43b-86c011e13d03.png)


Dans le code (voir ci-dessous) du RFID on définit d’abord le PIN pour le select (reconnaître le rfid) et le rest. 
Suite à cela, on va traiter les « erreurs » : si il n’y a pas de badge présent on ne doit rien renvoyer. 
Sinon on passe à la lecture du badge avec une boucle pour récupérer l’ID et pour l’afficher. 
J’ai testé ensuite le code avec le badge puis la carte, j’ai pu constater qu’il n’avait pas la même ID. 
Il ne sera donc pas nécessaire d’avoir un autre jeu de badge/carte care nous voulons avoir seulement 2 voitures. 
 
 ![image](https://user-images.githubusercontent.com/120109320/211363551-81f25bd7-9cf4-45f7-8ecd-dfd0d32234f8.png)


Je voulais ensuite brancher un deuxième module pour le portail de sortie. Après avoir appris qu’il s’agissait d’une disposition en bus. 
J’ai pu brancher le second lecteur. Mais mon programme ne marchait plus, j’ai vérifié les branchements, je pense que l’erreur doit être dans le code. 
Je n’ai pas pu résoudre l’erreur durant cette séance car durant la séance, j’ai aussi aidé à coller la « boîte »  que Quentin avait découpé et qui servira de sol pour le Parking mais aussi de cache pour les différents éléments(voir ci-dessous).

![image](https://user-images.githubusercontent.com/120109320/211363580-8a71fbf2-ae94-467c-ab85-6d472e81852a.png)
