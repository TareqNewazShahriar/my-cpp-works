// 11942 - Lumberjack Sequencing.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h" /*
#include<stdio.h>	//*/
#include<iostream>
using namespace std;

class CheckOrder
{
	int n[11], i;
	enum order{asc, desc};
	order o, p;
	bool status;
	
public:
	void input()
	{
		scanf("%d%d%d%d%d%d%d%d%d%d", n+1, n+2, n+3, n+4, n+5, n+6, n+7, n+8, n+9, n+10);
	}
	void prcess()
	{
		status = true;
		//pass the equal values
		for(i=1; i<10 && n[i]==n[i+1]; i++);
		
		// find the order
		if(i<10)
		{
			if(n[i] < n[i+1])
				o = asc;
			else if(n[i] > n[i+1])
				o = desc;
		}
		
		for(; i<10; i++)
		{
			if( (n[i] < n[i+1] && o == desc) || (n[i] > n[i+1] && o == asc) )
			{	status = false; break; }
		}
	}
	void output()
	{
		if(status == true)
			cout<<"Ordered"<<endl;
		else
			cout<<"Unordered"<<endl;
	}
};


int main()
{
	//freopen("in.txt", "r", stdin);

	int k, cs;
	
	CheckOrder obj;
	
	scanf("%d", &cs);	
	cout<<"Lumberjacks:"<<endl;
	for(k=1; k<=cs; k++)
	{
		obj.input();
		obj.prcess();
		obj.output();
	}
	return 0;
}

