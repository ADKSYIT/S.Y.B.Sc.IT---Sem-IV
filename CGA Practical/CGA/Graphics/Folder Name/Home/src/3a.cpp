// Draw the following basic shapes in the center of the screen :
// i. Circle ii. Rectangle iii. Square iv. Concentric Circles v. Ellipse vi. Line



#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   
   // Set the center coordinates of the screen  
   int centerX = getmaxx()/2;
   int centerY = getmaxy()/2;

   // Draw a circle in the center of the screen
   circle(centerX, centerY, 100);

   // Draw a rectangle in the center of the screen
   rectangle(centerX-50, centerY-25, centerX+50, centerY+25);

   // Draw a square in the center of the screen
   rectangle(centerX-50, centerY-50, centerX+50, centerY+50);

   // Draw concentric circles in the center of the screen
   circle(centerX, centerY, 50);
   circle(centerX, centerY, 75);
   circle(centerX, centerY, 100);

   // Draw an ellipse in the center of the screen
   ellipse(centerX, centerY, 0, 360, 100, 50);

   // Draw a line in the center of the screen
   line(centerX-50, centerY-50, centerX+50, centerY+50);

   getch();
   closegraph();
   return 0;
}
