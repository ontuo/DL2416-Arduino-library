#include "DL2416T.h"

// Set up the pins
Display display(A1, A0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);
String words = "HELLOWORLD";

//Note that the positions on the display are numbered from the right to the left from 3 to 0
int position = 3;

void setup()
{
}

void loop()
{
    for (int i = 0; i < words.length(); i++)
    {
        if (position >= 0)
        {
            display.setLetter(words[i], position);
        }

        else
        {
            display.clear();
            position = 3;
            display.setLetter(words[i], position);
        }
        position--;
        delay(200);
    }
    //Add a space between phrases
    position--;
}