#include<stdio.h>
#define R 9

/*-------------Functions-------------*/
void eight_queen_backtracking(char depth);
/*-------------Variables-------------*/
char rows[R],column[R],sorted[R], sn,k;  int r,c;
/*---------------Main----------------*/
void main()
{
freopen("in02.txt","r",stdin);
char i,j,q=0; int cs;
scanf("%d",&cs);
while(cs)
{
	scanf("%d%d",&r,&c); cs--;
	sn=0;	if(q) putchar(10); q=1;
	puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
	rows[1]=r; column[1]=sorted[r]=c;
	if(r==1) i=2; else i=1;
	for(j=1;j<9;j++)
	{	
		if( (r-c==i-j)||(c==j)||(i-r==c-j) ) continue;
		rows[2]=i; column[2]=sorted[i]=j;
		eight_queen_backtracking(2);
	}
}
}
/*------It tells done, by one and not done- by zero()-------*/
void eight_queen_backtracking(char depth)
{
	char row,col, hold=depth;
	if(r<=depth) row=depth+1;  else row=depth;
	for(col=1;col<9;col++)
	{	depth=hold;
		while(depth)
		{	if( (row-col==rows[depth]-column[depth])||(col==column[depth])
					||(row-rows[depth]==column[depth]-col) )
				break;
			depth--;
		}
		if(!depth)
		{	rows[hold+1]=row; column[hold+1]=sorted[row]=col;
			if(row<8)
				eight_queen_backtracking(hold+1);
			else
			{	printf(" %-6d",++sn);
				for(k=1;k<9;printf(" %d",sorted[k]),k++);
				putchar(10);
		}	}
}	}