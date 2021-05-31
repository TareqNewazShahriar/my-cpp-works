#include<stdio.h>
#include<math.h>
typedef __int64 Type;
/****************************Global Variables***************************/
//total prime 6493.  0=Prime, 1=Composite.
/*****************************main Function*****************************/
void main()
	{
	//freopen("10006.txt","r",stdin);

	int m,n,i,p,sq,count,
		prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,
				 103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,
				 199,211,223,227,229,233,239,241,251};
				 //total prime 54
	scanf("%d",&n);
	while(n)
		{
		m=n;
		p=count=0;
		sq=sqrt(n)+1;
		while(n!=1&&prime[p]<sq)
			{
			if(n%prime[p]==0) 
				{
				count++;
				n/=i=prime[p];
				for( ; n%i==0; n/=i);
				}
			p++;
			}
		if(count>=3)	// || (n!=1&&count>=2) ) // Why not 6410? Because, 2*5*641=6410
			printf("The number %d is a Carmichael number.\n",m,count);
		else printf("%d is normal.\n",m);
		
		scanf("%d",&n);
		}
	}