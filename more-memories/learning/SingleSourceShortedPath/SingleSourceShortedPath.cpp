// SingleSourceShortedPath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;

#define INF 30000
#define R 100

int n,v,cost[R][R],dist[R];
/*********************Data Input*********************/
void input()
{
	int x,y,length;

	cout<<"Enter number of Vertices :";
	cin>>n;

	for(x=0;x<=n;x++)		// elements of cost[][] is
	{
		for(y=1;y<=n;y++)	//  initializing by Infinite
			cost[x][y]=INF;
		cost[x][x]=0;
	}

	cout<<"Enter edge and length (enter -1, -1 to quit):-\n";
	do
	{	cout<<"Enter edge: ";
		cin>>x>>y;
		if(x==-1 || y==-1) break;
		cout<<"Enter length: ";
		cin>>length;
		cost[x][y]=length;
		cost[y][x]=length;
	}while(1);
	cout<<"Enter Source:";
	cin>>v;
}
/****************Single Source Shortest Path***************/
void ShortestPath()
{
	int i,j, temp,u;
	int isVisted[R];
	
	//initialization
	for(i=1;i<=n;i++)
	{
		isVisted[i]=0;
		dist[i]=cost[v][i]; // distance from 'source' to 'all other' nodes
	}
	isVisted[v]=1;		// source visited
	dist[v]=0;			// destination is source = 0
	
	//process
	for(i=2;i<n;i++)
	{
		temp=INF; u=1;
		//find out current nearest node from 'source'
		for(j=1;j<=n;j++)		
		{
			if(isVisted[j]==0 && dist[j]<temp)
			{	temp=dist[j]; u=j;	}
		}
		isVisted[u]=1;
		//find out any other shortest way from source to all other nodes
		for(j=1;j<=n;j++)
			if(isVisted[j]==0 && dist[j]>dist[u]+cost[u][j])
				dist[j]=dist[u]+cost[u][j];
	}
}

void show()
{
	int i;
	cout<<"\nShortest Paths from Source "<<v<<":-\n";
	
	for(i=1;i<=n;i++)
		cout<<setw(6)<<i;  // cout.width(), setw() can't do left indent
	cout<<"\n";
	
	for(i=1;i<=n;i++)
		cout<<setw(6)<<dist[i];
	cout<<"\n\n";
}

void main()
{
	freopen("Single Source.txt","r",stdin);
	int q;

	do
	{	cout<<"1. Input data\n";
		cout<<"2. Evaluate Single Source Shortest Path\n";
		cout<<"3. Quit\n";

		cin>>q;
		if(q==1) input();
		else if(q==2)
		{
			ShortestPath();
			show();
		}
	}while(q!=3);
}