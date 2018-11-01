#include<stdio.h>
#include<conio.h>
void main(){
int a[10][10],b[100][3],i,m,n,t=0,j,c=0;
clrscr();
printf("A Program By Chanpreet Singh\n");
printf("Enrollment No-02113202717\n\n");
printf("Enter number of rows:");
scanf("%d",&m);
printf("Enter number of columns:");
scanf("%d",&n);
printf("Enter the matrix\n");
for(i=0;i<m;i++)
   {
   for(j=0;j<n;j++)
      {
       scanf("%d",&a[i][j]);
       if(a[i][j]!=0)
	  t++;
      }
   }
b[0][0]=m;
b[0][1]=n;
b[0][2]=t;

for(i=0;i<m;i++)
  {
   for(j=0;j<n;j++)
      {
	  if(a[i][j]!=0)
	  {
	    c++;
	    b[c][0]=i;
	    b[c][1]=j;
	    b[c][2]=a[i][j];

	  }
      }
  }
printf("\nThe sparce matrix is:\n");

for(i=0;i<=c;i++)
  {
   for(j=0;j<3;j++)
      printf("%-3d ",b[i][j]);
   printf("\n");
   }

getch();
}