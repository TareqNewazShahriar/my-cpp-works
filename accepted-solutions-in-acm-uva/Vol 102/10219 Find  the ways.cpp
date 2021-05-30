#include<stdio.h>
#include<math.h>
void main()
{
long double n,k, res;
while(scanf("%Lf%Lf",&n,&k)!=EOF)
{
	res=0;

	while(k)
	{
		res+=log10(n)-log10(k);
		n--,k--;
	}
	res=floor(res)+1;
	printf("%.0Lf\n",res);
}
}