#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *tree=NULL;

struct node *insertNode(struct node* tree, int val);
struct node *deleteNode(struct node* tree,int val);
void inorderDisplay(struct node *temp);
void preorderDisplay(struct node *temp);
void postorderDisplay(struct node *temp);

int main()
{
	int option=0,val;
	printf("\nMaking a tree!\n");
	
	do
	{
		printf("1.Insert\t2.Delete\t3.Inorder\t4.Postorder\t5.Preorder\t6.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1: printf("Enter value\n");
					scanf("%d",&val);
					tree=insertNode(tree, val);
					break;
			
			case 2: printf("Enter value\n");
					scanf("%d",&val);
					deleteNode(tree, val);
					break;
			
			case 3: printf("Displaying\n");
					inorderDisplay(tree);
					printf("\n");
					break;
					
			case 4: printf("Displaying\n");
					postorderDisplay(tree);
					printf("\n");
					break;
					
			case 5: printf("Displaying\n");
					preorderDisplay(tree);
					printf("\n");
					break;		
			
			case 6: printf("Exit\n");
					exit(1);
					break;
		}
	}while(option!=6);
	
return 0;		

}		
		
		
struct node *insertNode(struct node *tree, int val)
{
	struct node *ptr,*temp,*pre;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	
	
	if(tree==NULL)
	{
		tree=ptr;
	} else {
		
		temp=tree;
		
		while(temp!=NULL)
		{
			pre=temp;
			if(val<temp->data)
			{
				temp=temp->left;
			}else{
				
				temp=temp->right;
			}
		}
		if(val<pre->data)
		{
			pre->left=ptr;
		} else {
			
			pre->right=ptr;
		}
		}
		ptr->left=NULL;
		ptr->right=NULL;
		
return tree;

}



void inorderDisplay(struct node *temp)
{
	if(temp!=NULL)
	{
		inorderDisplay(temp->left);
		printf("%d\t",temp->data);
		inorderDisplay(temp->right);
	}
}
		

void postorderDisplay(struct node *temp)
{
	if(temp!=NULL)
	{
		postorderDisplay(temp->left);
		postorderDisplay(temp->right);
		printf("%d\t",temp->data);
		
	}
}	
	
			
		
void preorderDisplay(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("%d\t",temp->data);
		preorderDisplay(temp->left);		
		preorderDisplay(temp->right);
	}
}		
		
struct node *deleteNode(struct node* tree, int val)
{
	struct node *temp,*par;
	temp=tree;
	
	if(tree==NULL)
	{
		printf("Tree is empty.\n");	
		return tree;	
	}
	while(temp->data!=val||temp==NULL)
	{
		par=temp;
		if(val<temp->data)
		{
			temp=temp->left;
		} else {
			temp=temp->right;
		}
	}
	if(temp==NULL)
	{
		printf("Value not present!");
		return tree;
	}
	
	if(temp->left==NULL&&temp->right!=NULL)
	{
		if(par->data<temp->data)
		par->right=temp->right;
		else
		par->left=temp->right;
		free(temp);
		return tree;
	}
	
	if(temp->right==NULL&&temp->left!=NULL)
	{
			if(par->data<temp->data)
			par->right=temp->left;
			else
			par->left=temp->left;
			free(temp);
			return tree;
	}
		
		
	if(temp->left==NULL&&temp->right==NULL)
	{
		free(temp);
		return tree;
	}
	if(temp->left!=NULL&&temp->right!=NULL)
	{	
		struct node *suc;
		suc=temp->right;
		while(suc->left!=NULL)
		{	
			suc=suc->left;
		}
		temp->data=suc->data;
		suc=deleteNode(temp->right,suc->data);
		return tree;
	}	
	
}	
	
	
/*
OUTPUT:

akshay@akshay-MacBookPro:~/Desktop$ gcc tree.c -o t
akshay@akshay-MacBookPro:~/Desktop$ ./t

Making a tree!
1.Insert	2.Delete	3.Inorder	4.Postorder	5.Preorder	6.Exit
1
Enter value
4
1.Insert	2.Delete	3.Inorder	4.Postorder	5.Preorder	6.Exit
1
Enter value
3
1.Insert	2.Delete	3.Inorder	4.Postorder	5.Preorder	6.Exit
1
Enter value
5
1.Insert	2.Delete	3.Inorder	4.Postorder	5.Preorder	6.Exit
1
Enter value
2
1.Insert	2.Delete	3.Inorder	4.Postorder	5.Preorder	6.Exit
1
Enter value
6
1.Insert	2.Delete	3.Inorder	4.Postorder	5.Preorder	6.Exit
3
Displaying
2	3	4	5	6	
1.Insert	2.Delete	3.Inorder	4.Postorder	5.Preorder	6.Exit
4
Displaying
2	3	6	5	4	
1.Insert	2.Delete	3.Inorder	4.Postorder	5.Preorder	6.Exit
5
Displaying
4	3	2	5	6	
1.Insert	2.Delete	3.Inorder	4.Postorder	5.Preorder	6.Exit
2
Enter value
3
1.Insert	2.Delete	3.Inorder	4.Postorder	5.Preorder	6.Exit
3
Displaying
2	4	5	6	
1.Insert	2.Delete	3.Inorder	4.Postorder	5.Preorder	6.Exit
6
Exit

*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
		





