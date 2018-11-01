#include<stdio.h>
#include<conio.h>
#define capacity 5
int top=-1,stack[capacity];

void push();
void pop();
void traverse();
int isFull();
int isEmpty();
void peak();

void main(){
int ch;
clrscr();
while(1){
printf("\nMAIN MENU");
printf("\n1 push");
printf("\n2 pop");
printf("\n3 teaverse");
printf("\n4 peak");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch){
       case 1: push();
	      break;
       case 2:
	       pop();
	       break;
       case 3: traverse();
	      break;
       case 4: peak();
		break;
       default: printf("\Exiting");
		getch();
		exit(1);
	}
}
getch();
}

void push(){		//insertion into stack
int ele;
if(isFull())
   printf("Stack full!");

else{
    printf("Enter element to be inserted");
    scanf("%d",&ele);
    top++;
    stack[top]=ele;
    printf("Insertion successful");
    }
}

void pop(){
if(isEmpty())
   printf("Stack is already empty");

else{
    printf("Element deleted is:%d",stack[top]);
    top--;
       }
}

void peak(){
if(isEmpty())
   printf("Stack is already empty");

else{
    printf("Element at the peak is:%d",stack[top]);

       }
}

int isFull(){
if(top==capacity-1)
  return 1;
else
  return 0;
}

int isEmpty(){
if(top==-1)
  return 1;
else
  return 0;
}

void traverse(){
int i=0;
printf("The stack elements are:");
for(i=0;i<=top;i++)
   printf("%d\n",stack[i]);
}