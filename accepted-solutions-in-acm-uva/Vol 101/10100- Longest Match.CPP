#include<stdio.h>
#include<string>
#define R 1001
#define T 21

using namespace std;
/*---------------------------Global Variables--------------------------*/
int len1,len2;
short memo[R][R];
string w1[R],w2[R];
/*+++++++++++++++++++++++++Function Prototypes+++++++++++++++++++++++++*/
/*---Find out the number of word in a line(STL_string_array, source_str)---*/
int string_evaluation(string dest[],char *src)
{
	int count=0;
	char *s;

	while(*src)
		{
		if((*src>64&&*src<91)||(*src>96&&*src<123)||(*src>47&&*src<58))
			{
			s=src;
			for(src++;(*src>64&&*src<91)||(*src>96&&*src<123)||(*src>47&&*src<58);src++)
				{
				if(*src>64&&*src<91) (*src)+=32;
				}
			dest[count].assign(s,src);
			count++;
			}
		else src++;
		}
	return count;
}
/*--------------------------Input Function----------------------------*/
int input()
	{
	char str1[R],str2[R];
	if(gets(str1)==0) return 0;
	gets(str2);
	if(*str1==0 || *str2==0) return 2;
	len1=string_evaluation(w1,str1);
	len2=string_evaluation(w2,str2);
	return 1;
	}
/*------------------------DP LIS---------------------------*/
int dp_lcs(int i,int j)
	{
	int u,v;
	if(i==len1||j==len2) return 0;
	if(memo[i][j]!=-1) return memo[i][j];
	if(w1[i]==w2[j])
		return memo[i][j]=dp_lcs(i+1,j+1)+1;
	u=dp_lcs(i,j+1);
	v=dp_lcs(i+1,j);
	if(u>v)
		return memo[i][j]=u;
	return memo[i][j]=v;
	}
/*----------------------------main Function----------------------------*/
void main()
	{
	int cs=0,i,j;
	//freopen("in.txt","r",stdin);
	i=input();
	while(i)
		{
		if(i==2) printf("%2d. Blank!\n",++cs);
		else
			{
			for(i=0;i<len1;i++) for(j=0;j<len2;j++) memo[i][j]=-1;
			printf("%2d. Length of longest match: %d\n",++cs,dp_lcs(0,0));
			//show_result();
			}
		i=input();
		}
	}