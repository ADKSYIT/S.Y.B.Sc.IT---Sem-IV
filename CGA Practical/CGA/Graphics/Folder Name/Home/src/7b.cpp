// C++ Program to create a house like figure and perform the following operations.
// i.Scaling about the origin followed by translation.
// ii. Scaling with reference to an arbitrary point.
// iii. Reflect about the line y = mx + c.



// #include <iostream>
// #include <graphics.h>
// #include <cmath>

// using namespace std;

// const int HOUSE_WIDTH = 200;
// const int HOUSE_HEIGHT = 200;

// // Define the house shape as a set of lines and rectangles
// void drawHouse(int x, int y) {
//   setcolor(BLACK);
//   rectangle(x, y, x + HOUSE_WIDTH, y + HOUSE_HEIGHT);
//   rectangle(x + 50, y + 100, x + 150, y + 200);
//   line(x, y + HOUSE_HEIGHT / 2, x + HOUSE_WIDTH, y + HOUSE_HEIGHT / 2);
//   line(x + 50, y + 100, x + 100, y);
//   line(x + 100, y, x + 150, y + 100);
// }

// // Scale the house with respect to the origin
// void scaleOrigin(int& x, int& y, double scaleX, double scaleY) {
//   // Apply scaling transformation to each point of the house
//   x *= scaleX;
//   y *= scaleY;
// }

// // Scale the house with respect to an arbitrary point
// void scaleArbitrary(int& x, int& y, double scaleX, double scaleY, int cx, int cy) {
//   // Translate the house so that the arbitrary point is at the origin
//   x -= cx;
//   y -= cy;
//   // Apply scaling transformation to each point of the house
//   x = round(x * scaleX);
//   y = round(y * scaleY);
//   // Translate the house back to its original position
//   x += cx;
//   y += cy;
// }

// // Reflect the house about the line y = mx + c
// void reflect(int& x, int& y, double m, double c) {
//   // Compute the reflection of the point (x, y) about the line y = mx + c
//   double d = (x + m * (y - c)) / (1 + pow(m, 2));
//   double dx = 2 * d - x;
//   double dy = 2 * m * d - y;
//   x = round(dx);
//   y = round(dy);
// }

// int main() {
//   int gd = DETECT, gm;
//   initgraph(&gd, &gm, NULL);

//   // Draw the house
//   int x = 100, y = 100;
//   drawHouse(x, y);

//   // Scale the house with respect to the origin
//   double scaleX = 1.5, scaleY = 0.8;
//   scaleOrigin(x, y, scaleX, scaleY);
//   drawHouse(x, y);

//   // Translate the scaled house
//   int dx = 100, dy = 50;
//   x += dx;
//   y += dy;
//   drawHouse(x, y);

//   // Scale the house with respect to an arbitrary point
//   double cx = x + HOUSE_WIDTH / 2.0, cy = y + HOUSE_HEIGHT / 2.0;
//   scaleX = 0.5, scaleY = 1.2;
//   scaleArbitrary(x, y, scaleX, scaleY, cx, cy);
//   drawHouse(x, y);

//   // Reflect the house about the line y = mx + c
//   double m = 0.5, c = 0;
//   reflect(x, y, m, c);
//   drawHouse(x, y);

//   getch();
//   closegraph();
//   return 0;
// }


#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void draw_house(int x, int y, int size) {
  int roof_x[4] = { x - size, x, x + size, x - size };
  int roof_y[4] = { y - size, y - 2 * size, y - size, y - size };
  int door_x[4] = { x - size / 2, x + size / 2, x + size / 2, x - size / 2 };
  int door_y[4] = { y, y, y + size, y + size };
  rectangle(x - size, y - size, x + size, y + size);
  rectangle(x - size / 2, y, x + size / 2, y + size);
  drawpoly(4, roof_x);
  drawpoly(4 ,roof_y);
  drawpoly(4, door_x);
  drawpoly(4, door_y);
}

void scale_origin(int x, int y, int size, float scale_factor) {
  int new_size = size * scale_factor;
  draw_house(x, y, new_size);
}

void scale_arbitrary(int x, int y, int size, int ref_x, int ref_y, float scale_factor) {
  int new_size = size * scale_factor;
  int new_x = ref_x + (x - ref_x) * scale_factor;
  int new_y = ref_y + (y - ref_y) * scale_factor;
  draw_house(new_x, new_y, new_size);
}

void reflect_line(int x, int y, int size, float m, float c) {
  int x1 = x - size;
  int y1 = y - size;
  int x2 = x + size;
  int y2 = y + size;
  float dx = x2 - x1;
  float dy = y2 - y1;
  float d = dx * (m * x1 - y1 + c) - dy * (x1 - m * y1 - c);
  line(x1, y1, x2, y2);
  if (d > 0) {
    while (x1 < x2) {
      if (m * x1 - y1 + c > 0) {
        y1++;
        y2++;
      } else {
        x1++;
        x2--;
      }
      line(x1, y1, x2, y2);
    }
  } else if (d < 0) {
    while (x1 < x2) {
      if (m * x1 - y1 + c < 0) {
        y1++;
        y2++;
      } else {
        x1++;
        x2--;
      }
      line(x1, y1, x2, y2);
    }
  }
}

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  int x = 200, y = 200, size = 50;
  draw_house(x, y, size);

  delay(1000);

  cleardevice();
  scale_origin(x, y, size, 1.5);

  delay(1000);

  cleardevice();
  int ref_x = 300, ref_y = 300;
  scale_arbitrary(x, y, size, ref_x, ref_y, 0.5);

  delay(1000);

  cleardevice();
  float m = 0.5;

}
