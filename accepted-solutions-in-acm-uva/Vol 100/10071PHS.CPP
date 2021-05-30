#include<stdio.h>
void main()
{    long s;
	int v, t;
	while(scanf("%d %d", &v, &t)!=EOF)
	{    s=2*long(v)*long(t);
		printf("%ld\n",s);
	}
}