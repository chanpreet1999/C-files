#include<stdio.h>
#include<conio.h>
int top=-1,max=50;stack[50];

void push();
void pop();
void disp();

void main(){
int n,ch;
int ctr=0;
clrscr();
printf("A Program By Chanpreet Singh\n");
printf("Enrollment No-02113202717\n\n");
printf("Enter size of STACK:");
scanf("%d",&n);
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
		case 3: disp();
			break;
		case 4: printf("Exiting!!");
			getch();
			exit(0);
		default: printf("Wrong Choice!!");
		}
	}
getch();
}

void push(){
int ele;
if(top==max-1){
       printf("Overflow");
       getch();
       clrscr();
       return;
    }
top++;
printf("Enter the element to be inserted:");
scanf("%d",&ele);
stack[top]=ele;
printf("Insertion Successful\n");
getch();
clrscr();
}

void pop() {
if(top==-1)
   {
   printf("Underflow\n");
   getch();
   clrscr();
   return;
   }
printf("Element Deleted is:%d\n",stack[top]);
top--;
printf("Deletion Successful\n");
getch();
clrscr();
}

void disp(){
int i;
if(top==-1){
	printf("Stack is already empty\n");
	return;
	}
printf("The stack is:\n");
for(i=top;i>=0;i--)
    printf("\t\t%d\n",stack[i]);
getch();
clrscr();
}