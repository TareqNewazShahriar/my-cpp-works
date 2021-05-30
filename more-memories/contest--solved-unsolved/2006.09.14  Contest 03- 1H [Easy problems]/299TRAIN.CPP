#include<stdio.h>
#define R 100
/*-------------------Global Variables------------------*/
/*-----------------Functions Prototypes----------------*/
/*--------------------main Function--------------------*/
void main()
{
	long cs,n,i,c,m,com[R],q,tmp;
	scanf("%ld",&cs);
	for(;cs;cs--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++) scanf("%ld",com+i);
		m=n-1; q=1; c=0;
		while(q) // Bubble Sort
		{
			q=0;
			for(i=0;i<m;i++)
			{
				if(com[i]>com[i+1])
				{
					q=1; c++;
					tmp=com[i]; com[i]=com[i+1]; com[i+1]=tmp;
				}
			}
		}
		printf("Optimal train swapping takes %ld swaps.\n",c);
	}
}