#include<stdio.h>
#include<string.h>
#define SIZE 10000
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*----Find out is "str" divisible by "devider" or not(str,len,devider)-----*/
long sn_dev(char *m,int len, long d)
{   
	int i=0,j=0; long dev=0;
	while(dev<d&&j<len) 
	{	dev=dev*10; dev+=(*(m+j))-48; j++; }
	do
	{ 
		while(dev<d&&j<len)
		{	
			dev=dev*10; 
			dev+=(*(m+j))-48; j++;
			//if(dev<d&&j<len) 
			//	*(r+i++)=48;
		} 
		//*(r+i++)=dev/d+48; 
		dev%=d;
	}while(j<len); 
	//*(r+i)=0;  
	if(dev)	return 0;
	return 1;
}
/*****************************main Function*****************************/
void main()
	{
	bool q=0,lp,h,b;
	char year[SIZE];
	int len;
	while(scanf("%s",year)!=EOF)
		{
		if(q) putchar(10);    q=1;
		
		lp=h=b=0;
		len=strlen(year);
		if((sn_dev(year,len,4)&&!(sn_dev(year,len,100))) || sn_dev(year,len,400) )
			{
			lp=1;
			if(sn_dev(year,len,55)) b=1;
			}
		if(sn_dev(year,len,15)) h=1;

		if(lp) puts("This is leap year.");
		if(h) puts("This is huluculu festival year.");
		if(b) puts("This is bulukulu festival year.");
		
		if(lp==0&&h==0&&b==0)
			puts("This is an ordinary year.");
		}
	}