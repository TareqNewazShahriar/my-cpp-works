#include<stdio.h>
#define R 8100
/*-------------------Global Variables------------------*/
/*-----------------Functions Prototypes----------------*/
/*--------------------main Function--------------------*/

void main()
{
//freopen("D:\\Programming\\Programming Language\\Turbo C++\\BIN\\in01.txt","r",stdin);
	int cs=0, s,t,n,i,j,k;
	char thic[R],th[]="***********************************",sq[]="...................................";
	for(i=R-1;i>=0;i--) thic[i]='*';
	scanf("%d%d%d",&s,&t,&n);

	while((s+t+n)!=0)
	{
	   thic[(s*n)+(t*n)+t]=0; th[t]=0; sq[s]=0;
	   printf("Case %d:\n",++cs);
	   for(k=0;k<n;k++)
	   {
		for(i=0;i<t;i++) puts(thic);
		for(i=0;i<s;i++)
		{
			for(j=0;j<n;j++) {	printf("%s%s",th,sq); } puts(th);
		}
	   }//for k
	   for(i=0;i<t;i++) puts(thic);
	   putchar(10);

	   thic[(s*n)+(t*n)+t]='*'; th[t]='*'; sq[s]='.';

		scanf("%d%d%d",&s,&t,&n);
	}
}