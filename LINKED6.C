#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
      int info;
      struct node *next;
}*start;

void push();
void pop();
void display();

void main(){
  int ch;
  clrscr();
  printf("A Program By Chanpreet Singh\n");
  printf("Enrollment No-02113202717\n\n");
  while(1){
	printf("\n\t\t\tMAIN MENU\n");
	printf("\t\t\t---------\n");
	printf("\t\t1 Push\n");
	printf("\t\t2 Pop\n");
	printf("\t\t3 Display\n");
	printf("\t\t4 Exit");
	printf("\n\t\tEnter your choice:");
	scanf("%d",&ch);
	switch(ch){
	case 1: push();
		break;
	case 2: pop();
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

void push(){
int info1;
struct node *node1;
struct node *node2=(struct node *)malloc(sizeof(struct node));
printf("\nEnter info:");
scanf("%d",&node2->info);
node2->next=NULL;
if(start==NULL)
   start=node2;
else{
      node1=start;
      while(node1->next!=NULL) {
	    node1=node1->next;
			    }
      node1->next=node2;
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
   return;
  }
else{
     node1=start;
     printf("\nThe linked list is:\n");
     while(node1!=NULL)
       {
	   printf("%d\n",node1->info);
	   node1=node1->next;
	}

    }
getch();
clrscr();
}

void pop(){
struct node *ptr1,*ptr2;
if(start==NULL)
  {
   printf("Underflow\n");
    return;
   }

ptr1=start;
ptr2=ptr1->next;
while(ptr2->next!=NULL)
   {
   ptr2=ptr2->next;
   ptr1=ptr1->next;
   }
printf("The info deleted is:%d\n",ptr2->info);
free(ptr2);
ptr1->next=NULL;
getch();
clrscr();
}
