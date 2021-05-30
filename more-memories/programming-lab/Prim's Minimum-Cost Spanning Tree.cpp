#include<stdio.h>
#include<iostream>

#define INF 25000
#define R 500

using namespace std;

int node;

/*******************Function Prototypes*******************/
int input(int cost[R][R]);
int Prim(int cost[R][R],int n,int t[R][3]);
void show(int mincost,int t[R][3],int cost[R][R]);
/**********************Main Function**********************/
void main()
{
	freopen("prim.txt","r",stdin);
	int q, n,cost[R][R],t[R][3],mincost;
	
	do
	{	cout<<"1. Input data\n";
		cout<<"2. Evaluate Minimum-Cost Spanning Tree\n";
		cout<<"3. Quit\n";
		
		cin>>q;
		if(q==1) n=input(cost);
		else if(q==2)
		{	mincost=Prim(cost,n,t);
			show(mincost,t,cost);
		}
	}while(q!=3);
}

/*********************Data Input*********************/
int input(int cost[R][R])
{
	int V, x,y,kost;

	cout<<"Enter number of Vertices :";
	cin>>V;

	for(x=0;x<=V;x++)		// elements of cost[][] is
		for(y=0;y<=V;y++)	//  initializing by Infinite
		{						// [ the loop must strat from zero.
			cost[x][y]=INF;		// [ because next process, in some
			cost[y][x]=INF;		// [ cases, will access this location.]
		}

	cout<<"Enter edges and costs (Enter -1, -1 to quit).\n";
	do
	{	cout<<"Enter edge: ";
		cin>>x>>y;
		if(x==-1 || y==-1) break;
		cout<<"Enter cost: ";
		cin>>kost;
		cost[x][y]=kost;
		cost[y][x]=kost;
	}while(1);

	return V;
}

/**********Prim's Minimum-cost Spanning Tree*********/
int Prim(int cost[R][R],int n,int t[R][3])
{
	int i,j, k,l, mincost, adjacent[R];
	
	node=0;
	k=l=1;
	for(i=1;i<=n;i++)	// finding the edge of minimum cost
	{	for(j=1;j<=n;j++)
			if(cost[i][j]<cost[k][l])
			{	k=i; l=j;	}
	}
	
	mincost=cost[k][l];
	t[1][1]=k; t[1][2]=l; node++;

	for(i=2;i<=n;i++)	// initializing adjacent[]
	{	if(cost[i][l]<cost[i][k]) adjacent[i]=l;
		else adjacent[i]=k;
	}
	adjacent[k]=adjacent[l]=0;
	
	for(i=2;i<n;i++)	// finding adjacent node so that ..
	{					//  cost[ j, adjacent[j] ] is minimum
		l=INF;
		for(k=1;k<=n;k++)
		{	if( cost[k][adjacent[k]] < l )
			{	l=cost[k][adjacent[k]];
				j=k;
			}
		}
		t[i][1]=adjacent[j]; t[i][2]=j;
		node++;
		mincost=mincost+cost[j][adjacent[j]];
		adjacent[j]=0;

		for(k=1;k<=n;k++)	// updating adjacent[].. 
			if(adjacent[k]!=0 && cost[k][adjacent[k]]>cost[k][j])
				adjacent[k]=j;
	} // for i
	return mincost;
}	

void show(int mincost,int t[R][3],int cost[R][R])
{
	int i;
	cout<<"\nPrim's Minimum Cost is "<<mincost<<"\n";
	cout<<"The Edges of the Spaninng Tree is:-\n";
	for(i=1;i<=node;i++)
		cout<<t[i][1]<<" -> "<<t[i][2]<<"\n";
	cout<<"\n\n";
}