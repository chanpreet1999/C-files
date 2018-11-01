#include<stdio.h>
#include<conio.h>
void main(){
int i,j,temp,a[10],n;
clrscr();
printf("Enter the no. of elements:");
scanf("%d",&n);
printf("\nEnter the array:");
for(i=0;i<n;i++)
   scanf("%d",&a[i]);
printf("\nBubble Sort starts");
for(i=0;i<n-1;i++)
   {
    for(j=0;j<n-1-i;j++)
       {
	if(a[j]>a[j+1])
	  {
	  temp=a[j];
	  a[j]=a[j+1];
	  a[j+1]=temp;
	  }
       }
   }

for(i=0;i<n;i++)
    printf("%d\n",a[i]);
getch();
}