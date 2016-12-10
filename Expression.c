#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct node
{
	char data;
	struct node *left;
	struct node *right;
};

struct node *tree=NULL;
struct node *stack[MAX];
int top=-1;

void push(struct node *val)
{
 if(top==MAX-1)
 {
 	printf("Stack Overflow");
 } else {
 	
 	
 	top++;
    stack[top]=val;
 	
 }
}


struct node *pop(){

struct node *val;
	if(top==-1){
	printf("Stack underflow");
	} else {
	
	val=stack[top--];
	return val;
	}
return 0;
}



struct node *create(char val,struct node *op1, struct node *op2)
{
	struct node *nn,*temp,*pre;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=val;
	nn->left=op1;
	nn->right=op2;
	
	
	
				
return nn;

}



void inorderDisplay(struct node *temp)
{
	if(temp!=NULL)
	{
		inorderDisplay(temp->left);
		printf("%c\t",temp->data);
		inorderDisplay(temp->right);
	}
}


int main()
{
	char postfix[10];
	int i=0;
	struct node *temp,*op1,*op2;
	printf("\nEnter Expression tree:");
	
	scanf("%s",postfix);
	
	while(postfix[i]!='\0')
	{	
		if(isalpha(postfix[i]))
		{	
			temp=create(postfix[i],NULL,NULL);
			push(temp);
			
		}
		else
		{
			op2=pop();
			op1=pop();
			temp=create(postfix[i],op1,op2);
			push(temp);
		}
		
		i++;
	}
	
	tree=pop();
	
	printf("\n");
	
	inorderDisplay(tree);
	
			
			
return 0;		

}		
		
		
/* 
OUTPUT:

student:~/Desktop/Akshay$ gcc Expression.c -o e
student@student-HP-ProOne-400-G1-AiO
student:~/Desktop/Akshay$ ./e

Enter Expression tree:AB+

A	+	B	
	
student@student-HP-ProOne-400-G1-AiO
student:~/Desktop/Akshay$ ./e

Enter Expression tree:AB+C*

A	+	B	*	C	

	
*/	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
		





