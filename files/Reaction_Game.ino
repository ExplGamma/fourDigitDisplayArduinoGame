/*
  Reaction Game
  Uses code from 4D Display
 */

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

int buttonPin = A5;
int Light = 13;

int delayTime = 5;

int randNumber = 0;

unsigned long previousMillis = 0;
unsigned long interval = 2000;

/* 
*/

void zero(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
}
void one(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}
void two(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
}
void three(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
}
void four(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}
void five(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}
void six(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}
void seven(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}
void eight(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}
void nine(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}

int displayScore (int score){
  switch(score){
    case 0: zero(); return 0;
    case 1: one(); return 1; 
    case 2: two(); return 2; 
    case 3: three(); return 3; 
    case 4: four(); return 4; 
    case 5: five(); return 5;
    case 6: six(); return 6; 
    case 7: seven(); return 7;
    case 8: eight(); return 8; 
    default: nine(); return 9; 
  }
}

void writeNums(int num1, int num2, int num3, int num4){
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  displayScore(num1);
  delay(delayTime);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  displayScore(num2);
  delay(delayTime);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
  displayScore(num3);
  delay(delayTime);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
  displayScore(num4);
  delay(delayTime);
}

void writeNum(int number){
  writeNums( (number/1000)%10, (number/100)%10, (number/10)%10, number%10 );
}

void setup() {
  // put your setup code here, to run once:
             
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT); 
  pinMode(D4, OUTPUT);
  pinMode(Light, OUTPUT);

  pinMode(buttonPin, INPUT);

  // Random Seeding
  randomSeed(analogRead(0));

  // AAAAA
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  zero();
}

void loop() {
  
  delay(random (3000, 6600));
  digitalWrite(Light, HIGH);
  unsigned long currentMillis = millis();
  previousMillis = currentMillis;
  boolean buttonPressed = digitalRead(buttonPin);

  while(!buttonPressed){
    currentMillis = millis();
    randNumber = currentMillis - previousMillis;
    writeNum(randNumber);
    buttonPressed = digitalRead(buttonPin);
  }
  
  currentMillis = millis();
  buttonPressed = digitalRead(buttonPin);
  previousMillis = currentMillis;
  while (buttonPressed){
    writeNum(randNumber);
    buttonPressed = digitalRead(buttonPin);
  }
  
  currentMillis = millis();
  unsigned long temp = currentMillis;
  while(temp + 5000 > currentMillis){
    writeNum(randNumber);
    currentMillis = millis();
  }
  
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  zero();
  digitalWrite(Light, LOW);
  

}
