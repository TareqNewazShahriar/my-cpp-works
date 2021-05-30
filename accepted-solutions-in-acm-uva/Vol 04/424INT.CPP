#include<stdio.h>
#include<string.h>
/*----Reverse and copy to destination simultaneously(des_str,str,len)----*/
void revcop(char *des,char *s,int len)
{    int i=0,j=len-1; *(des+len)='\0';
	for(len=len/2+1;i<len;i++,j--) { *(des+i)=*(s+j); *(des+j)=*(s+i); }}
/*-----------------------Reverse(sre,len)---------------------*/
void rev(char *s,int j)
{    int i=0;  char tmp;
	for(j--;i<j;i++,j--) { tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }}
/*----------Addition of 2 string(des str,str1,str2,len1,len2)------------*/
int ss_add(char *r,char *u,char *v,int len,int i)//<Require revcop & rev>
{    char m[110],n[110], sum;
	revcop(&m[0],u,len); revcop(&n[0],v,i);
	if(len>i) for(;i<len;i++) n[i]=48;
	else if(len<i) for(;len<i;len++) m[len]=48;
	for(sum=0,i=0;i<len;i++)
	{	sum+=(m[i]+n[i]);
		if (sum>105) {	*(r+i)=sum-58; sum=1; }
		else  { *(r+i)=sum-48; sum=0; }
	}if(sum==1) { *(r+i)=49; *(r+(++i))=0; }
	 else  *(r+i)=0; rev(r,i); return i;  }
void main()
{//m
char a[103],b[101],c[103]; int lena,lenb;
//freopen("input.txt","r",stdin);
//freopen("out.txt","w",stdout);
	gets(a);
	lena=strlen(a);
	while(scanf("%s",b)!=EOF)
	{	if(strcmp(b,"0")==0) break;
		lenb=strlen(b);
		lena=ss_add(&c[0],&a[0],&b[0],lena,lenb);
		strcpy(a,c);
	}
	printf("%s\n",c);
}//m