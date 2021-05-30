#include<stdio.h>
#include<math.h>
void main()
{
	double fact[15]={1};
	int n;

	for(n=1;n<14;n++) fact[n]=fact[n-1]*n;

   	while(scanf("%d",&n)!=EOF)
	{
		if(7<n && n<14) printf("%.0lf\n",fact[n]);
		else if((n>=0)&&(n<8)) puts("Underflow!");
		else if(n>13) puts("Overflow!");
		else
		{	if(fmod(n,2)==0) puts("Underflow!");
			else puts("Overflow!");
		}
	}

}