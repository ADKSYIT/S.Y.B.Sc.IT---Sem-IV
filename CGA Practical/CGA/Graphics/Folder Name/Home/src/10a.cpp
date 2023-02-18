// C++ program to Develop a simple text screen saver using graphics functions
#include <iostream>
#include <graphics.h>
#include <string.h>
#include <time.h>

using namespace std;

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  // set the font style and size
  settextstyle(10, 0, 5);

  // set the initial coordinates
  int x = 50, y = 100;

  // set the text and its color
  char text[] = "Hello, World!";
  int color = YELLOW;

  while (!kbhit()) {  // continue until a key is pressed
    // clear the screen
    cleardevice();

    // draw the text at the current position
    setcolor(color);
    outtextxy(x, y, text);

    // update the position and color
    x += 10;
    y += 5;
    color = (color + 1) % 16;

    // wrap around the screen if necessary
    if (x > getmaxx()) {
      x = 50;
    }
    if (y > getmaxy()) {
      y = 100;
    }

    // introduce a delay to control the animation speed
    delay(100);
  }

  getch();
  closegraph();
  return 0;
}


// This program uses the settextstyle function to set the font style and size, and then uses a while loop 
// to continuously update the position and color of the text on the screen. The kbhit function is used to check 
// if a key has been pressed, which will exit the loop and end the program.

// Inside the loop, the cleardevice function is used to clear the screen, and the outtextxy function 
// is used to draw the text at the current position. The position and color are then updated, and the program checks 
// if the text has gone off the edge of the screen, in which case it wraps around to the other side.

// Finally, a delay is introduced using the delay function to control the animation speed, and the 
// getch and closegraph functions are used to wait for a key press and close the graphics window, respectively.