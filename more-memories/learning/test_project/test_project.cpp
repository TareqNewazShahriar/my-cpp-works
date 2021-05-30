// test_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

__int64 fact(__int64 k);
int main()
{
	__int64 x,n;
	scanf("%I64d",&n);
	x=fact(n);
	printf("%I64d",x);
	return 0;
}
__int64 fact(__int64 k)
	{
		__int64 y;
		if(k==0)
		return 1;
		y=k*fact(k-1);
		return y;	
	}
