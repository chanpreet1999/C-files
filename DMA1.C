#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main(){
int n,*arr,i;
printf("Enter the size of the array:");
scanf("%d",&n);
arr=(int *)calloc(n,sizeof(int));
printf("Memory allocation successful");
for(i=0;i<n;i++)
scanf("%d",&*(arr+i));
getch();
}