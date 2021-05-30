#include<stdio.h>
void main()
{//m
	unsigned long int n, k, t, m;
//freopen("input.txt","r",stdin);
	while(scanf("%ld%ld",&n,&k)!=EOF)
	{//1w
		t=n;
		do
		{//d
			m=(n%k);
			n/=k;
			t+=n;
			n+=m;
		}while(n>=k);
		printf("%ld\n",t);
	}//1w
}//m