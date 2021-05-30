#include<stdio.h>
#include<string.h>
#define SIZE 100
typedef int Type;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*****************************main Function*****************************/
void main()
	{
	//freopen("inC.txt","r",stdin);
	Type i,j,len;
	char str[SIZE];

	scanf("%s",str);
	while(*str!='*')
		{
		len=strlen(str);
		
		for(i=0;i<len;i++)
			{
			bool mat[SIZE][SIZE]={0};
			for(j=i+1;j<len;j++)
				{
				if(mat[str[j]][str[j-i-1]])
					{ i=len; break; }
				else mat[str[j]][str[j-i-1]]=1;
				}
			}
		if(i==len+1) printf("%s is NOT surprising.\n",str);
		else printf("%s is surprising.\n",str);

		scanf("%s",str);
		}
	}