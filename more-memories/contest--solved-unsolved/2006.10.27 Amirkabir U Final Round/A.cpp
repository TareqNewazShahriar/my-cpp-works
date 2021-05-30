#include<stdio.h>
#define SIZE 52
#define CON 100
typedef int Type;
/****************************Global Variables***************************/
Type t,N,M,s,n,m, row[SIZE],col[SIZE],k,x,y,lr,lrc,llc;
char board[SIZE][SIZE], piece[SIZE][SIZE];
/*************************User Defined Functions************************/
/*----manipulates the position of all other '*' w.r.t the first '*'(void)----*/
void star_position()
{
	int r,c;
	/* Global variables :
	n,m == pattern_str[n][m];
	k == total '*' in the pattern matrix,
	x,y == first '*' position
	row[] , col[] == all others '*' position w,r,t first '*'
	lr == last_row, that contains '*'
	llc == last_left_column that contains '*'
	lrc == last_right_column that contains '*'
	*/
	k=0;
	for(r=0;r<n;r++)
	{
		for(c=0;c<m;c++)
		{
			if(piece[r][c]=='*')
			{
				x=r; y=c;
				row[0]=r; col[0]=c; k++;
				lr=x; lrc=llc=y;
				r=n; break;
			}
		}
	}
	c++;
	for(r=x;r<n;r++,c=0)
	{
		for(;c<m;c++)
		{
			if(piece[r][c]=='*')
			{
				row[k]=r-x;
				col[k]=c-y;
				if(c<llc) llc=c;
				else if(c>lrc) lrc=c;
				lr=r;
				k++;
			}
		}
	}
	lr=lr-x; llc=y-llc; lrc=lrc-y;
}	
/*----------------Matching grid with the target-------------------*/
/*----(opaques,store_to,opaque_row,opaque_col,tot_opaque,
							first_opaque_row,first_opaque_col)----*/
bool matching(int i,int j)
{
	Type x;
	for(x=1;x<k;x++)
	{
		if(board[i+row[x]][j+col[x]]!='*')
			return 0;
	}
	
	return 1;
}
/*****************************main Function*****************************/
void main()
	{
	//freopen("a.txt","r",stdin);
	Type i,j, R,C;

	scanf("%d",&t);
	for(;t;t--)
		{
		scanf("%d%d%d",&N,&M,&s);
		for(i=0;i<N;i++) scanf("%s",board[i]);

		for(;s;s--)
			{			
			scanf("%d%d",&n,&m);
			for(i=0;i<n;i++) scanf("%s",piece[i]);

			star_position();
			//i=l
			R=N-lr;
			C=M-lrc;
			for(i=0;i<R;i++)
				{
				for(j=llc;j<C;j++)
					{
					if(board[i][j]=='*'&&matching(i,j))
						{ i=R+1; break; }
					}
				}
			if(i==R) puts("No");
			else puts("Yes");
			}
		putchar(10);
		}
	}