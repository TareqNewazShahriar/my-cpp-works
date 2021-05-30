// TLE
#include<stdio.h>
typedef long Type;
/****************************Global Variables***************************/
Type i, x,y,s,w,m,c1,c2;
/*************************User Defined Functions************************/
void min_max()
	{
	x=c1, y=c2;
	for(i=s;i;i--)
		{
		x=(x/s)*w;
		y=(y/s)*w;
		}
	x/=s;
	y=(y/s)+1;
	}
/*****************************main Function*****************************/
void main()
	{
	freopen("10726.txt","r",stdin);
	Type t,cs=0,u,count;
	scanf("%lld",&t);
	for(;t;t--)
		{
		scanf("%lld%lld%lld%lld",&s,&m,&c1,&c2);
		w=s-1; count=0;
		min_max();
		for(;x<y;x++)
			{
			u=s*x;
			for(i=s;i;i--)
				{
				if(u%w!=0) break;
				u/=w; u=(u*s)+m;
				}
			if(i==0) count++;
			}
		printf("Case %lld: %lld\n",++cs,count);
		}
	}