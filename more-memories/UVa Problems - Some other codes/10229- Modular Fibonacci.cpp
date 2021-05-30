#include<stdio.h>
#define SIZE 1000
typedef long long Type;
/****************************Global Variables***************************/
Type n,m, i,h,j,k,t;
/*************************User Defined Functions************************/
/*-------------Divide & Conquare Fibonacci Algo[O(log n)]--------------*/
Type divide_conquer_fib()
	{
	i=1, h=1, j=0, k=0, t;
	while(n > 0)
		{
		if(n%2 == 1) // when n is odd
			{
			t = j*h;
			j = i*h + j*k + t;
			i = i*k + t;

			i%=m; j%=m; k%=m; h%=m;			
			}
		t = h*h;
		h = 2*k*h + t;
		k = k*k + t;
		n = n/2;

		i%=m; j%=m; k%=m; h%=m;
		
		//if( sto>j ) printf("ERR: %lld - %lld = %lld.\n",sto,j,sto-j); sto=j; // <^> debug code <^>
		}
	return j;
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("10229.txt","r",stdin);

	int i;
	while(scanf("%lld%lld",&n,&m)==2) // while(scanf("%lld",&n)==1)
		{
		if(m==0) puts("0");
		else
			{
			for(i=m,m=2;i>1;i--, m*=2);
		
			printf("%lld\n",divide_conquer_fib());
			}
		}
	}