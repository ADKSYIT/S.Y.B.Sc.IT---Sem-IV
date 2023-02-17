// This code uses the Turbo C++ Graphics library to create a window with a red x-axis and a green y-axis. 
// The initgraph function initializes the graphics window, and the setcolor function sets the color for the axis lines. 
// The line function is used to draw the lines for the x-axis and y-axis in the center of the window. 
// The getch function waits for the user to press a key, and the closegraph function closes the window.


#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(RED);
    line(0, getmaxy()/2, getmaxx(), getmaxy()/2);

    setcolor(GREEN);
    line(getmaxx()/2, 0, getmaxx()/2, getmaxy());

    getch();
    closegraph();
    return 0;
}
