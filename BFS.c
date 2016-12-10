#include <stdio.h>

#define MAX 4

int vis[MAX];
int adj[MAX][MAX];
int queue[MAX];


void bfs(int node)
{
	int i;
	int front=0,rear=-1;
	vis[node]=1;
	
	for(i=0;i<MAX;i++)
	{	
		if(adj[node][i]==1&&vis[i]==0)
		{
			printf("%c ",i+65);
			vis[i]=1;
			queue[++rear]=i;
		}
	}
	if(front<=rear)
	bfs(queue[front++]);
}

int main()
{
	int i,j;
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	
	for(i=0;i<MAX;i++)
	{
		vis[i]=0;
	}
	printf("%c ",65);
	bfs(0);
	printf("\n");

return 0;

}


/*
OUTPUT
student@student-HP-ProOne-400-G1-AiO
student:~/Desktop/Akshay$ ./b

Enter the adjacency matrix:
0
1
1
0
1
0
0
1
1
0
0
0
0
1
0
0
A B C D 



*/

