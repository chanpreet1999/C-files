#include<stdio.h>
#include<conio.h>
#define max 100
int front=-1,rear=-1,q[max];

void push();
void pop();
void disp();

void main(){
int ch;
clrscr();
printf("\nA Program By Chanpreet Singh\n");
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
int item;
printf("Enter item to be inserted:");
scanf("%d",&item);
if(rear==-1)
      front=rear=0;
else if(rear==max-1){
      printf("\nOverflow") ;
      getch();
      return;
	}
else
      rear++;

q[rear]=item;
printf("Insertion  Sucessful") ;
}

void pop(){
if(front==-1||front>rear){
   printf("Underflow");
   }
else{
    printf("The element deleted is:%d",q[front]) ;
    front++;
   }
}

void disp(){
int i=0;
if(front==-1||front>rear)
	printf("Queue already empty") ;
else{
	printf("The queue is:");
	for(i=front;i<=rear;i++)
		printf("\n%d",q[i]);
    }
}