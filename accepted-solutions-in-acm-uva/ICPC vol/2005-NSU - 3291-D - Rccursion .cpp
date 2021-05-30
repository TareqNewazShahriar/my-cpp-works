#include<stdio.h>
#include<stdlib.h>
#define A 40000
int num_com(const int *a,const int *b)
{    //int *x=(int *)a, *y=(int *)b;
	return *a-*b;
}
long comp_func(const long *x,const long *y)
	{ return *x-*y; }
void main()
{
//freopen("input.txt","r",stdin);
	long cs=0,n,x,i,num[A],k1,k2,sum;
	while(scanf("%ld",&n)!=EOF)
	{	if(n==0) break;
		for(i=0;i<n;scanf("%ld",&num[i]), i++);
		qsort((void *)num,n,sizeof(long),
			 ( int (*)(const void *,const void *))comp_func);
		k1=1; k2=0; sum=0; x=num[0];
		for(i=1;i<n;i++)
		{    if(num[i]==x) k1++;
			else
			{   	sum=k1*k2+sum;
				k2+=k1; k1=1; x=num[i];
		}	}
		printf("Case %ld: %ld\n",++cs,k1*k2+sum);
}	}