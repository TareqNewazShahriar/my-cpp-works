#include<stdio.h>
#define R 26
/*-------Global Variables---------*/
int graph[R][R],visit[R][R],freq[R], n,node,road,best;
/*------------Functions-----------*/
void Longest_path_of_Catan(int visited);
/*--------------Main--------------*/
void main()
{	
freopen("in06.txt","r",stdin);
int i=0;
scanf("%d%d",&n,&i);
while(n&&i)
{	
	for(node=0;node<n;node++)
		for(road=0;road<n;freq[node]=graph[node][road]=visit[node][road]=0,road++);
	
	for(best=0;best<i;best++)
	{	scanf("%d%d",&node,&road);
		graph[node][freq[node]++]=road;
		graph[road][freq[road]++]=node;
		//graph[node][road]=1; graph[road][node]=1;
	}
	best=0;
	for(i=0;i<n;i++)
	{	if(freq[i]!=1) continue;
		road=0;
		Longest_path_of_Catan(i);
	}
	printf("%d\n",best);
	scanf("%d%d",&n,&i);
}}
void Longest_path_of_Catan(int node)
{	int i,v;
	for(i=0;i<freq[node];i++)
	{	v=graph[node][i];
		if(visit[node][v]==0)
		{	road++; visit[v][node]=1; visit[node][v]=1;
			Longest_path_of_Catan(v);
			road--; visit[v][node]=0; visit[node][v]=0;
		}
	}//for
	if(best<road) best=road;
}		
