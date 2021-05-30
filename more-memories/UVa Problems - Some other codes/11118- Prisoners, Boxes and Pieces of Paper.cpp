#include<stdio.h>

void main()
	{
	int n,cs=0,t;
	scanf("%d",&t);
	for(;t;t--)
		{
		scanf("%d",&n);
		printf("Case #%d: 0.50000000 %d.00000000\n",++cs,n);
		}
	}