#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void dircle(int x,int y,int h,int k){
putpixel(x+h,y+k,15);
putpixel(y+h,x+k,15);
putpixel(y+h,-x+k,15);
putpixel(x+h,-y+k,15);
putpixel(-x+h,y+k,15);
putpixel(-y+h,x+k,15);
putpixel(-y+h,-x+k,15);
putpixel(-x+h,-y+k,15);
}




void main(void)
{  int x,y,h,k,r,d;
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();

      exit(1);
   }
   else{
   printf("Enter  radius:");
   scanf("%d",&r);
   printf("Enter the center:");
   scanf("%d%d",&h,&k);
   x=0;
   y=r;

   d=3- 2*r;
   while(x<=y){
       dircle(x,y,h,k);
	if(d<0){
	  // d=d+ 4*x +6;
	   d=d+2*x+3;
	   x=x+1;
	   y=y;
		}
	else if(d>=0){
	    // d=d+ 4*(x-y) +10;
	     d=d+2*(x-y)+5;
	     x=x+1;
	     y=y-1;
		 }
	}


   }
getch();
}