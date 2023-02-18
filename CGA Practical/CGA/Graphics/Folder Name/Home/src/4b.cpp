// Develop the program forBresenham’s Line drawing algorithm.

#include <graphics.h>
#include <stdio.h>
#include <math.h>

void bresenham_line(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y, incx, incy;
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    incx = x1 > x0 ? 1 : -1;
    incy = y1 > y0 ? 1 : -1;
    x = x0;
    y = y0;
    if (dx >= dy) {
        p = 2 * dy - dx;
        while (x != x1) {
            putpixel(x, y, WHITE);
            x += incx;
            if (p >= 0) {
                y += incy;
                p += 2 * (dy - dx);
            }
            else {
                p += 2 * dy;
            }
        }
    }
    else {
        p = 2 * dx - dy;
        while (y != y1) {
            putpixel(x, y, WHITE);
            y += incy;
            if (p >= 0) {
                x += incx;
                p += 2 * (dx - dy);
            }
            else {
                p += 2 * dx;
            }
        }
    }
    putpixel(x, y, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    bresenham_line(100, 100, 200, 200);
    getch();
    closegraph();
    return 0;
}


// In this code, the bresenham_line function takes four arguments representing the coordinates of the starting and ending points
//  of the line. The function calculates the differences between the x and y coordinates, determines the direction of the line, 
//  and sets the initial values of x and y.

// The function then determines whether dx or dy is greater and uses a loop to draw each pixel of the line. At each iteration, 
// the function updates the x or y coordinate based on the direction of the line and updates the value of p, which is used to 
// determine whether the next pixel should be on the same row or column as the current pixel.

// Finally, the function calls putpixel to draw a point at each coordinate, and the main function initializes 
// the graphics mode, calls the bresenham_line function with the desired coordinates, and then waits for user input 
// before closing the graphics mode.

// You can modify the values in the bresenham_line function to draw a line of your desired length and coordinates.