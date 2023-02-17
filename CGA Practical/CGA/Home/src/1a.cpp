// C++:

// graphics.h: This is a library in C++ that provides functions for drawing and working with graphics. 
// It is not part of the standard C++ library, so it may not be available on all systems. Some commonly used functions in graphics.h include:
// initwindow: This function is used to initialize a graphical window with a specified width and height.
// line: This function draws a line from one point to another in the graphical window.
// rectangle: This function draws a rectangle with specified coordinates for the top-left and bottom-right corners.
// circle: This function draws a circle with a specified center and radius.
// setcolor: This function sets the color used for drawing.
// Example:


#include <graphics.h>

int main()
{
  initwindow(800, 600, "Example");
  setcolor(RED);
  rectangle(100, 100, 300, 300);
  setcolor(GREEN);
  circle(200, 200, 50);
  getch();
  closegraph();
  return 0;
}


// Python:

// turtle: This is a module in Python that provides functions for working with graphics and creating turtle graphics. Turtle graphics is a popular way of introducing children to computer programming, but it can also be used for more advanced graphics. Some commonly used functions in turtle include:
// forward: This function moves the turtle forward by a specified distance.
// right: This function turns the turtle to the right by a specified number of degrees.
// left: This function turns the turtle to the left by a specified number of degrees.
// penup: This function lifts the turtle's pen, so that it doesn't draw when it moves.
// pendown: This function lowers the turtle's pen, so that it draws when it moves.
// Example:

// import turtle

// t = turtle.Turtle()

// t.forward(100)
// t.right(90)
// t.forward(100)
// t.right(90)
// t.forward(100)
// t.right(90)
// t.forward(100)

// turtle.done()


// C:

// graphics.h and winbgim.h: These are libraries in C that provide functions for drawing and working with graphics. Like graphics.h in C++, these libraries are not part of the standard C library, so they may not be available on all systems. Some commonly used functions in these libraries include:
// initwindow: This function is used to initialize a graphical window with a specified width and height.
// line: This function draws a line from one point to another in the graphical window.
// rectangle: This function draws a rectangle with specified coordinates for the top-left and bottom-right corners.
// circle: This function draws a circle with a specified center and radius.
// setcolor: This function sets the color used for drawing.
// Example:

// #include <graphics.h>
// #include <winbgim.h>

// int main()
// {
//   initwindow(800, 600, "Example");
//   setcolor(RED);
//   rectangle(100, 100, 300, 300
