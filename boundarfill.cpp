#include<graphics.h>
#include<conio.h>

void boundaryFill(int x, int y, int fillColor, int boundaryColor){
    int c = getpixel(x, y);

    if(c != fillColor && c != boundaryColor){
        putpixel(x, y, fillColor);

        boundaryFill(x+1, y, fillColor, boundaryColor);
        boundaryFill(x-1, y, fillColor, boundaryColor);
        boundaryFill(x, y+1, fillColor, boundaryColor);
        boundaryFill(x, y-1, fillColor, boundaryColor);
    }
}

void main(){
    int gd = DETECT, gm, x, y, fillColor, boundaryColor;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setbkcolor(WHITE);
    setcolor(BLUE);

    rectangle(100, 100, 158, 157);

    boundaryFill(101, 101, CYAN, BLUE);

    getch();
    closegraph();
}
