// TLE
// Actually Problem F 11134
#include<stdio.h>
#define SIZE 5001
typedef int Type;
/****************************Global Variables***************************/
Type n, chess[SIZE][2], area[SIZE][4];
/*************************User Defined Functions************************/
bool backtrack(int k)
	{
	if(k==n) return 1;
	
	int i=area[k][0],j,v;
	for(;i<=area[k][2];i++)
		{
		for(j=area[k][1];j<=area[k][3];j++)
			{
			for(v=0;v<k;v++)
				if(i==chess[v][0]||j==chess[v][1]) break;
			if(v==k)
				{
				chess[k][0]=i,chess[k][1]=j;
				if(backtrack(k+1)) return 1;
				}
			}
		}
	return 0;
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("K.txt","r",stdin);
	Type i;
	while(scanf("%d",&n)!=EOF)
		{
		for(i=0;i<n;i++) scanf("%d%d%d%d",&area[i][0],&area[i][1],&area[i][2],&area[i][3]);
		if(backtrack(0))
			for(i=0;i<n;i++) printf("%d %d\n",chess[i][0],chess[i][1]);
		else puts("IMPOSSIBLE");
		}
	}
