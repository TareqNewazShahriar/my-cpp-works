#include<stdio.h>
#define R 102
/*-----Global Variables----*/
short best,var, board[R][R],visit[R][R],dr[4]={ 0,0,-1,1},
										dc[4]={-1,1, 0,0};
/*----------Functions------*/
short BFS_longest_run(char r,char c,short val);
/*------------Main---------*/
void main()
{
//freopen("F:\\progra~3\\proble~1\\pacmpr~1\\in09.txt","r",stdin);
int cs,r,c,row,col; char Location[R];
scanf("%d",&cs);
while(cs)
{	cs--;
	scanf("%s %d %d",Location,&row,&col);
	row++; col++;
	for(r=1;r<row;r++) for(c=1;c<col;c++)  scanf("%d",&board[r][c]), visit[r][c]=0;
	if(row>col) c=row;
	while(c>-1)	{ board[c][0]=board[0][c]=board[row][c]=board[c][col]=110; c--; }
	best=0;
	for(r=1;r<row;r++)
		for(c=1;c<col;c++)
		{	if(visit[r][c]==0)
			{	if( (visit[r][c]=BFS_longest_run(r,c,board[r][c]))>best)
					best=visit[r][c];
		}	}
	printf("%s: %d\n",Location,best);
}}
/*----------------------------------------------------*/
short BFS_longest_run(char r,char c,short val)
{	char i=0,nr,nc; short var=0;
	while(i<4)
	{	nr=r+dr[i]; nc=c+dc[i];
		if(board[nr][nc]<val)
		{	
			if(!visit[nr][nc])
			{	
				if( (visit[nr][nc]=BFS_longest_run(nr,nc,board[nr][nc]))>var)
					var=visit[nr][nc];
			}
			else if(visit[nr][nc]>var) var=visit[nr][nc];
		}
		i++;
	}
	return var+1;
}		