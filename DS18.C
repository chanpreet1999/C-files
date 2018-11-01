#include<stdio.h>
#include<conio.h>
void main(){
int a[10],i,j,n,temp;
clrscr();
printf("A Program By Chanpreet Singh\n");
printf("Enter the no. of elements:");
scanf("%d",&n);
printf("\nEnter the array:");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
	{
	if(a[i]>a[j])
	  {
	   temp=a[i];
	   a[i]=a[j];
	   a[j]=temp;

	  }
	}
   }
printf("\nOrder of sorted elements(selection sort):");
for(i=0;i<n;i++)
   printf("%d ",a[i]);

getch();
}