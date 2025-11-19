/* DDA Line Drawing Algorithm - Turbo C/C++ (BGI) */
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void dda(int xi, int yi, int xf, int yf) {
    int dx = xf - xi;
    int dy = yf - yi;
    int steps;
    float xInc, yInc;
    float x = xi, y = yi;

    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    if (steps == 0) {            // single pixel (start == end)
        putpixel(xi, yi, WHITE);
        return;
    }

    xInc = (float)dx / (float)steps;
    yInc = (float)dy / (float)steps;

    for (int i = 0; i <= steps; ++i) {
        putpixel((int)round(x), (int)round(y), WHITE);
        x += xInc;
        y += yInc;
    }
}

void main() {
    int gd = DETECT, gm;
    int xi, yi, xf, yf;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");   /* Make sure this path matches your Turbo installation */

    /* get input (you can hardcode values if you prefer) */
    printf("Enter value of xi yi: ");
    scanf("%d %d", &xi, &yi);
    printf("Enter value of xf yf: ");
    scanf("%d %d", &xf, &yf);

    setbkcolor(BLACK);
    cleardevice();
    setcolor(WHITE);

    dda(xi, yi, xf, yf);

    getch();
    closegraph();
}
