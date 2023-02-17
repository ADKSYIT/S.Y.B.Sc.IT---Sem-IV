#include <graphics.h>
#include <conio.h>
#include <iostream>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xMax = getmaxx();
    int yMax = getmaxy();

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    circle(xMax/4, yMax/4, xMax/8);
    floodfill(xMax/4, yMax/4, BLUE);
    outtextxy(xMax/4, yMax/4, "Circle");

    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    rectangle(xMax/2, yMax/4, 3*xMax/4, 3*yMax/8);
    floodfill(xMax/2 + (xMax/4)/2, yMax/4 + (yMax/8)/2, YELLOW);
    outtextxy(xMax/2 + (xMax/4)/2, yMax/4 + (yMax/8)/2, "Rectangle");

    setcolor(MAGENTA);
    setfillstyle(SOLID_FILL, MAGENTA);
    ellipse(xMax/4, yMax/2, 0, 360, xMax/8, yMax/8);
    floodfill(xMax/4, yMax/2, MAGENTA);
    outtextxy(xMax/4, yMax/2, "Ellipse");

    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    pieslice(xMax/2, yMax/2, 180, 360, xMax/8);
    floodfill(xMax/2, yMax/2, CYAN);
    outtextxy(xMax/2, yMax/2, "Half Ellipse");

    getch();
    closegraph();
    return 0;
}
