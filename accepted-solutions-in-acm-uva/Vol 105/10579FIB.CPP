#include<stdio.h>
#include<string.h>
#define R 1000000
/*----Reverse and copy to destination simultaneously(des_str,str,len)----*/
void revcop(char *des,char *s,int len)
{    int i=0,j=len-1; *(des+len)='\0';
	for(len=len/2+1;i<len;i++,j--) { *(des+i)=*(s+j); *(des+j)=*(s+i); }}
/*-----------------------Reverse(str,len)---------------------*/
void rev(char *s,int j)
{    int i=0;  char tmp;
	for(j--;i<j;i++,j--) { tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }}
/*----------Addition of 2 strings(des str,str1,str2,len1,len2)------------*/
int ss_add(char *r,char *u,char *v,int len,int i)//<Require revcop & rev>
{    char m[1046],n[1046], sum;
	revcop(&m[0],u,len); revcop(&n[0],v,i);
	if(len>i) for(;i<len;i++) n[i]=48;
	else if(len<i) for(;len<i;len++) m[len]=48;
	for(sum=0,i=0;i<len;i++)
	{	sum+=(m[i]+n[i]);
		if (sum>105) {	*(r+i)=sum-58; sum=1; }
		else  { *(r+i)=sum-48; sum=0; }
	}if(sum==1) { *(r+i)=49; *(r+(++i))=0; }
	 else  *(r+i)=0; 	rev(r,i); return len;  }
void main()/*:::::::::::::::::::::::::::::::::::::::::::::*/
{	char fib[2][1046],r[1046]; int len[2],k=1,n,sum,i,tmp;
//freopen("out.doc","w",stdout);
	while(scanf("%ld",&n)!=EOF)
	{    if(n<3) printf("1\n",n);
		else
		{	fib[0][0]=49;fib[0][1]=0; fib[1][0]=49;fib[1][1]=0; len[0]=1;
			for(n-=2,k=1;n>0;n--)
			{    len[k]=strlen(fib[k]);
				len[k]=ss_add(r,&fib[0][0],&fib[1][0],len[0],len[1]);
				strcpy(fib[!k],r); k=!k;
			}printf("%s\n",r);
}	}	}//m