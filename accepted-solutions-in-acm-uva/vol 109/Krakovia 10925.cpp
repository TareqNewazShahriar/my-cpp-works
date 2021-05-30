#include<stdio.h>
#include<string.h>
#define R 25
/*----Addintion of 2 string in common way(des_str,str1,str2,len1,len2)----*/
/*----------This func, assume that at last, there will has a carry----------*/
int ss_add_1(char *r,char *m,char *n,int len,int ln)
{   char sum=0; int i=len,k=ln, lenth;
	if(len<ln) { i=ln; k=len; } *(r+i+1)=0;
	lenth=i;
	for(len--,ln--;k;len--,ln--,i--,k--)
	{	sum+=(*(m+len))+(*(n+ln));
		if (sum>105) {	*(r+i)=sum-58; sum=1; }
		else { *(r+i)=sum-48; sum=0; }
	} 
	if(len>-1) 
		for(;len>-1;len--,i--) 
		{	sum+=(*(m+len));
			if (sum>57) { *(r+i)=48; sum=1; }
			else
			{	*(r+i)=sum;sum=0; k=i-1; 
				for(i-=2;i>-1;i--) *(r+i)=(*(m+i)); break;
			}
		}
	else if(ln>-1) 
		for(;ln>-1;ln--,i--) 
		{	sum+=(*(n+ln));
			if (sum>57) { *(r+i)=48; sum=1; }
			else
			{	*(r+i)=sum;sum=0; k=i-1;
				for(i-=2;i>-1;i--) *(r+i)=(*(n+i)); break;
			}
		}
	if(sum==1) { *r=49; lenth++; } 
	else strcpy(r+k,r+k+1);   
	return lenth;
}
/*------------Division of String and integer(des str,str,num,len)----------*/
void sn_dev(char *r,char *m,long n,int len)
{   int i=0,j=0; long dev=0;
	while(dev<n&&j<len) 
	{	dev=dev*10; dev+=(*(m+j))-48; j++; }
	do
	{	while(dev<n&&j<len)
		{	dev=dev*10; dev+=(*(m+j))-48; j++;
			if(dev<n&&j<len) *(r+i++)=48;
		} *(r+i++)=dev/n+48; dev%=n;
	}while(j<len); 
	*(r+i)=0;  
}

void main()/////////////////////////////////////////////////////////
{	int cs=0,i,len[2],item,friends;
	char flag, bill[2][R];
//freopen("submit.txt","r",stdin);
	while(scanf("%d%d",&item,&friends)!=EOF)
	{	if(item==0&&friends==0) break;
		if(item) { scanf("%s",bill[0]); len[0]=strlen(bill[0]); }
		flag=0;
		for(i=1; i<item; i++)
		{	flag=!flag;
			scanf("%s",bill[flag]);
			len[flag]=strlen( bill[flag] );
			len[flag]=ss_add_1(bill[flag],bill[0],bill[1],len[0],len[1]);
		}
		printf("Bill #%d costs %s: each friend should pay ",
				++cs,bill[flag]);
		flag=!flag;
		if(friends) sn_dev(bill[flag], bill[!flag], friends, len[!flag]);
		else  { bill[flag][0]=48; bill[flag][1]=0; }
		puts( bill[flag] ); putchar(10);
}	}

