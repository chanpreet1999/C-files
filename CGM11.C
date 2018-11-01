#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void multiply(float a[3][3],float b[3][3],float c[3][3]){
int i,j,k;
float sum=0;
for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
       {
	 for(k=0;k<3;k++){
	     sum=sum+a[i][k]*b[k][j] ;
	    }

	    c[i][j]=sum;
	sum=0;
       }
   }
return;
}

void main(){
int gdriver=DETECT,gmode,errorcode;
float a[3][3],b[3][3],c[3][3],d[3][3],e[3][3],f[3][3],g[3][3],x,y;
int i,j;
clrscr();
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI\\");
errorcode=graphresult();
if(errorcode!=grOk)
  {
   printf("Graph Error:%d",grapherrormsg(errorcode));
   printf("\nPress any key to hault!");
   getch();
   exit(1);
  }
printf("\nEnter coordinate 1:") ;
scanf("%f%f",&a[0][0],&a[0][1]);
a[0][2]=1;
printf("\nEnter coordinate 2:") ;
scanf("%f%f",&a[1][0],&a[1][1]);
a[1][2]=1;
printf("\nEnter coordinate 3:") ;
scanf("%f%f",&a[2][0],&a[2][1]);
a[2][2]=1;
printf("Enter angle:");
scanf("%f",&y);
line(a[0][0],a[0][1],a[1][0],a[1][1]);
line(a[1][0],a[1][1],a[2][0],a[2][1]);
line(a[2][0],a[2][1],a[0][0],a[0][1]);
for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
     { if(i==j)
       {   b[i][j]=1;
	   d[i][j]=1;
       }
      else {
	    b[i][j]=0;
	    d[i][j]=0;
	   }
     }
   }
b[2][0]=-a[0][0];
b[2][1]=-a[0][1];
d[2][0]=a[0][0];
d[2][1]=a[0][1];

x=(3.14*y)/180;
c[0][0]=cos(x);
c[0][1]=sin(x);
c[0][2]=0;
c[1][0]=-sin(x);
c[1][1]=cos(x);
c[1][2]=0;
c[2][0]=0;
c[2][1]=0;
c[2][2]=1;


multiply(a,b,e);
multiply(e,c,f);
multiply(f,d,g);
for(i=0;i<3;i++)
  { for(j=0;j<3;j++)
	printf("%f ",c[i][j]);
    printf("\n");
   }
line(g[0][0],g[0][1],g[1][0],g[1][1]);
line(g[1][0],g[1][1],g[2][0],g[2][1]);
line(g[2][0],g[2][1],g[0][0],g[0][1]);
getch();
closegraph();
}