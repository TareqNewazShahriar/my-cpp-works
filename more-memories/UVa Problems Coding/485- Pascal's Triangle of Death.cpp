#include<stdio.h>
#define ROW 15500
#define COL 63
typedef __int64 Type;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*----Reverse and copy to destination simultaneously(des_str,str,len)----*/
void revcop(char *des,char *s,int j)
{   
	int i=0;	
	*(des+j)='\0';
	for(j--;i<j;i++,j--)
	{	*(des+i)=*(s+j); *(des+j)=*(s+i); }
	if(i==j) *(des+i)=*(s+i);	
}
/*-----------------------Reverse(str,len)---------------------*/
void rev(char *s,int j)
{   
	int i=0;  
	char tmp;
	for(j--;i<j;i++,j--)
	{	tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }
}
/*----------Addition of 2 strings(des str,str1,str2,len1,len2)------------*/
void ss_add(char *r,char *u,char *v,int len,int i)//<Require revcop & rev>
{   
	char m[COL],n[COL], sum;
	revcop(&m[0],u,len); revcop(&n[0],v,i);
	
	if(len>i) for(;i<len;i++) n[i]=48;
	else if(len<i) for(;len<i;len++) m[len]=48;
	
	for(sum=0,i=0;i<len;i++)
	{	
		sum+=(m[i]+n[i]);
		if (sum>105) {	*(r+i)=sum-58; sum=1; }
		else  { *(r+i)=sum-48; sum=0; }
	}
	if(sum==1) { *(r+i)=49; *(r+(++i))=0; }
	else  *(r+i)=0; 	rev(r,i);
}
/*****************************main Function*****************************/
void main()
	{
	char A[ROW][COL], B[ROW][COL]={"2"};
	Type i, tot=1, lenA[ROW],lenB[ROW]={1}, numA=0,numB=1;
	bool q=1;

	puts("1\n1 1");
	while(1)
		{
		tot++;
		putchar('1');
		
		if(q) { len[0]=ss_add(A[0], B[0],"1",lenB[0],1);  }
		else  { len[0]=ss_add(B[0], A[0],"1",lenA[0],1);  }
		
		for(i=0;i<tot;i++)
			{
			if(q)
				{
				ss_add();
				}
			else
				{
				}
			}
		puts(" 1");
		}
	}