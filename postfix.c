#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top=-1;
void push(char element);
char pop();
void infixtopostfix(char source[],char target[]);
int getpriority(char op);



void main(){

	char infix[MAX],postfix[MAX];
	printf("Enter infix expression: \n");
	scanf("%s",infix);
	
	infixtopostfix(infix,postfix);
	
	printf("Postfix Expression is: \n");
	puts(postfix);
	

}

void infixtopostfix(char source[],char target[])
{
	int i=0,j=0;
	char temp;
	strcpy(target,"");
	
	while(source[i]!='\0')
	{
	 
	 	if(source[i]=='(')
		{
		 	push('(');
		 	i++;
	 	
	 	} else if(source[i]==')'){
	 	 	
	 	 	while((top!=-1)&&stack[top]!='(')
	 	 	
			{	
				target[j]=pop();
				j++;
			}
	
			if(top==-2)
			{
				printf("Invalid expression\n");
				exit(1);
			} else {
				temp=pop();
			}
			
			i++;
			
		} else if(isdigit(source[i])||isalpha(source[i])){
			
			target[j]=source[i];
			j++;
			i++;
		} else if (source[i] == '+' || source[i] == '–' || source[i] == '*' ||
			   source[i] == '/' || source[i] == '%')
		{
			if(getpriority(source[i])<getpriority(stack[top]))
			{
				while(stack[top]!='('&&top!=-1)	
				{
					target[j]=pop();
					j++;
				}
				if(stack[top]='(')
				{temp=pop();}
				push(source[i]);
				i++;
				
				
				
			} else{
				
				push(source[i]);
				i++;
				
				
			}
			
		} else {
		
				printf("Invalid element in expression");
				exit(1);
			

			}
			
			

	}
	
	while(top!=-2)
	{
		target[j]=pop();
		j++;
	}	
		
	target[j]='\0';
		
		
}

int getpriority(char op){

	if(op=='/' || op == '*' || op=='%')
		return 1;
	
	else if(op=='+' || op=='–')
		
		return 0;

}



void push(char element)
{
 if(top==MAX-1)
 {
 	printf("Stack Overflow");
 } else {
 	
 	top++;
    stack[top]=element;
 
 }
 }
 
char pop(){

char val=' ';
	if(top==-2){
	printf("Stack underflow");
	} else {
	
	val= stack[top];
	top--;
	}
	return val;
}
	
/*

OUTPUT:

akshay@akshay-MacBookPro:~/Desktop$ gcc postfix.c -o p
akshay@akshay-MacBookPro:~/Desktop$ ./p
Enter infix expression: 
(A+B)*C
Postfix Expression is: 
AB+C*

*/

	
	







