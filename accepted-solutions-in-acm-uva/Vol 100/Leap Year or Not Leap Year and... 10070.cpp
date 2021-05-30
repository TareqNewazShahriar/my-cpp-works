#include<stdio.h>
#include<string.h>
#define R 50000
/*------------Calculate remainder by Dividing String and integer(str,len)----------*/
long sn_dev(char *m,int len,int d)
{   int i=0,j=0; long dev=0;
	while(dev<d&&j<len) 
	{	dev=dev*10; dev+=(*(m+j))-48; j++; }
	do
	{ 
		while(dev<d&&j<len)
		{	dev=dev*10; 
			dev+=(*(m+j))-48; j++;
			//if(dev<11&&j<len) 
			//	*(r+i++)=48;
		} 
		//*(r+i++)=dev/11+48; 
		dev%=d;
	}while(j<len); 
	//*(r+i)=0;  
	if(dev)	return 0;
	return 1;
}
void main()
{
	char yr[R], lp,hl,bl,  q=0;
	int len;
//freopen("in.txt","r",stdin);
	while(gets(yr))
	{	
		if(q) putchar(10); q=1;
		
		lp=0, hl=0, bl=0;
		len=strlen(yr);
				
		if( (sn_dev(yr,len,4)&&sn_dev(yr,len,100)==0)||sn_dev(yr,len,400))
		{	lp=1;
			if(sn_dev(yr,len,55)) bl=1;
		}
		hl=sn_dev(yr,len,15);
		
		
		if(lp) puts("This is leap year.");
		if(hl) puts("This is huluculu festival year.");
		if(bl) puts("This is bulukulu festival year.");

		if(lp==0&&hl==0&&bl==0) puts("This is an ordinary year.");
	}
}