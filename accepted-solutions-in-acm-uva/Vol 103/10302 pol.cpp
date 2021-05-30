#include<stdio.h>
#include<math.h>
void main()
{    long double x;
	while(scanf("%Lf",&x)!=EOF)
	{	x=pow((x/2),2)*pow((x+1),2);
		printf("%.0Lf\n",x);
	}
}
