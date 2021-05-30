// AC
#include<stdio.h>
#define R 30
/*-----Global Variables------*/
int wars, m;
char field[R][R]={0},dr[8]={0,0,-1,1,-1,-1,1,1},
dc[8]={-1,1,0,0,-1,1,-1,1};
/*---------Functions---------*/
void BFS(char i,char j)
{
	char nr,nc,k;
	for(k=0;k<8;k++)
	{
		nr=i+dr[k]; 
		nc=j+dc[k];
		if(field[nr][nc]==49)	//49 = '1'
		{
			field[nr][nc]=0; 
			BFS(nr,nc);
		}
	}
}
/*------------Main-----------*/
void main()
{
	//freopen("in07.txt","r",stdin);
	char i,j,*c;
	int cs=0;

	while(scanf("%d",&m)==1)
	{
		for(i=1; i<=m; scanf("%s",field[i]+1),i++);
		wars=0;
		for(i=1;i<=m;i++)
		{
			for(j=1,c=&field[i][1]; j<=m; c++,j++)
			{
				if(*c==49)	// 49 = '1'
				{
					*c=0;
					BFS(i,j);
					wars++;
				}
			}	
		}
		printf("Image number %d contains %d war eagles.\n", ++cs, wars);
	}
}