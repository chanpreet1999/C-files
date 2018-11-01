#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
int main()
{
int gddriven=DETECT,gmode,errorcode;
float xmax,ymax,xmin,ymin,x1,y1,x2,y2,a1,a2,a3,a4,b1,b2,b3,b4,y;
float m;
initgraph(&gddriven,&gmode,"C:\\TURBOC3\\BGI");
errorcode=graphresult();
if(errorcode!=grOk)
{
printf("graphics error:%s\n",grapherrormsg(errorcode));
printf("press any key to halt:");
getch();
exit(1);
}
printf("MADE BY CHANPREET");
printf("\nenter the max coordinates of windows");
scanf("%f%f",&xmax,&ymax);
printf("enter the min coordinates of windows");
scanf("%f%f",&xmin,&ymin);
printf("enter 1st coordinates of line");
scanf("%f%f",&x1,&y1);
printf("enter 2nd coordinates of line");
scanf("%f%f",&x2,&y2);
rectangle(xmin,ymin,xmax,ymax);
line(x1,y1,x2,y2);
if((y1-ymax)>=0)
a1=1;
else
a1=0;
if((ymin-y1)>=0)
a2=1;
else
a2=0;
if((x1-xmax)>=0)
a3=1;
else
a3=0;
if((xmin-x1)>=0)
a4=1;
else
a4=0;
if((y2-ymax)>=0)
b1=1;
else
b1=0;
if((ymin-y2)>=0)
b2=1;
else
b2=0;
if((x2-xmax)>=0)
b3=1;
else
b3=0;
if((xmin-x2)>=0)
b4=1;
else
b4=0;
if((a1||a2||a3||a4||b1||b2||b3||b4)==0)
{
printf("line is completely inside the window");
}
else if((a1&&b1)||(a2&&b2)||(a3&&b3)||(a4&&b4)==0)
{
printf("line is partially inside the window");
printf("\ncandidate for clipping");
m=(y2-y1)/(x2-x1);
y=(m*(xmax-x1))+y1;
rectangle(xmin+300,ymin,xmax+300,ymax);
line(x1+300,y1,xmax+300,y);
}
else
{
printf("line is completely outside the window");
}
getch();
closegraph();
return 0;
}