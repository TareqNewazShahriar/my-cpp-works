#include<stdio.h>
#include<string.h>
#define N 505
#define ZZ 10
/*---------------------------Global Variables--------------------------*/
int n,k,cube[N][ZZ], d[N][2];
char dir[N][ZZ], color[][]={"","front", "back", "left", "right", "top", "bottom"};
/*---------------------------------------------*/
void take_input()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d%d%d%d%d%d",cube[i][1],cube[i][2],
					cube[i][3],cube[i][4],cube[i][5],cube[i][6],cube[i][7],cube[i][8]);
	
}
/*---------------------------------------------*/
int DP_LIS()
{
	int i,j,v; f[N]={0};
	f[n]=0;
	//strcpy(dir[n],color[]);
	for(i=n-1;i;i--)
	{
		for(j=i+1;j<=n;j++)
		{
			for(v=1;v<=8;v++)
			{
				if(cube[][])
			}
		}
	}
}
/*----------------------------main Function----------------------------*/
void main() // 11:48 AM 9/10/2006
{
	int i,j;
	
	take_input();
	
	process();
}
