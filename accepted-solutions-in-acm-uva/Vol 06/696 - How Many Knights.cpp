// 696 - How Many Knights.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"	/*
#include<stdio.h>	//*/
#include<iostream>
using namespace std;

class Knights
{
public:
	int process(int a, int b)
	{
		int r=0, m, d;
		if(a > b)
		{	r=a; a=b; b=r;	}
		
		if(a<1) return 0;	// this check is not necessary. (tested)
		else if(a == 1)	return b;
		else if(a == 2 && b ==2)	return 4;
		else if(a==2) // and col > 2
		{
			m = b%4;
			d = b/4;
			r = d*4;
			if(m==1) r += 2;
			else if(m==2 || m==3) r += 4;
			return r;
		}
		else return (a*b+1)/2;
		return r;
	}
};


int main()
{
	//freopen("in.txt", "r", stdin);
	int a, b, c;
	Knights knight;
	while( scanf("%d%d", &a, &b)==2)
	{
		if(a==0 && b==0) break;
		
		c = knight.process(a,b);
		printf("%d knights may be placed on a %d row %d column board.\n", c, a, b);
	}
	return 0;
}

