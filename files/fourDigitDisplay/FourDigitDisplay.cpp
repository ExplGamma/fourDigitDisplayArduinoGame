
#include "Arduino.h"
#include "FourDigitDisplay.h"

#define DELAYTIME = 5;

FourDigitDisplay::FourDigitDisplay(int digitPins [4], int ledPins[7]){
  //TODO
}

FourDigitDisplay::FourDigitDisplay(int digitPins [4], int ledPins[7], int DPPin){
  //TODO
}

FourDigitDisplay::FourDigitDisplay(int digit1Pin, int digit2Pin, int digit3Pin, int digit4Pin, int DPpin,
  int ledAPin, int ledBPin, int ledCPin, int ledDPin, int ledEPin, int ledFPin, int ledGPin){
  //TODO
}

FourDigitDisplay::FourDigitDisplay(int digit1Pin, int digit2Pin, int digit3Pin, int digit4Pin,
  int ledAPin, int ledBPin, int ledCPin, int ledDPin, int ledEPin, int ledFPin, int ledGPin){
  //TODO
}

void FourDigitDisplay::zero(){
  digitalWrite(_PA, HIGH);   
  digitalWrite(_PB, HIGH);   
  digitalWrite(_PC, HIGH);   
  digitalWrite(_PD, HIGH);   
  digitalWrite(_PE, HIGH);   
  digitalWrite(_PF, HIGH);   
  digitalWrite(_PG, LOW);
}

void FourDigitDisplay::one(){
  digitalWrite(_PA, LOW);   
  digitalWrite(_PB, HIGH);   
  digitalWrite(_PC, HIGH);   
  digitalWrite(_PD, LOW);   
  digitalWrite(_PE, LOW);   
  digitalWrite(_PF, LOW);   
  digitalWrite(_PG, LOW);
}

void FourDigitDisplay::two(){
  digitalWrite(_PA, HIGH);   
  digitalWrite(_PB, HIGH);   
  digitalWrite(_PC, LOW);   
  digitalWrite(_PD, HIGH);   
  digitalWrite(_PE, HIGH);   
  digitalWrite(_PF, LOW);   
  digitalWrite(_PG, HIGH);
}

void FourDigitDisplay::three(){
  digitalWrite(_PA, HIGH);   
  digitalWrite(_PB, HIGH);   
  digitalWrite(_PC, HIGH);   
  digitalWrite(_PD, HIGH);   
  digitalWrite(_PE, LOW);   
  digitalWrite(_PF, LOW);   
  digitalWrite(_PG, HIGH);
}

void FourDigitDisplay::four(){
  digitalWrite(_PA, LOW);   
  digitalWrite(_PB, HIGH);   
  digitalWrite(_PC, HIGH);   
  digitalWrite(_PD, LOW);   
  digitalWrite(_PE, LOW);   
  digitalWrite(_PF, HIGH);   
  digitalWrite(_PG, HIGH);
}

void FourDigitDisplay::five(){
  digitalWrite(_PA, HIGH);   
  digitalWrite(_PB, LOW);   
  digitalWrite(_PC, HIGH);   
  digitalWrite(_PD, HIGH);   
  digitalWrite(_PE, LOW);   
  digitalWrite(_PF, HIGH);   
  digitalWrite(_PG, HIGH);
}

void FourDigitDisplay::six(){
  digitalWrite(_PA, HIGH);   
  digitalWrite(_PB, LOW);   
  digitalWrite(_PC, HIGH);   
  digitalWrite(_PD, HIGH);   
  digitalWrite(_PE, HIGH);   
  digitalWrite(_PF, HIGH);   
  digitalWrite(_PG, HIGH);
}

void FourDigitDisplay::seven(){
  digitalWrite(_PA, HIGH);   
  digitalWrite(_PB, HIGH);   
  digitalWrite(_PC, HIGH);   
  digitalWrite(_PD, LOW);   
  digitalWrite(_PE, LOW);   
  digitalWrite(_PF, LOW);   
  digitalWrite(_PG, LOW);
}

void FourDigitDisplay::eight(){
  digitalWrite(_PA, HIGH);   
  digitalWrite(_PB, HIGH);   
  digitalWrite(_PC, HIGH);   
  digitalWrite(_PD, HIGH);   
  digitalWrite(_PE, HIGH);   
  digitalWrite(_PF, HIGH);   
  digitalWrite(_PG, HIGH);
}

void FourDigitDisplay::nine(){
  digitalWrite(_PA, HIGH);   
  digitalWrite(_PB, HIGH);   
  digitalWrite(_PC, HIGH);   
  digitalWrite(_PD, LOW);   
  digitalWrite(_PE, LOW);   
  digitalWrite(_PF, HIGH);   
  digitalWrite(_PG, HIGH);
}

int FourDigitDisplay::displayNum (int singleDigitNumber){
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

void FourDigitDisplay::writeNums(int d1, int d2, int d3, int d4){
  digitalWrite(_D1, LOW);
  digitalWrite(_D2, HIGH);
  digitalWrite(_D3, HIGH);
  digitalWrite(_D4, HIGH);
  displayScore(num1);
  delay(DELAYTIME);
  digitalWrite(_D1, HIGH);
  digitalWrite(_D2, LOW);
  digitalWrite(_D3, HIGH);
  digitalWrite(_D4, HIGH);
  displayScore(num2);
  delay(DELAYTIME);
  digitalWrite(_D1, HIGH);
  digitalWrite(_D2, HIGH);
  digitalWrite(_D3, LOW);
  digitalWrite(_D4, HIGH);
  displayScore(num3);
  delay(DELAYTIME);
  digitalWrite(_D1, HIGH);
  digitalWrite(_D2, HIGH);
  digitalWrite(_D3, HIGH);
  digitalWrite(_D4, LOW);
  displayScore(num4);
  delay(DELAYTIME);
}

void FourDigitDisplay::writeNum(int upToFourDigitNumber){
  writeNums( (number/1000)%10, (number/100)%10, (number/10)%10, number%10 );
}

void FourDigitDisplay::writeToDigit(int digitToWrite, int numberToWrite){
  switch(digitToWrite){
    case 1:
      digitalWrite(_D1, LOW);
      digitalWrite(_D2, HIGH);
      digitalWrite(_D3, HIGH);
      digitalWrite(_D4, HIGH);
      break;
    case 2:
      digitalWrite(_D1, HIGH);
      digitalWrite(_D2, LOW);
      digitalWrite(_D3, HIGH);
      digitalWrite(_D4, HIGH);
      break;
    case 3:
      digitalWrite(_D1, HIGH);
      digitalWrite(_D2, HIGH);
      digitalWrite(_D3, LOW);
      digitalWrite(_D4, HIGH);
      break;
    case 4:
      digitalWrite(_D1, HIGH);
      digitalWrite(_D2, HIGH);
      digitalWrite(_D3, HIGH);
      digitalWrite(_D4, LOW);
      break;
    default:
      digitalWrite(_D1, LOW);
      digitalWrite(_D2, LOW);
      digitalWrite(_D3, LOW);
      digitalWrite(_D4, LOW);
  }
  displayNum(numberToWrite);
};
