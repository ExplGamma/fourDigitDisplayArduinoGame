#ifndef 4dDisplay_h
#define 4dDisplay_h

#include "Arduino.h"

class FourDigitDisplay
{
  int _D1;
  int _D2;
  int _D3;
  int _D4;
  int _PA;
  int _PB;
  int _PC;
  int _PD;
  int _PE;
  int _PF;
  int _PG;
  public:
    // CONSTRUCTORS
    FourDigitDisplay(int digitPins [4], int ledPins[7]);
    FourDigitDisplay(int digit1Pin, int digit2Pin, int digit3Pin, int digit4Pin, int DPpin,
      int ledAPin, int ledBPin, int ledCPin, int ledDPin, int ledEPin, int ledFPin, int ledGPin);
    FourDigitDisplay(int digit1Pin, int digit2Pin, int digit3Pin, int digit4Pin,
      int ledAPin, int ledBPin, int ledCPin, int ledDPin, int ledEPin, int ledFPin, int ledGPin);
      
    // PRINT INDIV NUMBERS
    void zero();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();
    
    // PRINT NUMBERS
    int displayNum(int singleDigitNumber);
    void writeNum(int upTo4DigitNumber);
    void writeToDigit(int digitToWrite, int numberToWrite);
    void writeNums(int d1, int d2, int d3, int d4);
};

#endif
