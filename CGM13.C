#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main(){
int gdriver=DETECT,gmode,errorcode;
double px,py,x0,x1,x2,x3,y0,y1,y2,y3,u;
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI\\");
errorcode=graphresult();
if(errorcode!=grOk)
  {
   printf("Graph Error:%d",grapherrormsg(errorcode));
   printf("\nPress any key to hault!");
   getch();
   exit(1);
  }

printf("Enter coordinate 1: ");
scanf("%lf%lf",&x0,&y0);
printf("Enter coordinate 2: ");
scanf("%lf%lf",&x1,&y1);
printf("Enter coordinate 3: ");
scanf("%lf%lf",&x2,&y2);
printf("Enter coordinate 4: ");
scanf("%lf%lf",&x3,&y3);
for(u=0;u<=1;u+=0.01)
   { px=x0*pow(u,3)+x1*pow(u,2)*(1-u)+x2*u*pow((1-u),2)+x3*(1-u);
     py=y0*pow(u,3)+y1*pow(u,2)*(1-u)+y2*u*pow((1-u),2)+y3*(1-u);
     putpixel(px,py,15);
   }

getch();
closegraph();
}