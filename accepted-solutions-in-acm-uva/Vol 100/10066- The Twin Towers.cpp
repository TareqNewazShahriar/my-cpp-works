#include<stdio.h>
#include<string.h>
#define R 101
/*---------------------------Global Variables--------------------------*/
int s1[R],s2[R], len1,len2, memo[R][R];
/*--------------------------Function Prototypes------------------------*/
int dp_lcs(int i,int j);
/*----------------------------main Function----------------------------*/
void main()
{
//freopen("in.txt","r",stdin);
	int i,j,cs=0, x,y, q=0;
	scanf("%d%d",&x,&y);
	while(x!=0&&y!=0)
	{
		//if(q) putchar(10);  q=1;
		for(i=0;i<x;i++) scanf("%d",s1+i);
		for(i=0;i<y;i++) scanf("%d",s2+i);
		len1=x, len2=y;
		for(i=0;i<len1;i++) for(j=0;j<len2;j++) memo[i][j]=-1;
		
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++cs,dp_lcs(0,0));

		scanf("%d%d",&x,&y);
	}
}
/*--DP Longest Common Subsequence(sequence1_index, sequence2_index)--*/
int dp_lcs(int i,int j)
{
	int u,v;
	
	if(i==len1||j==len2) return 0;
	if(memo[i][j] != -1) return memo[i][j];
	if(s1[i]==s2[j])
	{
		memo[i][j]=dp_lcs(i+1,j+1)+1;
		return memo[i][j];
	}
	
	u=dp_lcs(i,j+1);
	v=dp_lcs(i+1,j);

	if(u>v)
	{	
		memo[i][j]=u;
		return u;
	}

	memo[i][j]=v;
	return v;
}	