#include "DL2416T.h"

Display display(A1, A0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);

void setup()
{
  Serial.begin(9600);
}

String test = "HI!!";

void loop()
{
  display.Print(test,1000);
  delay(5000);
}
