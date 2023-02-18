//  C++ program that draws a moving car on the screen using graphics functions:

#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

const int CAR_WIDTH = 100;
const int CAR_HEIGHT = 50;
const int CAR_SPEED = 5;

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  int x = 0, y = getmaxy() - CAR_HEIGHT - 10;

  while (!kbhit()) {
    cleardevice();

    // draw the car
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    rectangle(x, y, x + CAR_WIDTH, y + CAR_HEIGHT);
    floodfill(x + 10, y + 10, YELLOW);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(x + 25, y + CAR_HEIGHT, 10);
    circle(x + CAR_WIDTH - 25, y + CAR_HEIGHT, 10);
    floodfill(x + 25, y + CAR_HEIGHT, BLACK);
    floodfill(x + CAR_WIDTH - 25, y + CAR_HEIGHT, BLACK);

    line(x + 10, y, x + 30, y);
    line(x + 70, y, x + 90, y);
    line(x, y + 10, x, y + 40);
    line(x + CAR_WIDTH, y + 10, x + CAR_WIDTH, y + 40);

    // update the position of the car
    x = (x + CAR_SPEED) % (getmaxx() + CAR_WIDTH);

    // update the screen
    delay(50);
  }

  getch();
  closegraph();
  return 0;
}





// This program uses the graphics functions to draw a car on the screen, and then animates the 
// car by continuously updating its position.

// The initgraph function is used to initialize the graphics mode, 
// and the getmaxy function is used to find the bottom of the screen.

// The while loop is used to continuously update the screen until a key is 
// pressed. Inside the loop, the cleardevice function is used to clear the screen, and the car is drawn using the rectangle, circle, and line functions.

// The position and size of the car components are calculated based on the current 
// position of the car, stored in the x and y variables. The x variable is updated in each iteration of the loop, 
// causing the car to move to the right of the screen. Once the car goes off the screen on the right, it reappears on the left, creating an infinite loop of animation.

// Finally, the program introduces a delay using the delay function to control the animation speed,
//  and the getch and closegraph functions are used to wait for a key press and close the graphics window, respectively.