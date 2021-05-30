#include<stdio.h>
#include<queue>
#define R 1000

using namespace std;
/****************************Global Variables***************************/
int ferry,m;

typedef queue<int> QUE;
QUE lque,rque;
/*************************User Defined Functions************************/
void input()
	{
	int i,car;
	char side[R];
	scanf("%d%d",&ferry,&m);
	ferry*=100;
	for(i=0;i<m;i++)
		{
		scanf("%d%s",&car,side);
		if(*side=='l') lque.push(car);
		else rque.push(car);
		}
	}
/*-----------Count the Ferry's amount of crossing the rever-----------*/
int ferry_loading()
	{
	int tmp,arrive,count=0,
		u=lque.size(),v=rque.size();
	bool q=1;
	while(m)
		{
		if(q)
			{
			q=0; count++; arrive=ferry;
			while(u)
				{
				tmp=lque.front();
				if(arrive-tmp>=0)
					{
					u--, m--;
					arrive-=tmp;
					lque.pop();
					}
				else break;
				}
			}
		else
			{
			q=1; count++; arrive=ferry;
			while(v)
				{
				tmp=rque.front();
				if(arrive-tmp>=0)
					{
					v--, m--;
					arrive-=tmp;
					rque.pop();
					}
				else break;
				}
			}
		}
	return count;
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("11034.txt","r",stdin);
	int cs;
	scanf("%d",&cs);
	for(;cs;cs--)
		{
		input();
		printf("%d\n",ferry_loading());
		}
	}
