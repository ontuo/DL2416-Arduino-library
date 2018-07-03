#ifndef DL2416T_h
#define DL2416T_h

#include "Arduino.h"

class Display
{
public:
  Display(uint8_t nD0, uint8_t nD1, uint8_t nD2, uint8_t nD3, uint8_t nD4, uint8_t nD5,
          uint8_t nD6, uint8_t nAd0, uint8_t nAd1, uint8_t nWR, uint8_t nCU, uint8_t nCUE,
          uint8_t nCLR, uint8_t nBL);
  ~Display();
  void Print(String word, int time_delay);
  void setAdress(int position);
  void setCursor(int position);
  void setLetter(char letter, int position,int time_delay);
  void removeCursor();
  void showCursor();
  void hideCursor();
  void clear();
  void turnOff();
  void turnOn();

private:
  uint8_t D0,
      D1,
      D2,
      D3,
      D4,
      D5,
      D6;

  uint8_t Ad0, Ad1;

  uint8_t WR, CU, CUE, CLR, BL;

  int number = 3;

  void set_begin();
};

#endif
