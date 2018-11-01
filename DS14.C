#include<stdio.h>
#include<conio.h>
#define max 100

struct node{
  int data;
  struct node *next;
}*start=NULL,*end=NULL;


void push();
void pop();
void disp();

void main(){
int ch;
clrscr();
printf("A Program By Chanpreet Singh\n");
printf("\nMAIN MENU");
printf("\n1 Insert");
printf("\n2 Delete");
printf("\n3 Display");
printf("\nPress any other key to exit");
while(1){
    printf("\nEnter choice");
    scanf("%d",&ch);
    switch(ch){
	 case 1: push();
		 break;
	 case 2: pop();
		 break;
	 case 3: disp();
		 break;
	 default:printf("Exiting!");
		 getch();
		 exit(0);
	}
    }

getch();
}

void push(){
int data1;
struct node *new_node;
printf("Enter data:");
scanf("%d",&data1);
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data =data1;
new_node->next=NULL;
if(start==NULL)
   {
    start=new_node;
    end=new_node;
    }
else{
     end -> next=new_node;
     end=new_node;
	}

printf("Insertion successful");
getch();
}

void pop(){
if(start==NULL){
      printf("Underflow");
      getch();
      return;

	}
printf("Data deleted is:%d",start->data);
start=start->next;

getch();
}

void disp(){
struct node *x;

if(start==NULL)
	printf("\nQueue already empty");
else{
     printf("The queue is:");
     x=start;
     while(x!=NULL){
     printf("%d->",x->data);
     x=x->next;
	}
     printf("NULL");
    }
getch();
}