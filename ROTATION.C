#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
void matrix(float a[3][3],float b[3][3],float c[3][3])
{
int i,j,k,sum;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
sum=0;
for(k=0;k<3;k++)
{
sum+=a[i][k]*b[k][j];
}
c[i][j]=sum;
}
}
}
void main()
{
int gddriven=DETECT,gmode,errorcode;
float i,j,m[3][3],n[3][3],Q,q,k[3][3],p[3][3],r[3][3],k1[3][3],k2[3][3];
float x1,x2,x3,y1,y2,y3,a,b,c,d,e,f;
clrscr();
initgraph(&gddriven,&gmode,"C:\\TURBOC3\\BGI");
errorcode=graphresult();
if(errorcode!=grOk)
{
printf("graphics error:%s\n",grapherrormsg(errorcode));
printf("press any key to halt:");
getch();
exit(1);
}
else
{
printf("\nEnter coordinate 1:");
scanf("%f%f",&x1,&y1);
printf("\nEnter coordinate 2:");
scanf("%f%f",&x2,&y2);
printf("\nEnter coordinate 3:");
scanf("%f%f",&x3,&y3);
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x1,y1);
printf("Enter angle of rotation");
scanf("%f",&Q);
q=(Q*3.14)/180;
m[0][0]=x1;
m[0][1]=y1;
m[0][2]=1;
m[1][0]=x2;
m[1][1]=y2;
m[1][2]=1;
m[2][0]=x3;
m[2][1]=y3;
m[2][2]=1;
n[0][0]=cos(q);
n[0][1]=sin(q);
n[0][2]=0;
n[1][0]=-sin(q);
n[1][1]=cos(q);
n[1][2]=0;
n[2][0]=0;
n[2][1]=0;
n[2][2]=1;
p[0][0]=1,p[0][1]=0,p[0][2]=0;
p[1][0]=0,p[1][1]=1,p[1][2]=0;
p[2][0]=-x1,p[2][1]=-y1,p[2][2]=1;
r[0][0]=1,r[0][1]=0,r[0][2]=0;
r[1][0]=0,r[1][1]=1,r[1][2]=0;
r[2][0]=x1,r[2][1]=y1,r[2][2]=1;
matrix(m,p,k1);
matrix(k1,n,k2);
matrix(k2,r,k);
a=k[0][0];
b=k[0][1];
c=k[1][0];
d=k[1][1];
e=k[2][0];
f=k[2][1];
line(a,b,c,d);
line(c,d,e,f);
line(e,f,a,b);
getch();
}
closegraph();
}