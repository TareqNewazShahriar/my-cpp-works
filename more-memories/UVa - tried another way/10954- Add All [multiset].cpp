#include<stdio.h>
#include<multiset>
typedef multiset<int> Mset;
/****************************Global Variables***************************/
using namespace std;
/*************************User Defined Functions************************/
/*****************************main Function*****************************/
void main()
	{
	Mset iset;
	int i,n,x,cost;

	scanf("%d",&n);
	while(n)
		{
		iset.clear();
		for(i=0;i<n;i++)
			{
			scanf("%d",x);
			iset.insert(x);
			}
		iset::iterator i=iset.begin(), j=iset.begin()+1;
		for( ; iset.size()!=1; i++)
			{
			x=*i+*j;
			iset.erase(i,j);
			cost+=x;
			iset.insert(x);
			}
		printf("%d",cost);

		scanf("%d",&n);
		}
	}