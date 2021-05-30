#include<stdio.h>
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*****************************main Function*****************************/
void main()
	{
	long long n;//210 000 000

	scanf("%lld",&n);
	while(n>=0)
		{
		printf("%lld\n",(n*(n+1))/2+1);

		scanf("%lld",&n);
		}
	}