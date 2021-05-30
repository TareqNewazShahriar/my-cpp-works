#include<stdio.h>
#define R 101
#define T 3651
void main()
{
//freopen("F:\\Programming\\Problems Coding\\pACM Problems Coding\\in01.txt","r",stdin);
int t,d,p,i,j;
scanf("%d",&t);
for(;t;t--)
{
	scanf("%d%d",&d,&p);
	bool day[T]={0}; int party[R]={0};
	for(i=0;i<p;scanf("%d",&party[i]),i++);
	d++;
	for(i=0;i<p;i++)
	{
		for(j=party[i];j<d;j+=party[i])
			day[j]=1;
	}
	for(i=6;i<d;i+=7)
		day[i]=0,day[i+1]=0;
	for(i=0,j=0;i<d;i++)
		if(day[i]) j++;
	printf("%d\n",j);
}
}