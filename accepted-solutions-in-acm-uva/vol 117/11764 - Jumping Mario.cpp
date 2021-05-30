// 11764 - Jumping Mario.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" /*
#include<stdio.h>	//*/

class HighLow
{
	int n, w1,w2, high, low, i;
	
public:	
	HighLow()	//constructor
	{
		high =0;
		low = 0;
	}
	void inputAndProcess()
	{
		scanf("%d", &n);
		if(n>0)
			scanf("%d", &w1);
		
		for(i=1; i<n; i++)
		{
			scanf("%d",&w2);
			
			if(w2 > w1)
				high++;
			else if(w2 < w1)
				low++;
			
			w1 = w2;
		}
	}
	void output(int k)
	{	
		printf("Case %d: %d %d\n", k, high, low);
	}
};


int main()
{
	//freopen("in.txt", "r", stdin);
	
	int cs, k;
	scanf("%d", &cs);
	for(k=1; k<=cs; k++)
	{
		HighLow obj;
		obj.inputAndProcess();
		obj.output(k);
	}
	
	return 0;
}

