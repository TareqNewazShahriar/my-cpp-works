#include<stdio.h>
#include<string>
#define R 101
#define T 35

using namespace std;
/*---------------------------Global Variables--------------------------*/
int len1,len2;
char word1[T],word2[T], (*disp)[R];
short memo[R][R];
string w1[R],w2[R];
/*+++++++++++++++++++++++++Function Prototypes+++++++++++++++++++++++++*/
/*--------------------------Input Function----------------------------*/
bool input()
	{
	len1=len2=0;
	
	if(scanf("%s",word1)==EOF) return 0;
	w1[len1]=word1;
	while(word1[0]!='#')
		{
		len1++;
		scanf("%s",word1);
		w1[len1]=word1;
		}
	
	scanf("%s",word2);
	w2[len2]=word2;
	while(word2[0]!='#')
		{
		len2++;
		scanf("%s",word2);
		w2[len2]=word2;
		}
	
	return 1;
	}
/*---------------------------------------------------------*/
void show_lcs()
	{
	int i=0,j=0;
	//for(i=0;i<len1;i++) for(j=0;j<len2&&disp[i][j]==0;j++);
	while(disp[i][j]!=1)
		{
		if(disp[i][j]==2)
			j++;
		else
			i++;
		}
	if(len1) 
		{
		printf("%s",w1[i].c_str());
		i++; j++; len1--;
		}
	while(len1)
		{
		if(disp[i][j]==1) 
			{
			printf(" %s",w1[i].c_str()); /*
			cout<<w1[i]<<" "; //*/
			i++, j++; len1--;
			}
		else if(disp[i][j]==2)
			j++;
		else
			i++;
		}
	printf("\n");
	}
/*------------------------DP LIS---------------------------*/
int dp_lcs(int i,int j)
	{
	int u,v;
	if(i==len1||j==len2) return 0;
	if(memo[i][j]!=-1) return memo[i][j];
	if(w1[i]==w2[j])
		{
		disp[i][j]=1;
		return memo[i][j]=dp_lcs(i+1,j+1)+1;
		}
	u=dp_lcs(i,j+1);
	v=dp_lcs(i+1,j);
	if(u>v)
		{
		disp[i][j]=2; return memo[i][j]=u;
		}
	disp[i][j]=3;
	return memo[i][j]=v;
	}
/*----------------------------main Function----------------------------*/
void main()
	{
	int i,j;
	//freopen("in.txt","r",stdin);
	
	while(input())
		{
		char d[R][R]={0}; disp=d;
		for(i=0;i<len1;i++) for(j=0;j<len2;j++) memo[i][j]=-1;
		len1=dp_lcs(0,0);
		show_result();
		}
	}