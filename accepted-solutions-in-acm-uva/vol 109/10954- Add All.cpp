#include<algorithm>
#include<stdio.h>
//#include<stdlib.h>
#define SIZE 5005
typedef int Type;

using namespace std;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
int compare( const Type &a, const Type &b )
	{	
	return a-b; 
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("in01.txt","r",stdin);
	Type n,i,j,num[SIZE];
	long/* */ long cost,sum;

	scanf("%d",&n);
	while(n)
		{
		for(i=0;i<n;i++) scanf("%d",num+i);

		sort(num,num+n);
		//qsort((void *)num,n,sizeof(Type),( int(*)(const void *,const void *) )compare);

		cost=0;
		num[n]=900000000;
		for(i=0,n--;i<n;i++)
			{
			sum=num[i]+num[i+1];
			cost+=sum;
			for(j=i+2;sum>num[j]; num[j-1]=num[j],j++);
			num[j-1]=sum;
			}

		printf("%lld\n",cost);

		scanf("%d",&n);
		}
	}