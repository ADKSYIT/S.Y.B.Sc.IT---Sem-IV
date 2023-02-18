// Write a program to implement 2D scaling.

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
