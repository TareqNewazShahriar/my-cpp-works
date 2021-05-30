#include<stdio.h>
#include<string.h>
#define R 2001
/*---------------------------Global Variables--------------------------*/
char s1[R],s2[R];
int len1,len2, memo[R][R];
/*--------------------------Function Prototypes------------------------*/
int dp_lcs(int i,int j);
/*----------------------------main Function----------------------------*/
void main()
{
//freopen("in.txt","r",stdin);
	int i,j;
	while(gets(s1))
	{
		gets(s2);
		
		len1=strlen(s1);
		len2=strlen(s2);
		for(i=0;i<len1;i++) for(j=0;j<len2;j++) memo[i][j]=-1;
		
		printf("%d\n",dp_lcs(0,0));
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