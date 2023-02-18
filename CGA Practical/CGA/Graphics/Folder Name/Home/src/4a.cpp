// Develop the program for DDA Line drawing algorithm.


#include <graphics.h>
#include <stdio.h>
#include <math.h>

void dda_line(int x0, int y0, int x1, int y1)
{
    int i;
    float dx, dy, x, y, steps;
    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);
    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }
    float x_inc = dx / steps;
    float y_inc = dy / steps;
    x = x0;
    y = y0;
    putpixel(x, y, WHITE);
    for (i = 0; i < steps; i++)
    {
        x += x_inc;
        y += y_inc;
        putpixel(round(x), round(y), WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    dda_line(100, 100, 200, 200);
    getch();
    closegraph();
    return 0;
}

// Explanation of CoDosDateTimeToFileTime
// In this code, the dda_line function takes four arguments representing the coordinates of the starting and 
// ending points of the line. The function calculates the values of dx and dy as the differences between the x and y coordinates, 
// respectively, and determines the number of steps needed to draw the line based on which difference is greater.

// The function then calculates the increment values for the x and y coordinates for each step of the line using 
// the formula dx/steps and dy/steps. Finally, the function uses a loop to draw each pixel of the line by updating 
// the x and y values and calling the putpixel function to draw a point at each coordinate.

// In the main function, the initgraph function initializes the graphics mode, and the getch and closegraph 
// functions are used to pause the program and close the graphics mode when the user is done viewing the output.

// You can modify the values in the dda_line function to draw a line of your desired length and coordinates.