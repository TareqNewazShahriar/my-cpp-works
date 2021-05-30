#include<stdio.h>
#define R 12
#define T 100
/*------Global Variables-------*/
int num[R],tot,n, output[R],u,ele,v; char q;
/*----------Functions----------*/
void sum_of_subset(int sum,int i); //void display();
/*-------------Main------------*/
void main()
{
//freopen("in08.txt","r",stdin);
int i;
while(scanf("%d%d",&tot,&n)==2&&n!=0)
{
	for(i=0;i<n;scanf("%d",&num[i]),i++);
	ele=-1; i=0; q=1;
	printf("Sums of %d:\n",tot);
	sum_of_subset(0,0);
	if(q) puts("NONE");

}}
/*-------Find the sum from the subset-------*/
void sum_of_subset(int sum,int i)
{	ele++;
	while(i<n)
	{	sum+=output[ele]=num[i];
		if(sum==tot)
		{	
			printf("%d",output[0]); q=0;
			for(u=1;u<=ele;printf("+%d",output[u]),u++);
			putchar(10);  sum-=u=num[i++];
			while(u==num[i]&&i<n) i++;			
		}
		else if(sum<tot)
		{	sum_of_subset(sum,i+1); 
			//v=i+1; u=num[n-i];  while(u<=num[v]&&v<n) v++;
			//sum_of_subset(sum,v);
			sum-=u=num[i++];
			while(u==num[i]&&i<n) i++;
		}
		else 
		{	sum-=num[i++]; u=tot-sum;
			while(u<num[i]&&v<n) i++;
		}		
	}
	ele--;
}		