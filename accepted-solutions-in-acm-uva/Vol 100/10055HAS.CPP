#include <stdio.h>
//#include<math.h>
void main()
{	long long int a, b, c;
	//freopen("scan.txt","r",stdin);
	while(scanf("%lld%lld",&a,&b)!=EOF)
	{    if(a>b)
			printf("%lld\n",(a-b));
		else
			printf("%lld\n",(b-a));
	}
}