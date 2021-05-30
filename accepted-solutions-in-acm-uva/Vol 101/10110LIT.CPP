#include<stdio.h>
#include<math.h>
void main()
{	unsigned long n,m;
	while(scanf("%lu",&n)!=EOF)
	{    if(n==0) break;
		m=sqrt(n);
		if(m*m==n) printf("yes\n");
		else printf("no\n");
	}
}//m