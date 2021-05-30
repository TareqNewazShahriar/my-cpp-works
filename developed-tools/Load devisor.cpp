#include<stdio.h>
#include<math.h>
#define SIZE 1000
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
void load_devisor(int n,int ld[],int rd[],int &u,int &v)
{
	int i,sq;
	u=0,v=0;
	sq=sqrt(n)+1;
	for(i=1;i<sq;i++)
	{
		if(n%i==0) ld[u++]=i, rd[v++]=n/i;
	}
	if(ld[u-1]==rd[v-1]) v--;
}
/*****************************main Function*****************************/
void main()
	{
	int ld[SIZE],rd[SIZE],n, u,v;
	while(scanf("%d",&n)==1)
		{
		load_devisor(n,ld,rd, u,v);
		for(n=0;n<u;n++)
			printf("%d ",ld[n]);
		puts("");
		for(n=0;n<v;n++)
			printf("%d ",rd[n]);
		puts("");
		}
	}