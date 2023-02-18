// C++ program that implements the Liang-Barsky line clipping algorithm:
#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void clipLine(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
  int dx = x2 - x1;
  int dy = y2 - y1;

  float p[4] = {-dx, dx, -dy, dy};
  float q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

  float u1 = 0, u2 = 1;

  for (int i = 0; i < 4; i++) {
    if (p[i] == 0) {
      if (q[i] < 0) {
        return;
      }
    }
    else {
      float t = q[i] / p[i];
      if (p[i] < 0) {
        u1 = max(u1, t);
      }
      else {
        u2 = min(u2, t);
      }
    }
  }

  if (u1 > u2) {
    return;
  }

  int clippedX1 = round(x1 + u1 * dx);
  int clippedY1 = round(y1 + u1 * dy);
  int clippedX2 = round(x1 + u2 * dx);
  int clippedY2 = round(y1 + u2 * dy);

  line(clippedX1, clippedY1, clippedX2, clippedY2);
}

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  int x1 = 50;
  int y1 = 50;
  int x2 = 250;
  int y2 = 250;

  int xmin = 100;
  int ymin = 100;
  int xmax = 200;
  int ymax = 200;

  line(x1, y1, x2, y2);
  clipLine(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

  getch();
  closegraph();
  return 0;
}


// This program first defines a function clipLine that takes in the endpoints of a line segment and 
// the dimensions of a rectangular clipping region, and then clips the line segment to the region using the Liang-Barsky algorithm.

// The algorithm works by defining four parameters p and q that determine the position of the line 
// segment with respect to the clipping region. If the line segment is outside the region along any of the four 
// directions (left, right, bottom, top), the function returns without drawing anything. If the line segment is inside the 
// region along all four directions, the function simply draws the original line. Otherwise, the function computes the values 
// of u1 and u2 that define the clipped portion of the line segment, and then uses these values to compute the clipped endpoints of the line.

// The program then defines main function that draws a line segment and clips it to a rectangular region defined by the 
// variables xmin, ymin, xmax, and ymax. The line function is used to draw the original line, and the clipLine function is 
// used to clip it to the specified region. Finally, the getch and closegraph functions are used to close the graphics window
//  when the user presses a key.