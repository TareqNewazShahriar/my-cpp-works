#include<stdio.h>
#include<string.h>
#define R 5000
/*--------------------------Finding Zero(str)--------------------*/
int zero(char *s)
{	int i;
	for(i=0; *(s+i)==48; i++);
	//if(i>0) {strcpy(s,s+i);}
	return i;
}
/*----------Addition of 2 strings(des str,str1,str2,len1,len2)------------*/
void ss_add(char r[],char m[],char n[],int len,int i)//<Require revcop & rev>
{    char sum;
	//revcop(m,u,len); revcop(n,v,i);
	if(len>i) for(;i<len;i++) n[i]=48;
	else if(len<i) for(;len<i;len++) m[len]=48;
	for(sum=0,i=0;i<len;i++)
	{	sum+=(m[i]+n[i]);
		if (sum>105) {	*(r+i)=sum-58; sum=1; }
		else  { *(r+i)=sum-48; sum=0; }
	}
	if(sum==1) *(r+i++)=49;
	*(r+i)=0; //rev(r,i);
	
}
/**************************************************************/
void main()
{
	int i,cs; //len1,len2;
	char m[R],n[R];
	scanf("%d",&cs);
	for(;cs>0;cs--)
	{	scanf("%s%s",m,n);
		ss_add(m,m,n, strlen(m),strlen(n));
		//rev();
		for(i=0;m[i]==48;i++);
		printf("%s\n",m+i);
	}
}