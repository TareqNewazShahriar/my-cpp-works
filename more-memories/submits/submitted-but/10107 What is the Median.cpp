#include<stdio.h>
#define R 10001

long x[R],n,f=0,i,t;

void insertion_sort();

void main()
{
	long half; bool q=1;
	while(scanf("%ld",&n)==1)
	{
		insertion_sort();
		f++;
		if(q)
		{	printf("%ld\n",x[f/2]); q=0; }
		else
		{	half=f/2; q=1;
			printf("%ld\n",(x[half]+x[half-1])/2);
		}

	}
}
void insertion_sort()
{
	for(i=0;i<f&&n>x[i];i++);
	t=i;
	for(i=f;i>t;i--)
		x[i+1]=x[i];
	x[t]=n;
}