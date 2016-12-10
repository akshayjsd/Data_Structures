#include <stdio.h>

#define MAX 4

int vis[MAX];
int adj[MAX][MAX];


void dfs(int node)
{
	int i;
	vis[node]=1;
	printf("%c ",node+65);
	for(i=0;i<MAX;i++)
	{	
		if(adj[node][i]==1&&vis[i]==0)
		{
			dfs(i);
		}
	}
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

	dfs(0);
	printf("\n");

return 0;

}


/*
OUTPUT
student@student-HP-ProOne-400-G1-AiO
student:~/Desktop/Akshay$ ./d

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
A B D C 


*/

