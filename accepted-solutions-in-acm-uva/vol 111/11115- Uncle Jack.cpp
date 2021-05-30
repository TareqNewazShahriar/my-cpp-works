// AC
#include<stdio.h>
#define SIZE 1000
typedef int Type;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*-----------------------Reverse(str,len)---------------------*/
void rev(char *s,int j)
{   
	int i=0;  
	char tmp;
	for(j--;i<j;i++,j--)
	{	tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }
}
/*----Multiplication between string and int(des_str,str,int,len)----*/
/*------------The 2nd number b < 21474836. Require rev()------------*/
int si_multiplication(char *r, char *a, long b, int len)
{	
	int i,j;
	unsigned long m=0;
	for(i=len-1,j=0;i>-1;i--)
	{	
		m+= ((*(a+i))-48)* b;
		*(r+ j++)=(m%10)+48;
		m/=10;
	}
	while(m)
	{	*(r+ j++)=(m%10)+48; m/=10; }
	
	if(*(r+j-1)==0) {  *r=48; j=1; }
	else rev(r,j);  *(r+j)=0;
	
	return j;
}
/*****************************main Function*****************************/
void main()
	{
	//freopen("f.txt","r",stdin);
	Type i,j, x,d,len;
	char n[50], r[50];
	
	scanf("%d%d",&x,&d);
	while(x||d)
		{
		if(d==0) { r[0]='1';r[1]=0; }
		else if(x==10)
			{ len=2; n[0]='1'; n[1]='0'; n[2]=0; }
		else{ len=1; n[0]=x+48; n[1]=0; }

		if(d==1) { r[0]=n[0]; r[1]=n[1]; r[2]=n[2]; }
		else
			{
			for(i=1;i<d;i++)
				{
				len=si_multiplication(r,n,x,len);
				for(n[len]=0,j=len-1;j>=0;n[j]=r[j],j--);
				}
			}
		puts(r);
		
		scanf("%d%d",&x,&d);
		}
	}