#include<stdio.h>
long double x;
long sum_all(long n)
{
	for(x=0.0000000000000000000;n>0;n--)  x+=n;
	return ++x;	   }
void main()/*:::::::::::::::::::::::::::::::::::::::::::::*/
{	long n;
//freopen("out.doc","w",stdout);
	while(scanf("%ld",&n)!=EOF)
	{    if(n<0) break;
		sum_all(n);
		printf("%.0Lf\n",x);
	}
}//m