#include<stdio.h>
#define R 9
/*---------------Functions---------------*/
void backtracking(int row,int col);
/*---------------Variables---------------*/
int gone[R][R]={{0},{0,1},{0,0,2},{0,0,0,3},{0,0,0,0,4},{0,0,0,0,0,5},
	{0,0,0,0,0,0,6},{0,0,0,0,0,0,0,7},{0,0,0,0,0,0,0,0,8}},
	
	path[6][6]={{0},{0,0,1,1,0,5},{0,1,0,1,0,5},{0,1,1,0,1,1},
	{0,0,0,1,0,1},{0,1,1,1,1,0}},
	
	ac[10],obv;
/*-----------------Main------------------*/
void main()
{	int i,j;
	for(i=1;i<6;i++)
	{
		for(j=1;j<6;j++)
		{	
			if(path[i][j]||i==j) continue;
			gone[i][j]=1; gone[j][i]=1;
			obv=2; ac[i]=i, ac[j]=j;
			backtracking(j,i);
		}
	}
}
void backtracking(int row,int col)
{	int j=1;
	while(j<6)
	{	
		if(path[row][j]&&!gone[row][j])
		{
			gone[row][j]=1; gone[j][row]=1; ac[obv++]=j;
			backtracking(j,row);
		}
		j++;
	}
	if(obv==9)
	{	for(j=1;j<10;printf("%d",ac[j]),j++); putchar(10); }
	gone[row][j]=0; gone[j][row]=0; obv--;
}		