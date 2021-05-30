#include<stdio.h>
#define SIZE 260
typedef int Type;
/****************************Global Variables***************************/
Type sum, alpha[SIZE];
char str[SIZE];
/*************************User Defined Functions************************/
void set_value()
	{
	Type i,j;
	for(i=65,j=1;i<=90;i++,j++)
		{
		alpha[i]=j;
		}
	alpha[32]=0;
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("inA.txt","r",stdin);
	Type i;
	char *t;

	set_value();

	gets(str);
	while(str[0]!='#')
		{
		sum=0;
		for(i=0;str[i];i++)
			{
			sum+=alpha[str[i]]*(i+1);
			}
		printf("%d\n",sum);

		gets(str);
		}
	}