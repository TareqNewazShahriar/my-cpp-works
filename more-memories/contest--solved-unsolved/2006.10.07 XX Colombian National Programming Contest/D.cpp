// WA
#include<stdio.h>
//#include<math.h>
#define SIZE 10000
typedef unsigned long Type;
typedef int Declare;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*****************************main Function*****************************/
void main()
	{
	//freopen("d.txt","r",stdin);
	//freopen("d out.txt","w",stdout);

	Type a,b;
	Declare cs=0,n[SIZE],dig[SIZE], i,j,k,u,v,mod, step;

	
	scanf("%llu%llu",&a,&b);
	while(a||b)
		{
		printf("Case %d:\n%llu / %llu\n",++cs,a,b);
		step=0;
		for(k=0;b;k++)
			{
			mod=a%b;
			n[k]=a/b;
			a=b;
			b=mod;

			v=n[k]; u=-1;
			if(v<0) u++;
			do
			{	v/=10;
				u++;
			}while(v);
			dig[k]=u+1;
			step+=u+4;
			}
		step++;
		if(n[k-1]!=1)
			{
			n[k-1]=n[k-1]-1;
			n[k]=1;
			}
		else { 	k--; step-=dig[k]+3; }

		u=0;
		for(i=0;i<k;i++)
			{
			u+=dig[i]+3;
			for(j=0;j<u;j++) putchar('.');
			
			v=j+(step-j)/2;
			if((step-j)%2) v++;

			for(j++;j<v;j++) putchar('.');
			putchar('1');
			for(;j<step;j++)  putchar('.');
			putchar('\n');

			u-=dig[i]+3;
			for(j=0;j<u;j++) putchar('.');
			printf("%d.+.",n[i]);
			
			for(j+=dig[i]+3;j<step;j++)  putchar('-');
			putchar('\n');

			u+=dig[i]+3;
			}
		for(j=1;j<step;j++)  putchar('.');
		printf("1\n");


		scanf("%llu%llu",&a,&b);
		}
	}