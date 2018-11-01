#include<malloc.h>
#include<stdio.h>
#include<conio.h>
struct emp{
char name[50];
float sal;
int age;
};
void main(){
struct emp *ptr;
clrscr();
ptr=(struct emp *)malloc(sizeof(struct emp));
if(ptr==NULL)
   {
   printf("Memory allocation failure ABORDING!!");
   getch();
   exit(1);
   }
else{
     printf("Enter the details:");
     printf("\nName:");
     scanf("%s",&ptr->name);
     printf("Age:");
     scanf("%d",&ptr->age);
     printf("salary:");
     scanf("%f",&ptr->sal);
     printf("The details are:");
     printf("Name:%s\t\tAge:%d\t\tSallary:%f",ptr->name,ptr->age,ptr->sal);

     }

getch();
}