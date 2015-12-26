int P1LED = 11;    // variable to store the servo position
int P2LED = 5;    // variable to store the servo position
int resultLED = 9;    // variable to store the servo position
int P1Button = 3;    // variable to store the servo position
int P2Button = 2;    // variable to store the servo position

int nOfGames = 4;

bool pressed;

void setup() {
  pinMode(resultLED, OUTPUT);
  pinMode(P2LED, OUTPUT);
  pinMode(P1LED, OUTPUT);
  pinMode(P2Button, INPUT);
  pinMode(P1Button, INPUT);
  pressed = 0;
}

void loop() {
  int count = 0;
  lightRound(3);
  lightsOn();
  delay(1000);
  lightsOff();
  
  for (int i = 0; i < nOfGames; i++){
    delay(random(1000,5000));
    digitalWrite(resultLED, HIGH);
    
    while (!pressed){
      if ( digitalRead(P1Button) == HIGH ){
        digitalWrite(P1LED, HIGH);
        pressed = 1;
        count++;
        delay(1000);
      }
      
      if (( digitalRead(P2Button) == HIGH ) && (!pressed) ){
        digitalWrite(P2LED, HIGH);
        pressed = 1;
        delay(1000);
      }
    }
    lightsOff();
    pressed = 0;
  }
  
  lightsOn();
  delay(300);
  lightsOff();
  delay(300);
  lightsOn();
  delay(300);
  lightsOff();
  delay(300);
  
  lightRound(3);
  lightsOn();
  delay(1000);
  lightsOff();
  
  delay(800);
  
  for (int i = count; i > 0; i--){
    digitalWrite(P1LED, HIGH);
    delay(100);
    digitalWrite(P1LED, LOW);
    delay(800);
  }

  delay(800);
  
  for (int i = nOfGames-count; i > 0; i--){
    digitalWrite(P2LED, HIGH);
    delay(100);
    digitalWrite(P2LED, LOW);
    delay(800);
  }

  lightRound(3);
  lightsOn();
  delay(1000);
  lightsOff();
  
  if ( nOfGames/count == 2){
    while (1){
      digitalWrite(P1LED, HIGH);
      digitalWrite(P2LED, HIGH);
      delay(350);
      digitalWrite(P1LED, LOW);
      digitalWrite(P2LED, LOW);
      delay(350);
    }
  }
  if ( nOfGames/count > 2){
    while (1){
      digitalWrite(P2LED, HIGH);
      delay(350);
      digitalWrite(P2LED, LOW);
      delay(350);
    }
  }
  if ( nOfGames/count < 2){
    while (1){
      digitalWrite(P1LED, HIGH);
      delay(350);
      digitalWrite(P1LED, LOW);
      delay(350);
    }
  }
}

void lightsOn(){
  digitalWrite(P1LED, HIGH);
  digitalWrite(P2LED, HIGH);
  digitalWrite(resultLED, HIGH);
}

void lightRound(int rounds){
  for (int i = 0; i < rounds; i++) {
    delay(150);
    digitalWrite(P1LED, HIGH);
    digitalWrite(P2LED, LOW);
    digitalWrite(resultLED, LOW);
    
    delay(150);
    digitalWrite(P1LED, LOW);
    digitalWrite(P2LED, HIGH);
    digitalWrite(resultLED, LOW);
  
    delay(150);
    digitalWrite(P1LED, LOW);
    digitalWrite(P2LED, LOW);
    digitalWrite(resultLED, HIGH);
  }
  digitalWrite(resultLED, LOW);
}

void lightsOff(){
  digitalWrite(P1LED, LOW);
  digitalWrite(P2LED, LOW);
  digitalWrite(resultLED, LOW);
}

