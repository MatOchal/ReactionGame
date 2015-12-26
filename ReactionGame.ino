int P1LED = 11;     // Player 1's LED    
int P2LED = 5;      // Player 2's LED
int resultLED = 9;  // result/reaction LED
int P1Button = 3;   // Player 1's button
int P2Button = 2;   // Player 1's button

int nOfGames = 4;   // Number of games before a round ends

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

  // Intro
  lightsShine(3);
  lightsBlink(1, 800);

  // Game Start
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

  // End of Game
  lightsBlink(1, 300);
  lightsShine(3);
  lightsBlink(1, 800);

  // Show Scores
  lightBlink(nOfGames-count, P1LED);
  delay(800);
  lightBlink(nOfGames-count, P2LED);

  lightsShine(3);
  lightsBlink(1, 800);

  // Blink for Winner
  if ( nOfGames/count == 2){
    lightBlink(6, P1LED, nOfGames-count);
  } else if ( nOfGames/count > 2){
    lightBlink(6, P2LED);
  } else if ( nOfGames/count < 2){
    lightsBlink(6);
  }
}

void lightBlink(int pin, int cycles){
  lightBlink(pin, cycles, 350);
}

void lightBlink(int pin, int cycles, int millisec){
   for (int i = 0; i < cycles; i++) {
    digitalWrite(pin, HIGH);
    delay(millisec);
    digitalWrite(pin, LOW);
    delay(millisec);
   }
}

void lightsBlink(int cycles){
  lightsBlink(cycles, 300);
}

void lightsBlink(int cycles, int millisec){
  for (int i = 0; i < cycles; i++) {
    lightsOn();
    delay(millisec);
    lightsOff();
    delay(millisec);
  }
}

void lightsShine (int cycles){
  lightsShine (cycles, 150);
}

void lightsShine (int cycles, int millisec){
  for (int i = 0; i < cycles; i++) {
    delay(millisec);
    digitalWrite(P1LED, HIGH);
    digitalWrite(P2LED, LOW);
    digitalWrite(resultLED, LOW);
    
    delay(millisec);
    digitalWrite(P1LED, LOW);
    digitalWrite(P2LED, HIGH);
    digitalWrite(resultLED, LOW);
  
    delay(millisec);
    digitalWrite(P1LED, LOW);
    digitalWrite(P2LED, LOW);
    digitalWrite(resultLED, HIGH);
  }
  digitalWrite(resultLED, LOW);
}

void lightsOn(){
  digitalWrite(P1LED, HIGH);
  digitalWrite(P2LED, HIGH);
  digitalWrite(resultLED, HIGH);
}

void lightsOff(){
  digitalWrite(P1LED, LOW);
  digitalWrite(P2LED, LOW);
  digitalWrite(resultLED, LOW);
}

