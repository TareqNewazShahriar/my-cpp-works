// WA
#include<stdio.h>
#define SIZE 10000
#define CON 25
typedef unsigned long long Type;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*---Division of String and integer(des str,str,num,len) return the length---*/
int sn_dev(char *r,char *m,long n,int len)
{
	int i=0,j=0;
	long dev=0;
	while(dev<n&&j<len)
	{	dev=dev*10; dev+=(*(m+j))-48; j++; }
	
	do
	{	while(dev<n&&j<len)
		{	
			dev=dev*10; dev+=(*(m+j))-48; j++;
			if(dev<n&&j<len) *(r+i++)=48;
		} 
	*(r+i++)=dev/n+48;
	dev%=n;
	}while(j<len);
	
	*(r+i)=0;
	return i;
}
/*****************************main Function*****************************/
void main()
	{
	//freopen("d.txt","r",stdin);
	//freopen("d out.txt","w",stdout);

	Type cs=0,n[SIZE],dig[SIZE], b,i,j,k,u,v,mod, step;
	char a[CON];
	
	scanf("%s%llu",a,&b);
	while(a||b)
		{
		printf("Case %llu:\n",++cs);
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
			printf("%llu.+.",n[i]);
			
			for(j+=dig[i]+3;j<step;j++)  putchar('-');
			putchar('\n');

			u+=dig[i]+3;
			}
		for(j=1;j<step;j++)  putchar('.');
		printf("1\n");


		scanf("%s%s",a,b);
		}
	}