#include<stdio.h>
#define R 1000
#define CONST 5
/*---------------------------Global Variables--------------------------*/
int num[CONST];
bool fill[CONST];
/*++++++++++++++++++++++++User Defined Functions+++++++++++++++++++++++*/
bool create_23(int n,int tot)
	{
	//if(tot==23) return 1;
	if(n==5)
		{
		if(tot==23) return 1;
		return 0;
		}
	for(int i=0;i<5;i++)
		{
		if(fill[i]) continue;
		fill[i]=1;
		if(create_23(n+1,tot+num[i])) return 1;
		if(create_23(n+1,tot-num[i])) return 1;
		if(create_23(n+1,tot*num[i])) return 1;
		fill[i]=0;
		}
	return 0;
	}
/*----------------------------main Function----------------------------*/
void main()
	{
	//freopen("10344.txt","r",stdin);
	int i;
	scanf("%d%d%d%d%d",num,num+1,num+2,num+3,num+4);
	while( (num[0]+num[1]+num[2]+num[3]+num[4])!=0 )
		{
		fill[0]=0; fill[1]=0; fill[2]=0; fill[3]=0; fill[4]=0; 
		for(i=0;i<5;i++)
			{
			fill[i]=1;
			if(create_23(1,num[i])) break;
			fill[i]=0;
			}
		if(i==5) puts("Impossible");
		else puts("Possible");

		scanf("%d%d%d%d%d",num,num+1,num+2,num+3,num+4);
		}
	}