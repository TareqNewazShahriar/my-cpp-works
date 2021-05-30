#include<stdio.h>
/****************************Global Variables***************************/
int mod,x;
/*************************User Defined Functions************************/
int bigmod(int b,int p,int m)
	{
	if(p==0) return 1;
	else if(p%2==0)
		{
		x=bigmod(b,p/2,m);
		return (x*x)%m;
		}
	return mod*bigmod(b,p-1,m)%m;
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("374.txt","r",stdin);
	int b,p,m;
	while(scanf("%d%d%d",&b,&p,&m)==3)
		{
		mod=b%m;
		printf("%d\n",bigmod(b,p,m));
		}
	}