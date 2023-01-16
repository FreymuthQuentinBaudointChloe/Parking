Lors de cette séance j’ai commencé à regarder comment fonctionnait les écrans LCD. 
L’écran LCD que nous avons reçu est donc branché avec un bus I2C. 
J’ai alors par la suite regardé sur Internet comment fonctionnait l’écran LCD lorsqu’il était branché à un bus I2C. 

Une fois le montage réalisé (voir ci-dessous), j’ai commencé à cherché comment on réalisait le code.

![image](https://user-images.githubusercontent.com/120109320/212728672-8d345325-eece-47c7-9f9d-9119b6dcd79c.png)

Une fois que j’avais commencé à regarder comment utiliser les fonctions ARDUINO pour l’écran LCD, j’ai donc essayer d’écrire le programme.
J’avais donc un module à importer, qui se nomme « LiquidCrystal_I2C.h », et qui est nécessaire pour faire fonctionner l’écran LCD I2C. 
Celle-ci m’a posée problème, puisque Arduino ne la reconnaissait pas. Je suis donc allé dans la bibliothèque et téléchargée les modules qui étaient nécessaire. 
Une fois le problème de module réglé, j’ai continué le code, fixés quelques petites choses et l’écran LCD marchait (voir code ci-dessous):

![image](https://user-images.githubusercontent.com/120109320/212728737-d8069048-a351-4283-aa5f-98c44578420f.png)


 On a décidé d’afficher un message « Merci de votre visite », puisque l’écran sera affiché à la sortie de notre parking (voir ci-dessous) :
 
![20230116_170916](https://user-images.githubusercontent.com/120109320/212728793-a1ff0882-5cbd-4f66-9701-0eceae4e84ef.jpg)
