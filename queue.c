#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* next;
};

struct node* front=NULL,*rear=NULL;


struct node *insert(struct node* rear,int val);
struct node *delete(struct node* front);
struct node *display(struct node* front);
void peek(struct node* front);

int main(){
	
	int val,option,n;
		
	printf("Enter your choice: ");
    	printf("\n1.Create queue\n");
   	 scanf("%d",&n);
    	while(n!=5)
    	{
        
        
       	    switch(n){
       	    
            case 1: printf("\nEnter element to insert: ");
            		scanf("%d",&val);
            		rear=insert(rear,val);
                	break;
            case 2: front=delete(front);
                	break;
            case 3: peek(front);           		
                	break;
            case 4: front= display(front);
               		break;
                
            default:printf("Invalid choice\n");
        }
        
        
        printf("\nEnter your choice:");
        printf("\n1. Insert\t2. Delete\t3. Peek\t4. Display\t5. Exit\nCHOICE : ");
        scanf("%d",&n);
        
    }
 return 0;   
}    
    
struct node *insert(struct node* rear,int val)
{    
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
   	nn->data=val;
    	if(rear==NULL)
    	{
    		rear=nn;
    		front=nn;
    		front->next=rear->next=NULL;
    	} else 
    	{
    		rear->next=nn;
    		rear=rear->next;
        }
    return rear;
}

struct node* delete(struct node* front)
{
	struct node* temp;
	temp=front;
	if(front==NULL)
	{	
		printf("\nUnderflow!");
	} else {
		front=front->next;
		printf("The value being deleted is %d",temp->data);
		free(temp);
    }
return front;
}

struct node* display(struct node* front)
{
	struct node* temp;
	temp=front;
	printf("Display\n");
	while(temp!=NULL)
	{
		
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	
	return front;
}

void peek(struct node *front)
{	
	printf("\nPeeking...");
	printf("\n%d",front->data);
}


/*
OUTPUT:

akshay@akshay-MacBookPro:~/Desktop$ gcc queue.c -o q
akshay@akshay-MacBookPro:~/Desktop$ ./q
Enter your choice: 
1.Create queue
1

Enter element to insert: 3

Enter your choice:
1. Insert	2. Delete	3. Peek	4. Display	5. Exit
CHOICE : 1

Enter element to insert: 4

Enter your choice:
1. Insert	2. Delete	3. Peek	4. Display	5. Exit
CHOICE : 1

Enter element to insert: 5

Enter your choice:
1. Insert	2. Delete	3. Peek	4. Display	5. Exit
CHOICE : 3

Peeking...
3
Enter your choice:
1. Insert	2. Delete	3. Peek	4. Display	5. Exit
CHOICE : 2
The value being deleted is 3
Enter your choice:
1. Insert	2. Delete	3. Peek	4. Display	5. Exit
CHOICE : 4
Display
4	5	
Enter your choice:
1. Insert	2. Delete	3. Peek	4. Display	5. Exit
CHOICE : 5

*/






	
    	
    	
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
