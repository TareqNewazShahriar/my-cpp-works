#include<stdio.h>
#include<math.h>
void main()
{    long long int x;
	while(scanf("%lld",&x)!=EOF)
	{	x=pow((x/2),2)*(pow((x+1),2));
		printf("%lld\n",x);
	}
}