#include<stdio.h>
#define R 25
/*---------------------------Global Variables--------------------------*/
/*--------------------------Function Prototypes------------------------*/
/*----------------------------main Function----------------------------*/
void main()
{
//freopen("in01.txt","r",stdin);
	int cs,i,n,farm,env,sum;
	scanf("%d",&cs);
	for(;cs;cs--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&farm,&env,&env);
			sum+=farm*env;
		}
		printf("%d\n",sum);
	}
}