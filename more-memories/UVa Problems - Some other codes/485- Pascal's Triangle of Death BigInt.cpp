#include<stdio.h>
#include<BigInt_Al.h>
#define SIZE 5001
typedef __int64 Type;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*****************************main Function*****************************/
void main()
	{
	int n;
	BigInt fib[Size];

	//for(n=0;n<Size;n++) encode(fib[n]);
	
	fib[0].digits=0;
	fib[1].digits=1;

	for(i=2;i<Size;i++)
		fib[i]=fib[i-1]+fib[i-2];
	
	while(scanf("%d",&n)==1)
		{
		decode(fib[n]);
		printf("The Fibonacci number for %d is %s\n",n, fib[n].digits.c_str());
		}
	}
