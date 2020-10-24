 

/*

  Tutorial 4 and 6– Game with buzzer signifying wrong answer

 

*/

int currentLED = 3;
int lastLED = 6;
int delayValue = 400;
int buzzerPin = 9;    // Using digital pin 8
#define NOTE_C6  1047
#define NOTE_D6  1175


void setup() {

  // initialize digital pin 12 as input;

  pinMode(12, INPUT);   // button input


  Serial.begin(9600);
  // initialize digital pin 2 to 5 as output:

  pinMode(3, OUTPUT);   // white LED

  pinMode(4, OUTPUT);   // yellow LED

  pinMode(5, OUTPUT);   // green LED

  pinMode(6, OUTPUT);   // red LED

}

 

int checkInput() { 

  if (digitalRead(12) == 0) {

     return 1;

  } else {

    return 0;

  }

}

 

void loop(){

  // Check if the button is press at the right moment

  if (digitalRead(12) == 0) {

     if (currentLED == 5) { 
       tone(buzzerPin, NOTE_C6, 500);
       delay(50);
  
       digitalWrite(5, HIGH);

       delay(200);

       digitalWrite(5, LOW);

       delay(200);

       digitalWrite(5, HIGH);

       delay(200);

       digitalWrite(5, LOW);

       delay(200);

 

// Speed up the LEDs

       delayValue = delayValue - 20; 

 

    } else {

       // Blink the wrong LED
       tone(buzzerPin, NOTE_D6, 500);
       delay(50);

       digitalWrite(currentLED, HIGH);

       delay(200);

       digitalWrite(currentLED, LOW);

       delay(200);

       digitalWrite(currentLED, HIGH);

 

       delay(200);

       digitalWrite(currentLED, LOW);

       delay(200);

    }

  }

  // Loop LED from white –> yellow –> green –> red

  digitalWrite(currentLED, HIGH);

  delay(delayValue);

  digitalWrite(currentLED, LOW);

  delay(delayValue);

  int randLED = 0;
  
  if(400 >= delayValue && delayValue >= 340){
    randLED = rand() % 4 + 3;
    currentLED = randLED;
  }  else if (340 >= delayValue && delayValue >= 280){
    currentLED = currentLED + 1;
    if (currentLED > 6) {
      currentLED = 3;
    }
  } else if(240 >= delayValue && delayValue >= 200){
    randLED = rand() % 4 + 3;
    currentLED = randLED;
  }else if (200 >= delayValue && delayValue >= 140){
    lastLED = lastLED - 1;
    if (lastLED < 3) {
      lastLED = 6;
    }
    currentLED = lastLED;
  } else if (140 >= delayValue && delayValue >= 80){
    currentLED = currentLED + 1;
    if (currentLED > 6) {
      currentLED = 3;
    }
  } else if (80 >= delayValue && delayValue >= 40){
    lastLED = lastLED - 1;
    if (lastLED < 3) {
      lastLED = 6;
    }
    currentLED = lastLED;
  } else {
    currentLED = currentLED + 1;
    if (currentLED > 6) {
      currentLED = 3;
    }
  }
 
  Serial.print(delayValue);
}

 
