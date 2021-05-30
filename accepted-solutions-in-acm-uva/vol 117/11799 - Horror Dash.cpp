// 11799 - Horror Dash.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" /*
#include<stdio.h>	//*/

class SpeedBalance
{
	int n, max, x, i;
public:
	void inputAndStoreMax();
	void output(int k);
	
};

void SpeedBalance::inputAndStoreMax()
{
	scanf("%d", &n);
	if(n>0)
	{
		scanf("%d", &x);
		max = x;
	}
	else max =0;
	
	for(i=1; i<n; i++)
	{
		scanf("%d", &x);
		if( x > max)
			max = x;
	}
}
void SpeedBalance::output(int k)
{
	printf("Case %d: %d\n", k, max);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	
	int k, cs;
	scanf("%d", &cs);
	
	SpeedBalance obj;
	for(k=1; k<=cs; k++)
	{
		obj.inputAndStoreMax();
		obj.output(k);
	}
	
	return 0;
}

