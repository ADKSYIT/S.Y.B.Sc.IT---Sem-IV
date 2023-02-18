// Develop the program for the mid-point ellipse drawing algorithm.

#include <graphics.h>
#include <stdio.h>
#include <math.h>

void mid_point_ellipse(int xc, int yc, int rx, int ry)
{
    int x = 0, y = ry;
    int rx2 = rx * rx, ry2 = ry * ry;
    int p1 = ry2 - rx2 * ry + 0.25 * rx2;
    int px = 2 * ry2 * x;
    int py = 2 * rx2 * y;
    while (px < py) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        x++;
        px += 2 * ry2;
        if (p1 < 0) {
            p1 += px + ry2;
        }
        else {
            y--;
            py -= 2 * rx2;
            p1 += px - py + ry2;
        }
    }
    int p2 = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;
    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        y--;
        py -= 2 * rx2;
        if (p2 > 0) {
            p2 += rx2 - py;
        }
        else {
            x++;
            px += 2 * ry2;
            p2 += px - py + rx2;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    mid_point_ellipse(200, 200, 100, 50);
    getch();
    closegraph();
    return 0;
}




// In this code, the mid_point_ellipse function takes four arguments representing the center 
// point (xc, yc) and the horizontal (rx) and vertical (ry) radii of the ellipse. The function uses 
// the Mid-Point Ellipse Drawing algorithm to calculate the coordinates of each pixel of the ellipse 
// and calls putpixel to draw a point at each coordinate.

// The algorithm uses the initial point x=0 and y=ry and calculates two decision parameters p1 and p2. 
// At each iteration, the function checks whether the first or second decision parameter is negative or
//  positive and updates the values of x and y and the values of the decision parameters accordingly.

// Finally, the function calls putpixel to draw a point at each of the four symmetric coordinates around 
// the circumference of the ellipse, and the main function initializes the graphics mode, calls the mid_point_ellipse 
// function with the desired center and radii, and then waits for user input before closing the graphics mode.

// You can modify the values in the mid_point_ellipse function to draw an ellipse of your desired size and location.