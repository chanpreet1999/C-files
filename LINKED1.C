#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
      int info;
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
  int ch;
  clrscr();
  printf("\nA Program By Chanpreet Singh");
  while(1){

	printf("\n\t\tMAIN MENU\n");
	printf("\t\t1 Insertion At Beginning\n");
	printf("\t\t2 Insert At End\n");
	printf("\t\t3 Insert At A User Defined Position\n");
	printf("\t\t4 Display\n");
	printf("\t\t5 Deletion From Beginning\n") ;
	printf("\t\t6 Deletion From End\n");
	printf("\t\t7 Deletion From A User Defined Position\n");
	printf("\t\t8 Reverse the Linked List\n");
	printf("\t\t9 Count \n");
	printf("\t\t10 Exit");
	printf("\n\t\tEnter your choice:");
	scanf("%d",&ch);
	switch(ch){
	case 1: InsertBeg();
		break;
	case 2: InsertEnd();
		break;
	case 3: InsertMid();
		break;
	case 4: display();
		break;
	case 5: DeletionBeg();
		break;
	case 6: DeletionEnd();
		break;
	case 7: DeletionMid();
		break;
	case 8: rev();
		break;
	case 9: count();
		break;
	case 10: printf("Exiting!!");
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
clrscr();
new_node=(struct node *)malloc(sizeof(struct node));
printf("\nEnter info of new node:");
scanf("%d",&info1);
new_node->info=info1;
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
clrscr();
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
	   printf("%d ->",node1->info);
	   node1=node1->next;
	}
     printf("NULL\n");

    }
}

void DeletionBeg(){
struct node *del;
clrscr();
if(start==NULL){
   printf("\nList is already empty");
   return;
  }
else{
	del=start;
	start=start->next;
	printf("Node deleted is:%d\n",del->info);
	free(del);
    }
}

void count(){
int ctr=0;
struct node *x;
clrscr();
x=start;
while(x!=NULL)
     {
	x=x->next;
	ctr++;
     }
printf("The number of nodes are:%d",ctr);
}

void InsertEnd(){
int info1;
struct node *node1;
struct node *node2=(struct node *)malloc(sizeof(struct node));
printf("\nEnter info of new node:");
scanf("%d",&info1);
node2->info=info1;
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
printf("The node deleted is:%d\n",q->info);
free(q);
p->next=NULL;
}

void InsertMid(){
struct node *new_node=(struct node *)malloc(sizeof(struct node));
struct node *q,*p;
int loc,i;
clrscr();
p=start;
q=p->next;
printf("\nEnter the position where you want to enter the node:");
scanf("%d",&loc);
printf("Enter the info of the new node:");
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
clrscr();
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
printf("The node deleted is:%d\n",q->info);
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