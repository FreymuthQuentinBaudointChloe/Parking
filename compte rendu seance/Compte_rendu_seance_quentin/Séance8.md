Lors de cette dernière séance, nous avons commencé les branchements de tous les éléments de notre parking (capteurs, servomoteurs, etc...). Nous avons commencé par brancher
les éléments de l'entrée, c'est-à-dire le capteur RFID, le servomoteur et les capteurs infrarouges (voir ci-dessous):

![test](https://user-images.githubusercontent.com/120109320/222730596-22205a65-1504-4649-a50a-7d51fffb3d3e.png)


On a par la suite commencé à brancher le reste de nos capteurs (les mêmes qu'à l'entrée avec en plus les capteurs ultrasons, les LED et l'écran LCD). On s'est cependant rendu compte
que nous avions des problèmes dans le code à cause des delay() que nous avions mis.
On a donc commencé à chercher comment utiliser la fonction millis() pour remplacer les delay() et ainsi éviter les bugs.
Pour la soutenance de la semaine prochaine, il nous reste donc les derniers branchements à faire et du code à modifier.
