#include<stdio.h>
#define R 52
#define T 200
/*---------------------------Global Variables--------------------------*/
char grid[R][R][R], (*tar)[T], alp[R][R], sto[R][R];
int gd,r,c,a, ele[T],row[T][T],col[T][T], bc[R],bcc[R],bg[R];
/*--------------------------Function Prototypes------------------------*/
/*---Finding a valid target(grid, position)---*/
char is_valid_target(int pos)
{
	int i,j, u=r,v=c;
	char ch=alp[pos][0];

	u=u-bg[pos];
	v=v-bcc[pos];
	for(i=0;i<u;i++)
	{
		for(j=bc[pos];j<v;j++)
		{
			if(tar[i][j]==ch)
			{
				if( matching(alp[pos],sto[pos],row[pos],col[pos],ele[pos], i,j) )
				{
					if(gd==pos) return 1;
					else if(  is_valid_target(pos+1) ) return 1;
					else return_alpha(sto[pos],row[pos],col[pos],ele[pos],i,j);
				}
			}
		}
	}
	return 0;
}
/*----------------Matching grid with the target-------------------*/
/*----(opaques,store_to,opaque_row,opaque_col,tot_opaque,
							first_opaque_row,first_opaque_col)----*/
char matching(char alp[],char sto[],int row[],int col[],int ele, int x,int y)
{
	int i,u,v;
	for(i=1;i<ele;i++)
	{
		if(tar[x+row[i]][y+col[i]]!=alp[i])
			return 0;
	}
	sto[0]=tar[x][y];
	tar[x][y]=0;
	for(i=1;i<ele;i++)
	{
		u=x+row[i];
		v=y+col[i];
		sto[i]=tar[u][v];
		tar[u][v]=0;
	}
	return 1;
}
/*---Restore the alphabets to "target string()---*/
void return_alpha(char sto[],int row[],int col[],int ele, int x,int y)
{
	int i,u,v;

	for(i=0;i<ele;i++)
	{
		u=x+row[i];
		v=y+col[i];
		tar[u][v]=sto[i];
		//tar[u][v]=0;
	}
}
/*----To collect the grid and save it's alpha position( grid[][] )----*/
void alpha_position(char grid[R][R],int &bc,int &bcc,int &bg)
{
	int r,c, x,y, b=0, k;
	a++;
	for(r=0;r<5;r++)
	{
		for(c=0;c<5;c++)
		{
			if(grid[r][c]!='.')
			{
				alp[a][b]=grid[r][c];
				x=r; y=c;
				row[a][b]=r;
				col[a][b]=c;
				b++;
				r=c=5;
			}
		}
	}
	c=y+1;
	for(r=x;r<5;r++,c=0)
	{
		for(;c<5;c++)
		{
			if(grid[r][c]!='.')
			{
				alp[a][b]=grid[r][c];
				row[a][b]=r-x;
				col[a][b]=k=c-y;
				b++;
				if(k<bc) bc=k;
				if(c>bcc) bcc=c;
				bg=r;
			}
		}
	}
	bc = -bc;
	bcc=bcc-y;
	bg-=x;
	ele[a]=b;
}	
/*------Fill every side of an array with zero(border_length)----*/
void fill_array_border(int border)
{
	int j,k=r;

	for(j=0;j<c;j++)
	{
		tar[0][j]=0;
		tar[j][0]=0; 
		/*
		tar[3][j]=0; tar[1][j]=0;
		tar[4][j]=0; tar[2][j]=0;		

		tar[j][3]=0; tar[j][1]=0;
		tar[j][4]=0; tar[j][2]=0;
		*/
	}
	for(j=c;j>=0;j--)
	{
		tar[k][j]=0;
		tar[j][k]=0;
		/*
		tar[k+3][j]=0; tar[k+1][j]=0;
		tar[k+4][j]=0; tar[k+2][j]=0;

		tar[j][k+3]=0; tar[j][k+1]=0;
		tar[j][k+4]=0; tar[j][k+2]=0;
		*/
	}
}
/*----------------------------main Function----------------------------*/
void main()
{
freopen("a.txt","r",stdin);
	int i,test, cs=0;

	scanf("%d",&test);
	for(;test;test--)
	{   
		a=-1;
		char t[T][T]={0};  tar=t;

		scanf("%d",&gd);
		for(i=0;i<gd;i++)
		{
			scanf("%s%s%s%s%s",grid[i][0],grid[i][1],grid[i][2],grid[i][3],grid[i][4]);
			alpha_position(grid[i],bc[i],bcc[i],bg[i]);
		}

		scanf("%d%d",&r,&c);
		for(i=0;i<r;i++) scanf("%s",tar[i]);
		gd--;
		if( is_valid_target(0) ) printf("Case %d: Yes\n",++cs);
		else    printf("Case %d: No\n",++cs);
	}
}
