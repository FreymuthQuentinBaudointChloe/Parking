// on inclut les bibliothèques
#include <SPI.h> // SPI
#include <MFRC522.h> // RFID
#include <Servo.h>  // piloter un servomoteur


//on définit les PIN
//portail d'entrée
#define SS1_PIN 10 
#define RST_PIN 9

//servomoteur
#define servo_moteur_PIN 4 
//capteur proximité
#define capteur_PIN 3
////////////////////////////////////////////////////////////////

//detection infra-rouge
int detection;

// Déclaration du rfid
MFRC522 rfid1(SS1_PIN, RST_PIN);
// on crée l'objet monServo
Servo moteur_barriere; 

// Déclaration du tableau 4 indice pour l'ID
byte ID_badge[4];

/////////////////////////////////////////////////////////
void setup() 
{ 
  Serial.begin(9600);
  SPI.begin(); 
  rfid1.PCD_Init(); //initialisation du rfid
  pinMode(capteur_PIN, INPUT);
  moteur_barriere.attach(servo_moteur_PIN); // on définit le Pin utilisé par le servomoteur sur la carte
  moteur_barriere.write(30); // initialise le moteur en haut 
}

void loop() 
{
  
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
    for (int position = 30; position <=100; position ++){ // variable position qui prend des valeurs entre 60 et 130 degrés
       moteur_barriere.write(position);  // le bras du servomoteur prend la position de la variable position
       delay(10);  // on attend 10 millisecondes  
    }
    
   
   // Si on détecte une voiture alors que la barrière est descendu 
   delay(2000);
  detection = digitalRead(capteur_PIN);
  while (detection == HIGH){//tant qu'une voiture est présente on laisse la barrière en bas (position 130)
    Serial.println("barrière reste en bas");
    moteur_barriere.write(100);
    detection = digitalRead(capteur_PIN);
    }//on met à jour la variable
  

  
  // Si on ne détecte pas de voiture
    Serial.println("barrière peut se lever");
    delay(2000);
    for (int position = 100; position >=30; position --){ //variable position passe de 130 à 60°
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
