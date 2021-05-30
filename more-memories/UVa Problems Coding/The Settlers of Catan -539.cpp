#include<stdio.h>
#define R 26
/*-------Global Variables---------*/
int graph[R][R],visit[R][R],shore[R], n,node,road,best;
/*------------Functions-----------*/
void Longest_path_of_Catan(int visited);
/*--------------Main--------------*/
void main()
{	
freopen("in06.txt","r",stdin);
int i=0,j;
scanf("%d%d",&n,&i);
while(n&&i)
{	
	for(node=0;node<n;node++)
		for(road=0;road<n;shore[node]=graph[node][road]=visit[node][road]=0,road++);
	
	for(best=0;best<i;best++)
	{	scanf("%d%d",&node,&road); shore[node]++; shore[road]++;
		graph[node][road]=1; graph[road][node]=1;
	}
	best=0;
	for(i=0;i<n;i++)
	{	if(shore[i]!=1) continue;
		road=0;
		Longest_path_of_Catan(i);
	}
	printf("%d\n",best);
	scanf("%d%d",&n,&i);
}}
void Longest_path_of_Catan(int node)
{	int i;
	for(i=0;i<n;i++)
	{	
		if(visit[i][node]==0&&graph[i][node])
		{	road++; visit[i][node]=1; visit[node][i]=1;
			Longest_path_of_Catan(i);
			road--; visit[i][node]=0; visit[node][i]=0;
		}
	}//for
	if(best<road) best=road;
}		