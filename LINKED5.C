#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>

struct node{
      int info;
      char name[20];
      struct node *next;
}*start,*end;

void InsertBeg();
void display();
void DeletionEnd();

void main(){
  int ch;
  clrscr();
  printf("A Program By Chanpreet Singh\n");
  printf("Enrollment No-02113202717\n\n");
  while(1){

	printf("\n\t\t\tMAIN MENU\n");
	printf("\t\t\t---------\n");
	printf("\t\t1 Insertion At Beginning\n");
	printf("\t\t2 Deletion From End\n");
	printf("\t\t3 Display\n");
	printf("\t\t4 Exit");
	printf("\n\t\tEnter your choice:");
	scanf("%d",&ch);
	switch(ch){
	case 1: InsertBeg();
		break;
	case 2: DeletionEnd();
		break;
	case 3: display();
		break;
	case 4: printf("Exiting!!");
		getch();
		exit(1);
	default: printf("Wrong Choice!!");

		}
	}
  getch();
}

void InsertBeg(){
int info1;
struct node *new_node;
new_node=(struct node *)malloc(sizeof(struct node));
printf("\nEnter name of new student:");
scanf("%s",&new_node->name);
printf("\nEnter College ID of new student:");
scanf("%d",&new_node->info);
if(start==NULL){
  start=end=new_node;
  new_node->next=end;
	}
else{
       new_node->next=start;
       start=new_node;
       end->next=start;
	}
printf("\nInsertion Successful\n");
getch();
clrscr();
}

void display(){
struct node *node1;
if(start==NULL)
  {
   printf("\nList is already empty");
   getch();
   clrscr();
   return;
  }
node1=start;
printf("\nThe linked list is:\n");
while(node1!=end)
       {
	   printf("College ID:%d\t\tName:%s\n",node1->info,node1->name);
	   node1=node1->next;
	}
printf("College ID:%d\t\tName:%s\n",node1->info,node1->name);
getch();
clrscr();
}

void DeletionEnd(){
struct node *ptr1,*ptr2;
if(start==NULL)
  {
   printf("Underflow\n");
    getch();
    clrscr();
    return;
   }

ptr1=start;
ptr2=ptr1->next;
while(ptr2!=end)
   {
   ptr2=ptr2->next;
   ptr1=ptr1->next;
   }
printf("The record deleted is:\t\tCollege ID:%d\t\tName:%s\n",ptr2->info,ptr2->name);
free(ptr2);
end=ptr1;
end->next=start;
getch();
clrscr();
}