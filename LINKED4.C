#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>

struct node{
      int info;
      char name[20];
      struct node *next;
      struct node *prev;
}*start,*end;

void InsertBeg();
void display();
void DeletionEnd();

void main(){
  int ch;
  clrscr();
  printf("\nA Program By Chanpreet Singh");
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
char name1[20];
struct node *new_node;
new_node=(struct node *)malloc(sizeof(struct node));
printf("\nEnter name of new employee:");
scanf("%s",&name1);
strcpy(new_node->name,name1);
printf("\nEnter ID of new employee:");
scanf("%d",&new_node->info);
if(start==NULL)
  start=end=new_node;
else{
       new_node->prev=NULL;
       new_node->next=start;
       start->prev=new_node;
       start=new_node;

      }
printf("\nInsertion Successful\n");
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
	   printf("ID:%d\t\tName:%s\n",node1->info,node1->name);
	   node1=node1->next;
	}

    }
}

void DeletionEnd(){
struct node *q;
if(end==NULL)
  {
   printf("Underflow\n");
    return;
   }
q=end;
end=end->prev;
if(end!=NULL)
  {
   end->next=NULL;
  }
printf("The record deleted is:\t\tID:%d\t\tName:%s\n",q->info,q->name);
free(q);
}
