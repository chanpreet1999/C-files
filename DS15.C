#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct tr
{
	int item;
	struct tr* left;
	struct tr* right;
}bst;

bst *save, *ptr,*parent,*node;
int ter=0,terrec=0,n=0;

void display(bst *ptr, int level){
	int i;
	if(ptr!=NULL){
		display(ptr->right, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->item);
		display(ptr->left, level+1);
	}
}
void create(bst *tree,int x)
{
	tree->left=tree->right=NULL;
	tree->item=x;
}
void insert(bst *tree,int x)
{
	ptr=(bst *)malloc(sizeof(bst));
	ptr->left=ptr->right=NULL;
	ptr->item=x;
	node=tree;
	while(node!=NULL)
	{
		 parent=node;
		 if(x<(node->item))
		 {
			 node=node->left;
		 }
		 else
		 {
			node=node->right;
		 }
	}
	if(x<parent->item)
	{
		parent->left=ptr;
	}
	else
	{
		parent->right=ptr;
	}
}
void inorder(bst *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("\t%d",p->item);
		inorder(p->right);
	}
}
void preorder(bst *p)
{
	if(p!=NULL)
	{
		printf("\t%d",p->item);
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(bst *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("\t%d",p->item);
	}
}
int main()
{
	int choice,x;
	char ans;
	bst *root;
	clrscr();
	printf("A Program By Chanpreet Singh\n");

	printf("\n 1.Create");
	printf("\n 2.Insert");
	printf("\n 3.Inorder");
	printf("\n 4.Preorder");
	printf("\n 5.Postorder");
	printf("\n 6.display");
	do
	{
		fflush(stdin);
		printf("\nEnter Choice   ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: root=(bst *)malloc(sizeof(bst));
					printf("\n  Enter no   ");
					scanf("%d",&x);
					create(root,x);
					break;
			
			case 2: printf("\n  Enter no  ");
					scanf("%d",&x);
					insert(root,x);
					break;
			
			case 3: inorder(root);
					break;
			
			case 4: preorder(root);
					break;
			
			case 5: postorder(root);
					break;
			case 6: display(root,1);
		}
		fflush(stdin);
			printf("\nWant to Continue ");
			scanf("%c",&ans);
	}while(ans=='y');
	getch();
return 0;
}
