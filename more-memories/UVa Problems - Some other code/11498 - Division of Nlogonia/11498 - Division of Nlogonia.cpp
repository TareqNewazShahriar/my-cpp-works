// 11498 - Division of Nlogonia.cpp : Defines the entry point for the console application.
//#include "stdafx.h" /*
#include <stdio.h> //*/

int main()
{
	//freopen("in.txt","r",stdin);
	
	long k, n,m, x,y;
	scanf("%ld",&k);
	while( k!=0 )
	{
		scanf("%ld%ld", &m,&n);
		
		for(; k>0; k--)
		{
			scanf("%ld%ld",&x,&y);
			if(m==x || n==y)
				printf("divisa\n");
			else if(x<m && y<m)
				printf("SO\n");
			else if(x<m && y>m)
				printf("NO\n");
			else if(x>m && y<m)
				printf("SE\n");
			else
				printf("NE\n");
		}
		scanf("%ld",&k);
	}
	return 0;
}
