#include<stdio.h>
#include<math.h>
#define R 101
/*-------------------------------------------------------*/
void prime_frequency(short prime[],short freq[]);
short	x[R][R]={0},
		prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
/*-------------------------------------------------------*/
void main()
{
//freopen("F:\\Programming\\Problems Coding\\pACM Problems Coding\\in08.txt","r",stdin);
	int n;
	short i,k,m,freq[R]={0};
	const bool sprime[]={1,1,0,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0};
	//total 26
	prime_frequency(prime,freq);
	scanf("%d",&n);
	while(n)
	{
		printf("%3d! =",n);
		m=0;
		for(i=2,k=freq[n];i<=k;i++)
		{
			if(sprime[i]==0)
			{	m++;
				if(m==16) printf("\n      ");
				printf("%3d",x[n][i]);
			}
		}
		putchar(10);
		
		scanf("%d",&n);
	}
}
/*-----------------------------------------------------------*/
void prime_frequency(short prime[],short freq[])
{
	short i,j,sq,p,k;
	for(i=2;i<101;i++)
	{
		sq=sqrt(i)+1; p=i;
		for(j=0;prime[j]<sq&&p!=1;j++)
		{				
			if(p%prime[j]==0)
			{
				k=prime[j];
				if(k>freq[i]) freq[i]=k;
				for(; p%k==0; p/=k,x[i][k]++);
			}
		}
		if(p!=1)
			x[i][p]++,freq[i]=p;
		
		j=i-1;
		if(freq[j]>freq[i]) freq[i]=freq[j];
		for(k=2;k<=freq[j];k++)
			x[i][k]+=x[j][k];
	}
}