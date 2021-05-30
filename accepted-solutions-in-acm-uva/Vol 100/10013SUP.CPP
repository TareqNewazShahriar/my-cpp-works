#include<stdio.h>
#include<string.h>
#define R 1000001
char a[R],b[R];
/*-----------------------Reverse(str,len)---------------------*/
void rev(long j)
{    long i=0;  char tmp;
	for(j--;i<j;i++,j--) { tmp=a[i]; a[i]=a[j]; a[j]=tmp; }}
/*----------Addition of 2 string(des str,str1,str2,len1,len2)------------*/
void ss_add(long len)//<Require rev()>
{    int sum; long i;
	for(sum=0,i=0;i<len;i++)
	{	sum+=a[i]+b[i];
		if (sum>9) {	a[i]=sum+38; sum=1; }
		else  { a[i]=sum+48; sum=0; }
	}if(sum==1) { a[i]=49; a[++i]=0; }
	 else  a[i]=0; rev(i);  }
void main()//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
{//m
	char q=0; int cs,x,y; long len,in;
//freopen("input.txt","r",stdin);
//freopen("out.doc","w",stdout);
	scanf("%d",&cs);
	for(;cs>0;cs--)
	{    if(q==1) printf("\n"); q=1;
		scanf("%ld",&len);
		for(in=len-1;in>-1;in--)
		{	scanf("%d%d",&x,&y); a[in]=x; b[in]=y; }
		ss_add(len);
		printf("%s\n",a);
}	}//m