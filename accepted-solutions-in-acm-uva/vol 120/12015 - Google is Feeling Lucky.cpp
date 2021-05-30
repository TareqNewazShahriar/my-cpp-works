// 12015 - Google is Feeling Lucky-2.cpp : Defines the entry point for the console application.

//#include "stdafx.h"	/*
#include<stdio.h>	//*/
#include<iostream>
#include<string.h>
using namespace std;

#define R 10
#define S 101

class Map
{
	int  i,j, max, point[R];
	char url[R][S];
public:
	void input();
	void process();
	void output();
};
void Map::input()
{
	max=0;
	for(i=0; i<R; i++)
	{
		cin>>url[i]>>point[i];
		if(max < point[i])
		{
			max = point[i];
		}
	}
}
void Map::process()
{
	for(i=0; i<R; i++)
	{
		if(point[i]==max)
			for(j=i+1; j<R; j++)
			{
				if(max == point[j] && strcmp(url[i], url[j])==0)
				{
					point[j] = -1;
				}
			}
	}
}
void Map::output()
{
	for(i=0; i<R; i++)
	{
		if(max == point[i] )
		{
			cout<<url[i]<<endl;
		}
	}
}


int main()
{
	//freopen("in.txt", "r", stdin);
	int k, cs;
	Map m;
	scanf("%d", &cs);	
	for(k=1; k<=cs; k++)
	{
		cout<<"Case #"<<k<<":\n";
		m.input();
		m.process();
		m.output();
	}
	return 0;
}

