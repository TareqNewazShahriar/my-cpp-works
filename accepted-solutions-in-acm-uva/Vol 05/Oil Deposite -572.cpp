#include<stdio.h>
#define R 102
/*-----Global Variables------*/
int pocket, m,n; char field[R][R]={0},dr[8]={0,0,-1,1,-1,-1,1,1},
									  dc[8]={-1,1,0,0,-1,1,-1,1};
/*---------Functions---------*/
void breadth_of_pocket(char i,char j);
void readth_of_pocket(char i,char j);
void BFS(char i,char j);
/*------------Main-----------*/
void main()
{
//freopen("in07.txt","r",stdin);
char i,j;
//scanf("%d",&m)
while(scanf("%d%d",&m,&n)==2&&m!=0)
{	
	for(i=1;i<=m;scanf("%s",&field[i][1]),i++);
	pocket=0;
	for(i=1;i<=m;i++)
	{	for(j=1;j<=n;j++)
		{
			if(field[i][j]==64) 
			{
				//breadth_of_pocket(i,j); 
				//readth_of_pocket(i,j);  
				BFS(i,j);
				pocket++;
	}	}	}
	printf("%d\n",pocket);	
}}		
/*	if(i-1>-1&&j-1>-1 &&field[i-1][j-1]==64) field[i-1][j-1]=42;
	if(i-1>-1&&field[i-1][j]==64) field[i-1][j]=42;
	if(i-1>-1&&j+1<n &&field[i-1][j+1]==64) field[i-1][j+1]=42;
	if(j+1<n &&field[i][j+1]==64) field[i][j+1]=42;
	if(i+1<m&&j+1<n &&field[i+1][j+1]==64) field[i+1][j+1]=42;
	if(i+1<m &&field[i+1][j]==64) field[i+1][j]=42;
	if(i+1<m&&j-1>-1&&field[i+1][j-1]==64) field[i+1][j-1]=42;
	if(j-1>-1&&field[i][j-1]==64) field[i][j-1]=42;
*/
void breadth_of_pocket(char i,char j)
{	char mi=i-1,mj=j-1,pi=i+1, pj=j+1;

	if(field[mi][mj]==64)	{ field[mi][mj]=0;	breadth_of_pocket(mi,mj); }
	if(field[mi][j]==64)	{ field[mi][j]=0;	breadth_of_pocket(mi,j); }
	if(field[mi][pj]==64)	{ field[mi][pj]=0;	breadth_of_pocket(mi,pj); }
	if(field[i][pj]==64)	{ field[i][pj]=0;	breadth_of_pocket(i,pj); }
	if(field[pi][pj]==64)	{ field[pi][pj]=0;	breadth_of_pocket(pi,pj); }
	if(field[pi][j]==64)	{ field[pi][j]=0;	breadth_of_pocket(pi,j); }
	if(field[pi][mj]==64)	{ field[pi][mj]=0;	breadth_of_pocket(pi,mj); }
	if(field[i][mj]==64)	{ field[i][mj]=0;	breadth_of_pocket(i,mj); }
}		
void readth_of_pocket(char i,char j)
{
	if(field[i-1][j-1]==64)	{ field[i-1][j-1]=0;	readth_of_pocket(i-1,j-1); }
	if(field[i-1][j]==64)	{ field[i-1][j]=0;		readth_of_pocket(i-1,j); }
	if(field[i-1][j+1]==64)	{ field[i-1][j+1]=0;	readth_of_pocket(i-1,j+1); }
	if(field[i][j+1]==64)	{ field[i][j+1]=0;		readth_of_pocket(i,j+1); }
	if(field[i+1][j+1]==64)	{ field[i+1][j+1]=0;	readth_of_pocket(i+1,j+1); }
	if(field[i+1][j]==64)	{ field[i+1][j]=0;		readth_of_pocket(i+1,j); }
	if(field[i+1][j-1]==64)	{ field[i+1][j-1]=0;	readth_of_pocket(i+1,j-1); }
	if(field[i][j-1]==64)	{ field[i][j-1]=0;		readth_of_pocket(i,j-1); }
}		
void BFS(char i,char j)
{
	char nr,nc,k;
	for(k=0;k<8;k++)
	{
		nr=i+dr[k]; nc=j+dc[k];
		if(field[nr][nc]==64) { field[nr][nc]=0;	BFS(nr,nc); }
	}

}