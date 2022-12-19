Séance 2: Compte-rendu

Lors de la séance précédente, j'avais effectué le programme qui permet d'actionner la levée et la descente de la barrière grâce au servomoteur. 

Donc, lors de cette séance, j’ai géré le capteur ultrason qui sera situé en face de la barrière et qui permettra de lever la barrière seulement s’il n’y a pas d’objet à une certaine distance (ici, cela permettra de ne pas relever la barrière si la voiture se trouve en dessous).

J’ai donc fait le programme qui permet au capteur ultrason de renvoyer la distance entre lui et l’objet se situant devant lui le plus proche. Une fois le programme réalisé, j’ai voulu tester le programme, mais j’avais des problèmes de ports avec mon ordinateur.

J’ai donc chercher plusieurs choses qui pouvaient en être la cause. Et finalement c’était la mise à jour Windows que j’avais faite qui avait fait dysfonctionné mes ports. J’ai donc du réaliser une autre mise à jour qui à cette fois-ci refait fonctionner mes ports. 

Une fois mes ports fonctionnels, j’ai pu tester mon programme du capteur ultrason et celui-ci fonctionnait et renvoyait bien la distance avec l’objet le plus proche.
J’ai ensuite réalisé un montage avec le capteur ultrason et le servomoteur de la semaine passée (voir ci-dessous) :




![image](https://user-images.githubusercontent.com/120109320/208505806-1fb88b35-56ee-4efd-98be-d0dee16415af.png)




J’ai ensuite écrit un programme qui permet de descendre la barrière, puis de la garder en bas, tant qu’une voiture se situe en dessous, et de la relever seulement lorsque la voiture est passée. J’ai donc fait des conditions (if et while) avec la distance que renvoie le capteur ultrason pour remonter ou non la barrière. 

J’ai cependant eu des problèmes avec une de mes boucles for qui permettait de faire remonter la barrière progressivement. En effet, celle-ci faisait buggé mes conditions et je n’ai pas réussi à savoir pourquoi. 

J’ai donc décidé de supprimer cette boucle, et mettre directement la position de la barrière « en haut » (position pour laquelle la voiture ne peut pas passer), et cela a donc fonctionné. 


