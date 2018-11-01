#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
struct node{
      int info;
      char name[20];
      struct node *next;
}*start;

void InsertBeg();
void display();
void DeletionBeg();
void count();
void InsertEnd();
void DeletionEnd();
void InsertMid();
void DeletionMid();
void rev();

void main(){
  int ch,i,n;
  clrscr();
  printf("\nA Program By Chanpreet Singh");
  while(1){

	printf("\n\t\t\tMAIN MENU\n");
	printf("\t\t\t---------\n");
	printf("\t\t1 Create a Linked List\n");
	printf("\t\t2 Insertion At Beginning\n");
	printf("\t\t3 Insert At End\n");
	printf("\t\t4 Insert At A User Defined Position\n");
	printf("\t\t5 Display\n");
	printf("\t\t6 Deletion From Beginning\n") ;
	printf("\t\t7 Deletion From End\n");
	printf("\t\t8 Deletion From A User Defined Position\n");
	printf("\t\t9 Reverse the Linked List\n");
	printf("\t\t10 Count \n");
	printf("\t\t11 Exit");
	printf("\n\t\tEnter your choice:");
	scanf("%d",&ch);
	switch(ch){
	case 1:  printf("\nEnter the no of nodes to be created:");
		 scanf("%d",&n);
		 for(i=1;i<=n;i++)
		   {
		     printf("\nEnter details ofstudent %d",i);
		     InsertEnd();
		    }
		 break;
	case 2:  InsertBeg();
		 break;
	case 3:  InsertEnd();
		 break;
	case 4:  InsertMid();
		 break;
	case 5:  display();
		 break;
	case 6:  DeletionBeg();
		 break;
	case 7:  DeletionEnd();
		 break;
	case 8:  DeletionMid();
		 break;
	case 9:  rev();
		 break;
	case 10: count();
		 break;
	case 11: printf("Exiting!!");
		 getch();
		 exit(0);
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
printf("\nEnter name of new student:");
scanf("%s",&name1);
strcpy(new_node->name,name1);
printf("\nEnter Roll No. of new student:");
scanf("%d",&new_node->info);
if(start==NULL)
  start=new_node;
else{
       new_node->next=start;
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
	   printf("Roll No:%d\t\tName:%s\n",node1->info,node1->name);
	   node1=node1->next;
	}

    }
}

void DeletionBeg(){
struct node *del;
if(start==NULL){
   printf("\nList is already empty");
   return;
  }
else{
	del=start;
	start=start->next;
	printf("Record deleted is:\tRoll No:%d\t\tName:%s\n",del->info,del->name);
	free(del);
    }
}

void count(){
int ctr=0;
struct node *x;
x=start;
while(x!=NULL)
     {
	x=x->next;
	ctr++;
     }
printf("The number of Records are:%d",ctr);
}

void InsertEnd(){
int info1;
struct node *node1;
char name1[20];
struct node *node2=(struct node *)malloc(sizeof(struct node));
printf("\nEnter name of new student:");
scanf("%s",&name1);
strcpy(node2->name,name1);
printf("\nEnter Roll No of new student:");
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
}

void DeletionEnd(){
struct node *p,*q;
if(start==NULL)
  {
   printf("Underflow\n");
    return;
   }

p=start;
q=p->next;
while(q->next!=NULL)
   {
   q=q->next;
   p=p->next;
   }
printf("The record deleted is:\t\tRoll No:%d\t\tName:%s\n",q->info,q->name);
free(q);
p->next=NULL;
}

void InsertMid(){
struct node *new_node=(struct node *)malloc(sizeof(struct node));
struct node *q,*p;
int loc,i;
char name1[20];
p=start;
q=p->next;
printf("\nEnter the position where you want to enter the node:");
scanf("%d",&loc);
printf("\nEnter name of new student:");
scanf("%s",&name1);
strcpy(new_node->name,name1);
printf("Enter the Roll no of the new node:");
scanf("%d",&new_node->info);
for(i=1;i<loc-1;i++)
   {
   p=p->next;
   q=q->next;
   }
p->next=new_node;
new_node->next=q;
printf("\nInsertion Successful\n");
}

void DeletionMid(){
struct node *q,*p;
int loc,i;
p=start;
q=p->next;
printf("\nEnter the position of the node to be deleted:");
scanf("%d",&loc);
for(i=1;i<loc-1;i++)
   {
   p=p->next;
   q=q->next;
   }
p->next=q->next;
printf("The Record deleted is:\t\tRoll no:%d\t\tName:%s\n",q->info,q->name);
free(q);
}

void rev(){
struct node *prev,*current,*next;
current=start;
prev=next=NULL;
while(current!=NULL){
	next=current->next;
	current->next=prev;
	prev=current;
	current=next;
	}
start=prev;
printf("\nLinked List Reversed\n");
}