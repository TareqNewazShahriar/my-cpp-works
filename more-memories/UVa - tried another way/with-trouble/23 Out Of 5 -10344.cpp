#include<stdio.h>
/*-----------------------------*/
int n[5]; char fill[5];
/*-----------------------------*/
bool _23_out_of_5(int tot,char i);
/*-----------------------------*/
void main()
{
freopen("in05.txt","r",stdin);
char i;
scanf("%d%d%d%d%d",&n[0],&n[1],&n[2],&n[3],&n[4]);
while(n[0]!=0&&n[1]!=0&&n[2]!=0&&n[3]!=0&&n[4]!=0)
{
	fill[0]=1;fill[1]=1;fill[2]=1;fill[3]=1;fill[4]=1;

	for(i=0;i<5;i++)
		if(_23_out_of_5(n[i],i+1)) puts("Possible");
	if(i==5) puts("Impossible");

	scanf("%d%d%d%d%d",n[0],n[1],n[2],n[3],n[4]);
}}
/*-------------------------------------*/
bool _23_out_of_5(int tot,char i)
{
	if(i==6)
	{
		if(tot==23)	return 1;
		else return 0;
	}	
	for(i=0;i<5;i++)
	{	if(fill[i]) 
		{	fill[i]=0;
			if(_23_out_of_5(tot+n[i],i+1)) return 1;
			fill[i]=1;
		}
	}
	for(i=0;i<5;i++)
	{	if(fill[i]) 
		{	fill[i]=0;
			if(_23_out_of_5(tot-n[i],i+1)) return 1;
			fill[i]=1;
		}
	}
	for(i=0;i<5;i++)
	{	if(fill[i]) 
		{	fill[i]=0;
			if(_23_out_of_5(tot*n[i],i+1)) return 1; 
			fill[i]=1;
		}
	}
	return 0;
}