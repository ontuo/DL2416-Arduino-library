# Siemens DL2416T Display

![Display](http://www.decadecounter.com/vta/pic/dl2416t.jpg)

### Beginning

Creating a new object:

```C++
Display display (D0, D1, D2, D3, D4, D5, D6, 
                A0, A1, WR, CU, CUE, CLR, BL);
```

(Replace D0 ... BL with the corresponding pin numbers ).

### Functions

No cursor control.

```C++
display.Print(String word);     //Print a word.Remember that only 4 
                                //or fewer letters can be displayed.

display.clear();    //Clear the display.

display.turnOff();      //You can turn off or on the screen (without deleting data).
display.turnOn();
display.setLetter(char letter, int position);   //Output one letter to the desired position.
                                                //Note that the positions on the display are 
                                                //numbered from the right to the left from 3 to 0.

```
### Datasheet

[Siemens DL2416T datasheet](https://www.silicon-ark.co.uk/datasheets/DL2416-display-datasheet-siemens.pdf)