#include<stdio.h>
#include<conio.h>
#define max 50
#include<string.h>
char stack[max],expression[max];
int top=-1,k=-1;
void push(char*);
void pop(char*);
int priority(char*);
void main()
{
  char str[50];
  int i=0;
  clrscr();
  printf("Enter the infix expression:");

  scanf("%s",&str);
  str[strlen(str)+1]=')';
  for(i=0;str[i]!='\0';i++)
  {
      if(str[i]=='('|| str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='$'||str[i]=='^')
	 push(&str[i])	;
      else if(str[i]==')')
	    { while(stack[i]!='(')
	       pop(&stack[i]);
	       pop(&stack[i]);
	    }
      else
      {
	k++;
	expression[k]=str[i];

      }
  }
printf("Postfix expression is:\n");
for(i=0;expression[i]!='\0';i++)
printf("%c ",expression[i]);

getch();
}



void push(char *ele){
int i,p,q;
if(top==-1)
  {
  top++;
  stack[top]='(';
  }
if(top==max-1)
  {
   printf("Overflow\n");
   return;
   }

else {
       top++;
       stack[top]= *ele;
      }
for(i=1;i<=top;i++)
  {
   p=priority(&stack[top]);
   q=priority(&stack[top-i]);
   if(q>=p)
       {
	pop(&stack[top-i]);
       }
   }
}



void pop(char *ele)
{
  if(top==-1)
     {
      printf("Underflow\n");
      return;
      }
  k++;
  expression[k]=stack[top];
  top--;

}


int priority(char *ele)
{
  if(*ele=='$'||*ele=='^')
      return 3;

  else if(*ele=='*'||*ele=='/')
      return 2;

  else if(*ele=='+'||*ele=='-')
       return 1;
  else
       return 0;

}