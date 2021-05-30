#include<stdio.h>
/*-------------------Global Variables------------------*/
/*-----------------Functions Prototypes----------------*/
/*--------------------main Function--------------------*/
void main()
{
	long double n;

	while(scanf("%Lf",&n)!=EOF)
	{
		printf("%.0Lf\n",( (n/2)*(n/2)) * ((n+1)*(n+1) ) );
	}
}