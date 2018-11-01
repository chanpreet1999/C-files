#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void drawcircle(int x,int y,int h,int k)
   {
   putpixel(x+h,y+k,6);
   putpixel(y+h,x+k,6);
   putpixel(y+h,-x+k,6);
   putpixel(x+h,-y+k,6);
   putpixel(-x+h,y+k,6);
   putpixel(-y+h,x+k,6);
   putpixel(-y+h,-x+k,6);
   putpixel(-x+h,-y+k,6);
   }
void main()
{
   int gdriver = DETECT, gmode, errorcode;
   int r,h,k,x,y,d;
   initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI ");
  errorcode = graphresult();

   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
   }
   else
   {
   printf("enter the radius of circle");
   scanf("%d",&r);
   printf("enter the coordinates of centre of cirle");
   scanf("%d%d",&h,&k);
   x=0;
   y=r;
   d=3-2*r;
   while(x<=y)
   {
   drawcircle(x,y,h,k);
   if(d<0)
   {
   d=d+4*x+6;
   x=x+1;
   }
   else if(d>=0)
   {
   d=d+4*(x-y)+10;
   x=x+1;
   y=y-1;
   }
   }
   }
   getch();
   closegraph();
   }






