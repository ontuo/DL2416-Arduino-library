#include "DL2416T.h"

Display::Display(uint8_t nD0, uint8_t nD1, uint8_t nD2, uint8_t nD3, uint8_t nD4, uint8_t nD5,
                 uint8_t nD6, uint8_t nAd0, uint8_t nAd1, uint8_t nWR, uint8_t nCU, uint8_t nCUE,
                 uint8_t nCLR, uint8_t nBL)
    : D0(nD0), D1(nD1), D2(nD2), D3(nD3), D4(nD4), D5(nD5), D6(nD6), Ad0(nAd0), Ad1(nAd1),
      WR(nWR), CU(nCU), CUE(nCUE), CLR(nCLR), BL(nBL)
{
    pinMode(D0, 1);
    pinMode(D1, 1);
    pinMode(D2, 1);
    pinMode(D3, 1);
    pinMode(D4, 1);
    pinMode(D5, 1);
    pinMode(D6, 1);
    pinMode(WR, 1);
    pinMode(CLR, 1);
    pinMode(CU, 1);
    pinMode(BL, 1);
    pinMode(Ad0, 1);
    pinMode(Ad1, 1);

    digitalWrite(WR, 1);
    digitalWrite(Ad0, 1);
    digitalWrite(Ad1, 1);

    digitalWrite(BL, 1);
    digitalWrite(CLR, 1);
    digitalWrite(CUE, 0);
    digitalWrite(CU, 1);
}

void Display::Print(String word, int time_delay)
{
    clear();
    digitalWrite(CUE, 0);
    digitalWrite(CU, 1);
    int len = 0;
    if (word.length() > 4)
    {
        len = 4;
    }
    else
    {
        len = word.length();
    }
    Serial.println(word);
    for (int i = 0; i < len; i++)
    {
        Serial.print(i);
        int m = len - 1 - i;
        Serial.print("-");
        Serial.println(m);
        setLetter(word[i], m, time_delay);
    }
    delay(100);
}

void Display::setAdress(int position)
{
    digitalWrite(Ad1, (position & 0b10) >> 1);
    digitalWrite(Ad0, (position & 0b01) >> 0);
}



void Display::setLetter(char letter, int position, int time_delay)
{
    setAdress(position);

    digitalWrite(D6, (letter & 0b1000000) >> 6);
    digitalWrite(D5, (letter & 0b0100000) >> 5);
    digitalWrite(D4, (letter & 0b0010000) >> 4);
    digitalWrite(D3, (letter & 0b0001000) >> 3);
    digitalWrite(D2, (letter & 0b0000100) >> 2);
    digitalWrite(D1, (letter & 0b0000010) >> 1);
    digitalWrite(D0, (letter & 0b0000001) >> 0);

    digitalWrite(WR, 0);
    delay(time_delay);
    digitalWrite(WR, 1);
}

void Display::clear()
{
    digitalWrite(CLR, 0);
    digitalWrite(CLR, 1);
}

void Display::turnOff()
{
    digitalWrite(BL, 0);
}

void Display::turnOn()
{
    digitalWrite(BL, 1);
}

Display::~Display() {}
