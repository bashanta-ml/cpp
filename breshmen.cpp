/* Bresenham line drawing for Turbo C/C++ (BGI graphics) */
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bresenham(int xi, int yi, int xf, int yf)
{
    int dx = abs(xf - xi);
    int dy = abs(yf - yi);
    int sx = (xi < xf) ? 1 : -1;
    int sy = (yi < yf) ? 1 : -1;
    int err = dx - dy;
    int x = xi, y = yi;

    while (true) {
        putpixel(x, y, WHITE);
        if (x == xf && y == yf) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x += sx; }
        if (e2 < dx)  { err += dx; y += sy; }
    }
}

int main()
{
    int gd = DETECT, gm;
    int xi, yi, xf, yf;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter value of xi yi: ");
    scanf("%d %d", &xi, &yi);
    printf("Enter value of xf yf: ");
    scanf("%d %d", &xf, &yf);

    cleardevice();
    bresenham(xi, yi, xf, yf);

    getch();
    closegraph();
    return 0;
}
