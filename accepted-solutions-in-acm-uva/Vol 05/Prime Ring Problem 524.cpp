#include<stdio.h>
#define R 17
/*---------Global Variables-----------*/
int x,prime[R], n, fill[R],
	svprm[]={1,1,0,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,0};
/*-------------Functions-------*/
void prime_ring(int m);
/*---------------Main--------------*/
void main()
{
//freopen("in05.txt","r",stdin);
//freopen("f:\\Trq.out","w",stdout);
int cs=0;
while(scanf("%d",&x)!=EOF)
{	for(n=1;n<=x;fill[n]=0,n++);
	if(cs) putchar(10);
	printf("Case %d:\n",++cs);
	prime[1]=fill[1]=n=1;
	prime_ring(1);		//printf("- %d -",y);
	//putchar(10);
}
}
void prime_ring(int m)
{	int i; n++;
	if(n==x)
	{	
		for(i=2;fill[i]&&i<=x;i++);
		if(fill[i]==0&&svprm[i+1]==0&&svprm[prime[x-1]+i]==0)
		{	
			prime[n]=i;
			printf("1");
			for(i=2;i<=x;printf(" %d",prime[i]),i++);
			putchar(10);
	}	}
	else
	{	i=m%2==0 ? 3 : 2 ;
		while(i<=x)
		{	
			if(fill[i]==0&&svprm[m+i]==0)
			{
				fill[i]=1; prime[n]=i;
				prime_ring(i);
				fill[i]=0;
			}
			i+=2;
		}
	}
	n--;
}		