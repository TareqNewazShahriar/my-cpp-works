// TLE - factorising kills the time
#include<stdio.h>
#include<math.h>
#include<algorithm> // debug
#define SIZE 10000

using namespace std; // debug
//typedef long Type; /*
typedef __int64 Type; //*/
/****************************Global Variables***************************/
Type n,dev[SIZE],u;

/*************************User Defined Functions************************/

/*____________Load devisor of 'n' Typeo two array by evaluate the sqrt of n___________*/
/*_(Type n, Type left_devisor, Type right_devisor, Type tot_left_dev, Type tot_right_dev)_*/
void load_devisor()
{
	Type i,sq;
	u=0;
	sq=sqrt(n)+1;
	for(i=2;i<sq;i++)
	{
		if(n%i==0) dev[u++]=i, dev[u++]=n/i;
	}
	if(u&&dev[u-1]==dev[u-2]) u--;
	if(n>1) dev[u++]=n;

	sort(dev,dev+u);
}
/**Convert the val from 10base to "to"base.||Require- num_equiv(), ASCII_equiv(), rev()***/
Type base_conv(Type digi,Type to)
{	
	Type count=0;
	for( ;digi%to==0; count++,digi/=to);
	return count;
}	
/*****************************main Function*****************************/
void main()
	{
	freopen("2195 F.txt","r",stdin);
	freopen("2195 F out.txt","w",stdout);

	Type i,k,m,d, x;
	//char str[SIZE],*p;

	scanf("%I64d",&n);
	while(n)
		{
		load_devisor();
		k=0;
		for(i=0;i<u;i++)
			{
			m=n; d=dev[i];
			x=k;
			for(k++,m/=d ;m%d==0; k++,m/=d);

			if(x+1==k) printf("%I64d, ",dev[i]); // debug
			else printf("%I64d-%I64d, ",dev[i],k-x);  // debug
			}
		puts("");  // debug
		printf("#%I64d %I64d#\n",n,k);

		scanf("%I64d",&n);
		}
	}