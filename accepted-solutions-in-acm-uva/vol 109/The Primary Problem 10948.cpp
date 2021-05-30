#include<stdio.h>
#define R 1000001
/*----Load Primes in a static array by Sieve Algorithm up to index R(array_name)----*/
//--------prime 0 , non-prime 1 ---------
void seive_prim(char *prim)
{	long i,j;
	for(i=4;  i<R;  *(prim+i)=1,i+=2);

	for(i=3;i<R;i+=2)
	{	if(*(prim+i)==0)
			for(j=i+i;j<R;*(prim+j)=1,j+=i);
}	}

void main()
{	long n,m, p1; static char prim[R]={1};
	seive_prim(prim);
//freopen("submit.txt","r",stdin);
	scanf("%ld",&n);
	while(n)
	{	
		p1=2;
	if(prim[n-2]==0);
	else
		{	p1=3; m=n/2; if(m%2==0) m++;
			while(prim[n-p1]&&m>p1)
			{
				for(p1+=2;prim[p1]&&p1<m;p1+=2)
				{
					//if(==0) break;
				}
			}
		}
		if(prim[n-p1]) printf("%ld:\nNO WAY!\n",n);
		else printf("%ld:\n%ld+%ld\n",n,p1,n-p1);

		scanf("%ld",&n);
	}
}