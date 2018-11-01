#include<stdio.h>
#include<conio.h>
void main(){
int a[10],h,temp,i,j,n;
clrscr();
printf("A Program By Anshuman Singh\n");
printf("Enter the no. of elements:");
scanf("%d",&n);
printf("\nEnter the array:");
for(i=0;i<n;i++)
   scanf("%d",&a[i]);
printf("\nInsertion sort starts");
for(i=1;i<n;i++)
   {
     h=i;
     while(h>0 && a[h]<a[h-1])
	  {
	   temp=a[h];
	   a[h]=a[h-1];
	   a[h-1]=temp;

	  h--;
	  }
   }
printf("\nAfter Sorting:");
for(i=0;i<n;i++)
    printf("%d ",a[i]);

getch();
}