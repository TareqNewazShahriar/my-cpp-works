#include<stdio.h>
#define R 1000
/*=======================*/
int tot,m,n,a; 
char fill[21],*x;
/*=======================*/
void prime_ring(int sum,int p);
/*=======================*/
void main()
{
freopen("in09.txt","r",stdin);
//freopen("outB.txt","w",stdout);
int cs=0,i;		
FILE *fp=fopen("B.out","w");
scanf("%d",&m);
while(m)
{	
	char v[5000]={0}; x=v;
	tot=0; n=1;
	for(i=1;i<m;fill[i]=0,i++);  fill[0]=1;

	if(m==1)
	{	
		printf("Case #%d: 1\n",++cs);
		fprintf(fp,"Case #%d: 1\n",cs);
	}
	else
	{	
		prime_ring( 0,0);	
		printf("Case #%d: %d\n",++cs,tot);
		fprintf(fp,"Case #%d: %d\n",cs,tot);
	}
	scanf("%d",&m);
}}		
void prime_ring(int sum,int p)
{	int i=0,s; n++;
	if(n==m)
	{	
		for(i=0;fill[i]&&i<m;i++);
		if(fill[i]==0)
		{	
			sum+=p*i; 
			if(x[sum]==0) 
			{	tot++; x[sum]=1; }
	}	}
	else
	{	
		while(i<m)
		{	
			if(fill[i]==0)
			{
				fill[i]=1; sum+=s=i*p;
				prime_ring(sum,i);
				fill[i]=0; sum-=s;
			}
			i++;
		}
	}
	n--;
}		