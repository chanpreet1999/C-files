// Q10. Convert infix expression to postfix expression using stack.

#include<conio.h>
#include<stdio.h>
#include<string.h>

char st[30];
int top=-1,max=30;
char infix[30], postfix[30];

void push(char st[],char val)
{
 if(top==max-1)
 printf("\n Overflow");
 else
 {
  top++;
  st[top]=val;
 }
}

char pop(char st[])
{
 char val=' ';
 if(top==-1)
 printf("\n Underflow");
 else
 {
  val=st[top];
  top--;
 }
 return val;
}

void intopost(char source[], char target[])
{
 int i=0,j=0;
 char temp;
 strcpy(target," ");
 while(source[i]!='\0')
 {
  if(source[i]=='(')
  {
   push(st,source[i]);
   i++;
  }
  else if(source[i]==')')
  {
   while((top!=-1)&&(st[top]!='('))
   {
    target[j]=pop(st);
    j++;
   }
   if(top==-1)
   {
    printf("\n Incorrect expression" );
    return;
   }
   temp=pop(st);
   i++;
  }
  else if(isalnum(source[i]))
  {
   target[j]=source[i];
   j++;
   i++;
  }
  else if(source[i]=='^'||source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%')
  {
   while((top!=-1)&&(st[top]!='(')&&(priority(st[top])>priority(source[i])))
   {
    target[j]=pop(st);
    j++;
   }
   push(st,source[i]);
   i++;
  }
  else
  {
   printf("\n Incorrect element");
  }
 }
 while((top!=-1)&&(st[top]!='('))
 {
  target[j]=pop(st);
  j++;
 }
 target[j]='\0';
}

int priority(char op)
{
 if(op=='^')
 return 2;
 else if(op=='/'||op=='%'||op=='*')
 return 1;
 else if(op=='+'||op=='-')
 return 0;
 else
 return -1;
}

void main()
{
 clrscr();
 printf("\nA Program By Chanpreet Singh\n");
 printf("\n Enter infix expression : ");
 gets(infix);
 strcpy(postfix," ");
 intopost(infix,postfix);
 printf("\n Postfix expression : ");
 puts(postfix);
 getch();
}