// C program that implements the Cohen-Sutherland line clipping algorithm
#include<stdio.h>
#include<graphics.h>

// Define the bit codes for the 4 regions of the window
#define INSIDE 0  // 0000
#define LEFT 1    // 0001
#define RIGHT 2   // 0010
#define BOTTOM 4  // 0100
#define TOP 8     // 1000

// Define the dimensions of the window
#define xmin 100
#define xmax 400
#define ymin 100
#define ymax 400

// Function to compute the bit code of a point
int computeCode(int x, int y)
{
    int code = INSIDE;
    if(x < xmin)
        code |= LEFT;
    else if(x > xmax)
        code |= RIGHT;
    if(y < ymin)
        code |= BOTTOM;
    else if(y > ymax)
        code |= TOP;
    return code;
}

// Function to clip the line using the Cohen-Sutherland algorithm
void cohenSutherland(int x1, int y1, int x2, int y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while(1)
    {
        if((code1 == 0) && (code2 == 0))
        {
            accept = 1;
            break;
        }
        else if(code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            int x, y;

            if(code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if(code_out & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if(code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if(code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if(code_out & LEFT)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if(code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    
    // If the line is accepted, draw it
    if(accept)
    {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    // Draw the window
    setcolor(RED);
    rectangle(xmin, ymin, xmax, ymax);
    
    // Input the line to be clipped
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the line: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
}


