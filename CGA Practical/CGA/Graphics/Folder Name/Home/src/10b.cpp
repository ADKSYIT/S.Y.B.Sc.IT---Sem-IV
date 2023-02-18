// C++ program that performs a smiling face animation using graphics functions:
#include <iostream>
#include <graphics.h>
#include <math.h>
#include <time.h>

using namespace std;

const int RADIUS = 100;

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  int centerX = getmaxx() / 2;
  int centerY = getmaxy() / 2;

  int angle = 0;
  while (!kbhit()) {
    cleardevice();

    // draw the face
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(centerX, centerY, RADIUS);
    floodfill(centerX, centerY, YELLOW);

    // draw the eyes
    int leftEyeX = centerX - RADIUS / 2;
    int rightEyeX = centerX + RADIUS / 2;
    int eyeY = centerY - RADIUS / 4;
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(leftEyeX, eyeY, RADIUS / 8);
    floodfill(leftEyeX, eyeY, BLACK);
    circle(rightEyeX, eyeY, RADIUS / 8);
    floodfill(rightEyeX, eyeY, BLACK);

    // draw the mouth
    int mouthRadius = RADIUS / 2;
    int mouthX = centerX;
    int mouthY = centerY + RADIUS / 2;
    setcolor(BLACK);
    arc(mouthX, mouthY, 0 + angle, 180 - angle, mouthRadius);
    angle = (angle + 5) % 45;

    // update the screen
    delay(100);
  }

  getch();
  closegraph();
  return 0;
}



// This program uses the graphics functions to draw a car on the screen, and then animates the car by continuously updating its position.

// The initgraph function is used to initialize the graphics mode, and the getmaxy function is used to find the bottom of the screen.

// The while loop is used to continuously update the screen until a key is pressed. Inside the loop, the cleardevice 
// function is used to clear the screen, and the car is drawn using the rectangle, circle, and line functions.

// The position and size of the car components are calculated based on the current position of the car, stored in the x and y variables. 
// The x variable is updated in each iteration of the loop, causing the car to move to the right of the screen. Once the car goes 
// off the screen on the right, it reappears on the left, creating an infinite loop of animation.

// Finally, the program introduces a delay using the delay function to control the animation speed, and the getch and closegraph 
// functions are used to wait for a key press and close the graphics window, respectively.




