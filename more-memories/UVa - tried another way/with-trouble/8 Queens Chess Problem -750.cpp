#include<stdio.h>
#define R 9

/*-------------Functions-------------*/
void eight_queens_backtracking(char depth);
/*-------------Variables-------------*/
char rows[R],column[R],sorted[R], sn,k;  int r,c;
/*---------------Main----------------*/
void main()
{
freopen("in02.txt","r",stdin);
char i,j,q=0; int cs;
scanf("%d",&cs);
while(cs)
{	scanf("%d%d",&r,&c); cs--;
	sn=0; if(q) putchar(10); q=1;
	puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
	rows[1]=sorted[c]=r; column[1]=c;
	if(c==1) j=2; else j=1;
	for(i=1;i<9;i++)
	{	
		if( (r-c==i-j)||(r==i)||(i-r==c-j) ) continue;
		rows[2]=sorted[j]=i; column[2]=j;
		eight_queens_backtracking(2);
	}
}
}
/*------It tells done, by one and not done- by zero()-------*/
void eight_queens_backtracking(char depth)
{
	char row,col, hold=depth;
	if(r<=depth) col=depth+1;  else col=depth;
	for(row=1;row<9;row++)
	{	depth=hold;
		while(depth)
		{	if( (row-col==rows[depth]-column[depth])||(row==rows[depth])
					||(row-rows[depth]==column[depth]-col) )
				break;
			depth--;
		}
		if(!depth)
		{	rows[hold+1]=sorted[col]=row; column[hold+1]=col;
			if(col<8)
				eight_queens_backtracking(hold+1);
			else
			{	printf(" %-6d",++sn);
				for(k=1;k<9;printf(" %d",sorted[k]),k++);
				
				/*for(k=2;k<=c;printf(" %d",rows[k]),k++); printf(" %d",r);
				while(k<9) { printf(" %d",rows[k]); k++; }
				*/
				putchar(10);
		}	}
}	}