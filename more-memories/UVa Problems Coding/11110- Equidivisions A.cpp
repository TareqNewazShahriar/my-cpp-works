// TLE
#include<stdio.h>
#define SIZE 101
typedef int Type;

/****************************Global Variables***************************/
char (*mat)[SIZE];
Type i,n, x[SIZE],y[SIZE];
/*************************User Defined Functions************************/
/*------------------------------------------------------------*/
bool valid()
	{
	Type j,u,v;
	for(j=1;j<=n;j++)
		{
		if(mat[u=x[j]][v=y[j]]==0) mat[u][v]=i;
		else return 0;
		}

	for(j=1;j<=n;j++)
		{
		u=x[j];
		v=y[j];
		if(mat[u][v+1]==i) continue;
		if(mat[u][v-1]==i) continue;
		if(mat[u+1][v]==i) continue;
		if(mat[u-1][v]==i) continue;
		return 0;
		}
	return 1;
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("a.txt","r",stdin);
	Type j,u,v;
	bool q;
	
	scanf("%d",&n);
	while(n)
		{
		q=1;
		char mat[SIZE][SIZE]={0}; // mat=m;
		for(i=1;i<n;i++)
			{
			for(j=1;j<=n;j++) 
				{
				scanf("%d%d",&x[j],&y[j]);
				if(q)
					{
					if(mat[u=x[j]][v=y[j]]==0) mat[u][v]=i;
					else q=0;
					}
				}
			if(q)
				{
				/*
				for(j=1;j<=n;j++)
					{
					if(mat[u=x[j]][v=y[j]]==0) mat[u][v]=i;
					else q=0;
					}
				*/

				for(j=1;j<=n;j++)
					{
					u=x[j];
					v=y[j];
					if(mat[u][v+1]==i) continue;
					if(mat[u][v-1]==i) continue;
					if(mat[u+1][v]==i) continue;
					if(mat[u-1][v]==i) continue;
					q=0; break;
					}
				}
			}
		if(q) puts("good");
		else puts("wrong");

		scanf("%d",&n);
		}
	}