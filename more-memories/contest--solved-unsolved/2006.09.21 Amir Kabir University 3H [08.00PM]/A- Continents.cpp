#include<stdio.h>
#define R 102
#define CON 100000
/*-----Global Variables------*/
int pocket,big, m,n, u,v; char field[R][R]={0},
		dr[8]={0,0,-1,1,-1,-1,1,1},
		dc[8]={-1,1,0,0,-1,1,-1,1};
/*---------Functions---------*/
void breadth_of_pocket(char i,char j);
void readth_of_pocket(char i,char j);
void BFS(char i,char j)
{
	char nr,nc,k,z;
	for(k=0;k<8;k++)
	{
		nr=i+dr[k]; nc=j+dc[k];
		if(field[nr][nc]=='l') 
		{
			if(nr==u&&nc==v) pocket=-CON;
			field[nr][nc]=0;
			pocket++;
			BFS(nr,nc);
			if(nr==1) //opposite of first row
				{
				if(field[m][nc]=='l')
					{
					if(m==u&&nc==v) pocket=-CON;
					field[m][nc]=0;
					pocket++;
					BFS(m,nc);
					}
				if(field[m][nc+1]=='l')
					{
					if(m==u&&nc+1==v) pocket=-CON;
					field[m][nc+1]=0;
					pocket++;
					BFS(m,nc+1);
					}
				if(field[m][nc-1]=='l')
					{
					if(m==u&&nc-1==v) pocket=-CON;
					field[m][nc-1]=0;
					pocket++;
					BFS(m,nc-1);
					}
				}
			if(nr==m) //opposite of last row
				{
				if(field[1][nc]=='l')
					{
					if(1==u&&nc==v) pocket=-CON;
					field[1][nc]=0;
					pocket++;
					BFS(1,nc);
					}
				if(field[1][nc+1]=='l')
					{
					if(1==u&&nc+1==v) pocket=-CON;
					field[1][nc+1]=0;
					pocket++;
					BFS(1,nc+1);
					}
				if(field[1][nc-1]=='l')
					{
					if(1==u&&nc-1==v) pocket=-CON;
					field[1][nc-1]=0;
					pocket++;
					BFS(1,nc-1);
					}
				}
			if(nc==1) //opposite of first column
				{
				if(field[nr][n]=='l')
					{
					if(nr==u&&n==v) pocket=-CON;
					field[nr][n]=0;
					pocket++;
					BFS(nr,n);
					}
				if(field[nr+1][n]=='l')
					{
					if(nr+1==u&&n==v) pocket=-CON;
					field[nr+1][n]=0;
					pocket++;
					BFS(nr+1,n);
					}
				if(field[nr-1][n]=='l')
					{
					if(nr-1==u&&n==v) pocket=-CON;
					field[nr-1][n]=0;
					pocket++;
					BFS(nr-1,n);
					}
				}
			if(nc==n) //opposite of last column
				{
				if(field[nr][1]=='l')
					{
					if(nr==u&&1==v) pocket=-CON;
					field[nr][1]=0;
					pocket++;
					BFS(nr,1);
					}
				if(field[nr+1][1]=='l')
					{
					if(nr+1==u&&1==v) pocket=-CON;
					field[nr+1][1]=0;
					pocket++;
					BFS(nr+1,1);
					}
				if(field[nr-1][1]=='l')
					{
					if(nr-1==u&&1==v) pocket=-CON;
					field[nr-1][1]=0;
					pocket++;
					BFS(nr-1,1);
					}
				}
			//opposite part
		}// land check
	}//for loop
}// function end
/*------------Main-----------*/
void main()
{
//freopen("A.txt","r",stdin);
char i,j;
while(scanf("%d%d",&m,&n)==2&&m!=0)
{	
	for(i=1;i<=m;scanf("%s",&field[i][1]),i++);
	scanf("%d%d",&u,&v);
	u++; v++;
	big=0;
	for(i=1;i<=m;i++)
	{	
		for(j=1;j<=n;j++)
		{
			if(field[i][j]=='l')
			{
				pocket=1;
				if(i==u&&j==v) pocket=-CON;
				field[i][j]=0;
				BFS(i,j);
				if(pocket>big) big=pocket;
	}	}	}
	printf("%d\n",big);	
}}		