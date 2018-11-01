#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct tr
{
	int item;
	struct tr* left;
	struct tr* right;
}bst;

//--------------  Global variables


bst *save, *ptr,*parent,*node;
int ter=0,terrec=0,n=0;


//--------------  Functions


void create(bst *tree,int x)
{
	tree->left=tree->right=NULL;
	tree->item=x;
}
void insert(bst *tree,int x)
{
	ptr=(bst *)malloc(sizeof(bst)); //-----Memory Allocation
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
		printf("\n \t%d",p->item);
		inorder(p->right);
	}
}


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

void delete_node(bst *tree,int val)
{
		bst *ptr_del,*par_del,*save,*save1;
		ptr_del=tree;
		while(ptr_del->item!=val)
		{
			par_del=ptr_del;
			if(ptr_del->item>val)
			{
				ptr_del=ptr_del->left;
			}
			else
				ptr_del=ptr_del->right;
		}
		
		//--------------- if node has no child (terminal node)----
		
		if(ptr_del->left==ptr_del->right)//---when it is equal to NULL
		{
			if(ptr_del!=tree)
			{
				if(par_del->item>val)
				{
					par_del->left=NULL;
				}
				else
					par_del->right=NULL;
			}
			else
				tree=NULL;
				
				free(ptr_del);
		}
		
		//--------------- if node has one child 
		
		else if(ptr_del->left==NULL && ptr_del->right!=NULL)
		{
			if(ptr_del==tree)
			{
				tree=ptr_del->right;
			}
			else
			{
				if(par_del->item>ptr_del->item)
				{
					par_del->left=ptr_del->right;
				}
				else
				{
					par_del->right=ptr_del->right;
				}
				free(ptr_del);
			}
		}

		else if(ptr_del->right==NULL && ptr_del->left!=NULL)
		{
			if(ptr_del==tree)
			{
				tree=ptr_del->right;
			}
			else
			{
				if(par_del->item>ptr_del->item)
				{
					par_del->left=ptr_del->left;
				}
				else
				{
					par_del->right=ptr_del->left;
				}
				free(ptr_del);
			}
		}
		
		//------------------- if it has two child 
		else
		{
				save1=ptr_del->right;
				while(save1->left!=NULL)
				{
					save1=save1->left;
				}
				save1->left=ptr_del->left;
				if(ptr_del->right==tree)
				{
					tree=ptr_del->right;
				}
				else
				{
					if(par_del->item>ptr_del->item)
					{
						par_del->left=ptr_del->right;
					}
					else
					{
						par_del->right=ptr_del->right;
					}
					free(ptr_del);
				}
		}
}		
int main()
{
	int choice,x;
	char ans;
	bst *root;
	clrscr();
	printf("A Program by Chanpreet  Singh\n");
	printf("\n 1.Create");
	printf("\n 2.Insert");
	printf("\n 3.Inorder");
	printf("\n 4.Display");
	printf("\n 5.Delete");
	do
	{
		fflush(stdin);
		printf("\nEnter Choice   ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: root=(bst *)malloc(sizeof(bst));
					printf("\n\tEnter no   ");
					scanf("%d",&x);
					create(root,x);
					break;
			
			case 2: printf("\n\t Enter no  ");
					scanf("%d",&x);
					insert(root,x);
					break;
			
			case 3: inorder(root);
					break;
			case 4:	display(root,1);
					break;
			
			case 5: printf("\n\t Enter no to be deleted ");
					scanf("%d",&x); 
					delete_node(root,x);
					break;
		}
		fflush(stdin);
			printf("\n Want to Continue ");
			scanf("%c",&ans);
	}while(ans=='y');
	getch();
return 0;
}
