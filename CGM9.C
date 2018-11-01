#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void multiply(int a[3][3],int b[3][3],int* c){
int i,j,k,sum=0;
for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
       {
	 for(k=0;k<3;k++){
	     sum=sum+a[i][k]*b[k][j] ;
	    }

	    c[i*3+j]=sum;
	sum=0;
       }
   }
return;
}

void main(){
int gdriver=DETECT,gmode,errorcode;
int a[3][3],b[3][3],c[3][3],sx,sy,sz,i,j;
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
scanf("%d%d",&a[0][0],&a[0][1]);
a[0][2]=1;
printf("\nEnter coordinate 2:") ;
scanf("%d%d",&a[1][0],&a[1][1]);
a[1][2]=1;
printf("\nEnter coordinate 3:") ;
scanf("%d%d",&a[2][0],&a[2][1]);
a[2][2]=1;
printf("Enter scaling factor:");
scanf("%d%d",&sx,&sy);
line(a[0][0],a[0][1],a[1][0],a[1][1]);
line(a[1][0],a[1][1],a[2][0],a[2][1]);
line(a[2][0],a[2][1],a[0][0],a[0][1]);
for(i=0;i<3;i++)
   for(j=0;j<3;j++)
      if(i!=j)
	b[i][j]=0;
b[0][0]=sx;
b[1][1] =sy;
b[2][2]=1;
multiply(a,b,&c);
for(i=0;i<3;i++)
  { for(j=0;j<3;j++)
	printf("%-5d ",c[i][j]);
    printf("\n");
   }
line(c[0][0],c[0][1],c[1][0],c[1][1]);
line(c[1][0],c[1][1],c[2][0],c[2][1]);
line(c[2][0],c[2][1],c[0][0],c[0][1]);
getch();
closegraph();
}

