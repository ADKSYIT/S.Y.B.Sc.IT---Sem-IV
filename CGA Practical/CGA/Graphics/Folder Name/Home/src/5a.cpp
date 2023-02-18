// Develop the program for the mid-point circle drawing algorithm.

#include <graphics.h>
#include <stdio.h>
#include <math.h>

void mid_point_circle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;
    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        if (p < 0) {
            p += 2 * x + 3;
        }
        else {
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    mid_point_circle(200, 200, 100);
    getch();
    closegraph();
    return 0;
}


// In this code, the mid_point_circle function takes three arguments representing the center point (xc, yc) and 
// the radius r of the circle. The function uses the Mid-Point Circle Drawing algorithm to calculate the coordinates of 
// each pixel of the circle and calls putpixel to draw a point at each coordinate.

// The algorithm uses the initial point x=0 and y=r and calculates the value of a decision parameter p. 
// At each iteration, the function checks whether the decision parameter is negative or positive and updates the 
// value of p and the values of x and y accordingly.

// Finally, the function calls putpixel to draw a point at each of the eight symmetric coordinates around the circumference of the 
// circle, and the main function initializes the graphics mode, calls the mid_point_circle function with the desired center 
// and radius, and then waits for user input before closing the graphics mode.

// You can modify the values in the mid_point_circle function to draw a circle of your desired size and location.