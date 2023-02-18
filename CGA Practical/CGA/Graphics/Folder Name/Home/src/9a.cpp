
// C++ program that fills a circle using the Flood Fill Algorithm:
#include <iostream>
#include <graphics.h>

using namespace std;

void floodFill(int x, int y, int fillColor, int borderColor) {
  if (getpixel(x, y) != borderColor && getpixel(x, y) != fillColor) {
    putpixel(x, y, fillColor);
    floodFill(x + 1, y, fillColor, borderColor);
    floodFill(x - 1, y, fillColor, borderColor);
    floodFill(x, y + 1, fillColor, borderColor);
    floodFill(x, y - 1, fillColor, borderColor);
  }
}

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  int x = 250;
  int y = 250;
  int radius = 100;

  circle(x, y, radius);
  floodFill(x, y, RED, BLACK);

  getch();
  closegraph();
  return 0;
}


// This program defines a function floodFill that takes in the coordinates of a point, the color to fill, and the color of the border, and then performs
//  the Flood Fill algorithm to fill the circle.

// The algorithm works by starting at 
// the given point and recursively filling adjacent pixels that are not part of the border and have not already been 
// filled with the fill color. This is done by checking the color of the current pixel using the getpixel function, and 
// then setting it to the fill color using the putpixel function if it is not part of the border or has not already been filled. 
// The function then recursively calls itself on the adjacent pixels to continue the fill.

// The program then defines the main function that draws a circle and fills it using the floodFill function with the fill color RED 
// and the border color BLACK. Finally, the getch and closegraph functions are used to close the graphics window when the user presses a key.