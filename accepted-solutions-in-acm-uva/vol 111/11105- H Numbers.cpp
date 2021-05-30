#include<stdio.h>
#define SIZE 1000002
#define CON 100
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*****************************main Function*****************************/
void main()
	{
	//freopen("A_out.txt","w",stdout);
	int i,j,n,k,u,hn,x, pary[SIZE/CON]={0};
	char h[SIZE]={0};
	
	for(i=1;i<250;i++)
		{
		u=4*i+1;
		if(h[u]) continue;
		x=u;
		for(j=i;(hn=u*x)<SIZE;j++,x=(j*4)+1 )
			{
			if(h[hn]==0)
				{
				if(h[x]==0) h[hn]=1;
				else h[hn]=2;
				}
			}
		}

	for(i=1;i<250;i++)
		{
		u=4*i+1;
		if(h[u]) continue;
		x=u;
		for(j=i;(hn=u*x)<SIZE;j++,x=(j*4)+1 )
			{
			if(h[x]&&h[hn])
				{
				h[hn]=0;
				}
			}
		}
	u=1; k=0;
	for(i=25;i<SIZE;i++)
		{
		if(h[i]==1) k++;
		if(i%CON==0) pary[u++]=k;
		}

	scanf("%d",&n);
	while(n)
		{
		n++;
		u=n/CON;
		k=pary[u];
		for(i=u*CON+1;i<n;i++)
			{
			if(h[i]==1) k++;
			}
		printf("%d %d\n",n-1,k);
		
		scanf("%d",&n);
		}
	}