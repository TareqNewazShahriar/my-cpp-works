#include<stdio.h>
#define R 101
void main()
{	int r,c, i,j, mine,cs=0;
	char mat[R][R];
//freopen("input.txt","r",stdin);
//freopen("out.doc","w",stdout);
	while(scanf("%d%d",&r,&c)!=EOF)
	{	if(r==0&&c==0) break;
		printf("Field #%d:\n",++cs);
		if(cs!=1) printf("\n");
		for(i=0;i<r;i++) scanf("%s",&mat[i]);
		for(i=0;i<r;i++)
		{	for(j=0,mine=0;j<c;j++,mine=0)
			{   if(mat[i][j]!=42)
				{	if(i-1>-1&&j-1>-1 &&mat[i-1][j-1]==42) mine++;
					if(i-1>-1&&mat[i-1][j]==42) mine++;
					if(i-1>-1&&j+1<c &&mat[i-1][j+1]==42) mine++;
					if(j+1<c &&mat[i][j+1]==42) mine++;
					if(i+1<r&&j+1<c &&mat[i+1][j+1]==42) mine++;
					if(i+1<r &&mat[i+1][j]==42) mine++;
					if(i+1<r&&j-1>-1&&mat[i+1][j-1]==42) mine++;
					if(j-1>-1&&mat[i][j-1]==42) mine++;
					printf("%d",mine);
				}
				else printf("*");
			}
			printf("\n");
		}//printf("\n");
}	}//m