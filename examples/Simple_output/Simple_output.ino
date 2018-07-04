#include "DL2416T.h"

// Set up the pins
Display display(A1, A0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);

void setup()
{
  //Print a message 
  display.Print("HI!!");
}

void loop()
{
}
