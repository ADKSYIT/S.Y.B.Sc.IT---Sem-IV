#include <iostream>
#include <graphics.h>
#include <cmath>

#define PI 3.14159265

using namespace std;

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  int x1, y1, x2, y2, x3, y3, xn1, yn1, xn2, yn2, xn3, yn3;
  float angle;

  // Input the coordinates of the triangle
  cout << "Enter the coordinates of the triangle: ";
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  // Draw the original triangle
  setcolor(GREEN);
  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x1, y1);

  // Input the angle of rotation
  cout << "Enter the angle of rotation: ";
  cin >> angle;

  // Convert the angle to radians
  angle = angle * PI / 180.0;

  // Compute the sine and cosine of the angle
  float c = cos(angle);
  float s = sin(angle);

  // Rotate the triangle
  xn1 = round(x1 * c - y1 * s);
  yn1 = round(x1 * s + y1 * c);
  xn2 = round(x2 * c - y2 * s);
  yn2 = round(x2 * s + y2 * c);
  xn3 = round(x3 * c - y3 * s);
  yn3 = round(x3 * s + y3 * c);

  // Draw the rotated triangle
  setcolor(RED);
  line(xn1, yn1, xn2, yn2);
  line(xn2, yn2, xn3, yn3);
  line(xn3, yn3, xn1, yn1);

  getch();
  closegraph();

  return 0;
}
