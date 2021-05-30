#include <stdio.h>
#include <string.h>
#define L 11
void revcop(char *des,char *s,int len)
{    int i=0,j=len-1;
	*(des+len)='\0';
	for(len=len/2+1;i<len;i++,j--) { *(des+i)=*(s+j); *(des+j)=*(s+i); }}
int ss_add(char *u,char *v,int len,int i)//*<Required revcop function>*/
{    char m[L],n[L], sum; int x=0;
	revcop(&m[0],u,len); revcop(&n[0],v,i);
	if(len>i) for (;i<len;i++)  n[i]=48;
	else if (len<i) for(;len<i;len++)  m[len]=48;
	for(sum=0,i=0;i<len;i++)
	{	sum+=(m[i]+n[i]);
		if (sum>105) {	sum=1; x++; }
		else  sum=0;
	}	return x;	}
//::::::::::::::::::::::MAIN:::::::::::::::::::::
void main()
{    int m,n,w;   char v1[L], v2[L];
//freopen("input.txt","r",stdin);
while(scanf("%s%s",v1,v2)!=EOF)
{	m=strlen(v1);	n=strlen(v2);
	if( v1[0]=='0'&&v2[0]=='0'&&m==1&&n==1) break;
	w=ss_add(&v1[0],&v2[0],m,n);
	if(w>1)  printf("%d carry operations.\n",w);
	else if(w==1)  printf("1 carry operation.\n");
	else  printf("No carry operation.\n");
}}