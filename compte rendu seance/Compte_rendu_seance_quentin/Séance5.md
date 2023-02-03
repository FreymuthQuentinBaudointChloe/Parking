Lors de la séance précédente, les professeurs nous avait donné deux capteurs de proximité infrarouge, qu’ils ont jugé plus utile pour notre projet que les capteurs ultrasons 
(pour détecter si une voiture se trouve au-dessus de la barrière). 

Lors de cette séance, j’ai donc regardé comment ils fonctionnaient et j’ai donc fait les branchements nécessaire (voir photo ci-dessous) et le code qui va avec:

![image](https://user-images.githubusercontent.com/120109320/216586010-f7632ac3-8397-4b26-b945-b9e0643684ae.png)


Nous avons donc mis les deux capteurs, l’un en face de l’autre, en cachant (à l’aide de scotch noir) un émetteur sur l’un et un récepteur sur l’autre de manière à n’avoir qu’une « seule » barrière de photon. 
Le programme permet ensuite de détecter si la barrière de photon est intacte (renvoie LOW) ou si elle est coupé par un objet (renvoie HIGH). 
Cela permettra donc d’éviter de relever la barrière de notre parking sur la voiture.

J’ai ensuite compté le nombre d’entrées/sorties qui seront nécessaire pour l’ensemble de nos objets (capteurs, écran LCD, servomoteurs, etc…). 
Cela porte ainsi ce nombre à 30. Nous devrons donc sans doute utiliser deux plaques Arduino Uno.

Par la suite, Chloé s’est occupé de relier le programme du capteur RFID avec celui du servomoteur et celui des capteurs de proximité infrarouge, et je l’ai aidé dans les branchements. 
Après, nous avons réglé à deux plusieurs petits problèmes qui étaient survenus dans le code à cause de nos délais.
