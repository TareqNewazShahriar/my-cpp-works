#include<stdio.h>
#include<vector>
#include<algorithm>
#define INF 20000002
#define INFn -1
using namespace std;
typedef int Type;
typedef vector<Type> VECT;

/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*****************************main Function*****************************/
void main()
	{
	//freopen("a.txt","r",stdin);
	Type i,k,day,n,tot,max,min,mi,ni, x,cost;
	scanf("%d",&day);
	while(day)
		{
		VECT list;
		tot=cost=0;
		//max=INFn; min=INF;
		for(;day;day--)
			{			
			scanf("%d",&k); tot+=k;
			for(i=k;i;i--) { scanf("%d",&n); list.push_back(n); }
			min=max=list[mi=ni=0];
			for(i=1;i<tot;i++)
				{
				x=list[i];
				if(max<x) max=x, mi=i;
				else if(min>x) min=x, ni=i;
				}
		cost+=max-min;
		if(ni<mi) mi--;
		list.erase(list.begin()+ni);
		list.erase(list.begin()+mi);
		//x=list.size();
		tot-=2;
			}
		printf("%d\n",cost);
		scanf("%d",&day);
		}
	}