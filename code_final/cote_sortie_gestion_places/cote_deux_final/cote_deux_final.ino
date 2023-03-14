// on inclut les bibliothèques
#include <SPI.h> // SPI
#include <MFRC522.h> // RFID
#include <Servo.h>  // piloter un servomoteur
#include <LiquidCrystal_I2C.h> //écran LCD
#include <Adafruit_NeoPixel.h>

LiquidCrystal_I2C LCD(0x26,16,2); // ici, on définit le type d'écran lcd( qui ici est de 16 pixels de longueur par 2 pixels de hauteur)

//on définit les PIN
//portail d'entrée
#define SS1_PIN 10 
#define RST_PIN 9

//servomoteur
#define servo_moteur_PIN 2 
//capteur proximité
#define capteur_PIN 7
////////////////////////////////////////////////////////////////

//detection infra-rouge
int detection;

// Déclaration du rfid
MFRC522 rfid1(SS1_PIN, RST_PIN);
// on crée l'objet monServo
Servo moteur_barriere; 

// Déclaration du tableau 4 indice pour l'ID
byte ID_badge[4];



//////LED ET UlTRASON
// première place
const int trigPin1 = 5;  // Trigger1
const int echoPin1 = 6;  // Echo1
long duree1;   // durée1 de l'echo
int distance1; // distance1

//deuxième place
const int trigPin2 = 4;  // Trigger2
const int echoPin2 = 3;  // Echo2  
long duree2;   // durée2 de l'echo
int distance2; // distance2

int x =5; //nombre leds sur la bande 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(x, 8, NEO_GRB + NEO_KHZ800);//PIN 8


//variable millis

unsigned long previous_millis=0;


/////////////////////////////////////////////////////////
void setup() 
{ 
  LCD.init(); // on initialise l'afficheur
  LCD.backlight();
  Serial.begin(9600);
  SPI.begin(); 
  rfid1.PCD_Init(); //initialisation du rfid
  pinMode(capteur_PIN, INPUT);
  moteur_barriere.attach(servo_moteur_PIN); // on définit le Pin utilisé par le servomoteur sur la carte
  moteur_barriere.write(120); // initialise le moteur en haut 

    //LED
  pinMode(trigPin1, OUTPUT); // Configuration du port du Trigger comme une SORTIE
  pinMode(echoPin1, INPUT);  // Configuration du port de l'Echo  comme une ENTREE
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);  
  Serial.begin(9600); // Démarrage de la communication série
  strip.begin();
  
  for(int i = 0; i < x; i=i+4 ) { // boucle pour que les LEDS 1 et 5 soient vertes 
          strip.setPixelColor(i, 0, 255, 0);       
      }
  strip.show();
}

void loop() 
{

  Led();
  
  //on attend un badge
  // Si aucun badge n'est présent 
  if ( !rfid1.PICC_IsNewCardPresent())
    return;
  // Vérifier la présence d'un nouveau badge 
  if ( !rfid1.PICC_ReadCardSerial())
  return;
  
  
  // Enregistrer l'ID du badge, on remplit le tableau (4 octets) 
  for (byte i = 0; i < 4; i++) 
  {
    ID_badge[i] = rfid1.uid.uidByte[i];
  }

  
  // Affichage de l'ID 
  Serial.println("Un badge est détecté");
  Serial.println(" L'UID du tag est:");

  
  for (byte i = 0; i < 4; i++) 
  { Serial.print(ID_badge[i], HEX);//HEX fichier
    Serial.print(" ");}
  
  Serial.println();

  if(GetAccesState(ID_badge)){//si le badge est bien associé au parking on ouvre la barrière
    
     LCD.setCursor(5, 0); //On place le curseur sur la première ligne, à la 5ème colonne
     LCD.print("MERCI"); //Puis on affiche ce message
    
     LCD.setCursor(0, 1); // On place le curseur sur la deuxième ligne, à  la colonne 0
     LCD.print("DE VOTRE VISITE"); //Puis on affiche ce message
        

     delay(3000);
     LCD.clear();
    
    for (int position = 120; position <=190; position ++){ // variable position qui prend des valeurs entre 60 et 130 degrés
       moteur_barriere.write(position);  // le bras du servomoteur prend la position de la variable position
       delay(10);  // on attend 10 millisecondes  
    }
    
   
   // Si on détecte une voiture alors que la barrière est descendu 
   delay(2000);
  detection = digitalRead(capteur_PIN);
  Serial.println(detection);
  while (detection == HIGH){//tant qu'une voiture est présente on laisse la barrière en bas (position 130)
    Serial.println("barrière reste en bas");
    moteur_barriere.write(190);
    detection = digitalRead(capteur_PIN);
    }//on met à jour la variable
  

  
  // Si on ne détecte pas de voiture
    Serial.println("barrière peut se lever");
    delay(2000);
    for (int position = 190; position >=120; position --){ //variable position passe de 130 à 60°
        moteur_barriere.write(position);  // le bras du servomoteur prend la position de la variable position
        delay(10);  // le bras du servomoteur prend la position de la variable position
    }
}
  if (!GetAccesState(ID_badge))
    Serial.println("barrière reste fermé");
  
  // Réinitialise le RFID
  rfid1.PICC_HaltA(); // Halt PICC
  rfid1.PCD_StopCrypto1(); // Stop encryption on PCD
}

//fonction qui compare les 2 ID et retourne true si elles sont identiques et false sinon
byte GetAccesState(byte*CodeAcces) 
{ 
  //on vérfie chaque byte de l'ID du badge
  if (
    (String(CodeAcces[0])=="233" || (String(CodeAcces[0])=="18"))&&
    (String(CodeAcces[1])=="209" || (String(CodeAcces[1])=="229"))&&
  (String(CodeAcces[2])=="119" || (String(CodeAcces[2])=="162"))&& 
  (String(CodeAcces[3])=="193") || (String(CodeAcces[3])=="52"))

  //si il est valide on retourne true
    return true; 
  else
  //sinon false
    return false;
}

//fonction qui allume les LEDS en fonction de si un objet est présent ou non
void Led(){
  // Émission d'un signal de durée 10 microsecondes premier capteur 
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  //on stocke la durée/écoute l'écho 
  duree1 = pulseIn(echoPin1, HIGH);
  delay(1);
  
  // Émission d'un signal de durée 10 microsecondes deuxième capteur 
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  //on sotck la durée
  duree2 = pulseIn(echoPin2, HIGH);
  
  // Calcul de la distance
  distance1 = duree1*0.034/2;
  distance2 = duree2*0.034/2;
  //on allume les leds verte ou rouge en fonction de la distance obtenue
 if(distance1<=8){
  strip.setPixelColor(0, 255, 0, 0);
  strip.show(); 
  } 
 if(distance1>8){
  strip.setPixelColor(0, 0, 255, 0);
  strip.show(); 
  }
 if(distance2<=8){
  strip.setPixelColor(4, 255, 0, 0);
  strip.show(); 
  }
 if(distance2>8){
  strip.setPixelColor(4, 0, 255, 0);
  strip.show(); 
  }
  delay(1000);
}
