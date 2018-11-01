#include<stdio.h>
#include<graphics.h>

void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
  //  float m;

    dx=x1-x0;
    dy=y1-y0;
//    m=(float)dy/dx;
  //  printf("Slope m=%f",m);
    x=x0;
    y=y0;

    p=2*dy-dx;

    while(x<x1)
    {
	if(p>=0)
	{
	    putpixel(x,y,7);
	    y=y+1;
	    p=p+2*dy-2*dx;
	}
	else
	{
	    putpixel(x,y,7);
	    p=p+2*dy;
	}
	x=x+1;
    }
}

int main()
{
    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

    printf("Enter x1 and y1: ");
    scanf("%d%d", &x0, &y0);

    printf("Enter x2 and y2: ");
    scanf("%d%d", &x1, &y1);
    drawline(x0, y0, x1, y1);

    return 0;
}