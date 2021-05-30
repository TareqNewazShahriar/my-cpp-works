#include<stdio.h>
#include<math.h>
void main()
{
	double rlt, n;
	while(scanf("%lf",&n)!=EOF)
	{
		rlt=sqrt(n);
		printf("Square Root %.3lf\n",rlt);
	}
}