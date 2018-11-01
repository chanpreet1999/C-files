#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{  float x1,y1,x2,y2,m,d,dx,dy;
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
   printf("Enter x1 and y1:");
   scanf("%f%f",&x1,&y1);
   printf("Enter x2 and y2:");
   scanf("%f%f",&x2,&y2);
   dy=y2-y1;
   dx=x2-x1;
   m=dy/dx;
   printf("Slope m=%f",m);
   if(m>=-1 && m<0)
     {
      d=2*dy-dx;
      while(x1<=x2){
	putpixel(x1,y1,GREEN);
	d=d+2*dy;
	x1++;
	y1--;
	if(d>=0){
	   y1--;
	   d=d+2*dx;
	   }
	}

     }

   if(m<=1 && m>=0)
    {
     d=2*dy-dx;
     while(x1<=x2){
	   putpixel(x1,y1,YELLOW);
	   d=d+2*dy;
	   x1++;
	   if(d>=0){
	    y1++;
	    d=d-2*dx;
	      }

	   }
     }

     if(m>1){
     d=2*dx-dy;
     while(y1<=y2){
	putpixel(x1,y1,BLUE);
	d=d+2*dx;
	y1++;
	if(d>=0){
	  x1++;
	  d=d-2*dy;
		}
	    }
	}

     if(m<-1){
       d=2*dx-dy;
       while(y1>=y2){
	    putpixel(x1,y1,RED);
	    d=d+2*dx;
	    y1--;
	    if(d>=0){
	       x1++;
	       y1--;
	       d=d-2*dy;
	       }
	    }

     }

   }
   getch();
   closegraph();
   return 0;
}

