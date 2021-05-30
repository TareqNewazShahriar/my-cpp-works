#include<stdio.h>
#include<string.h>
long long multi_all(int k)
{ long long n=1;int i; for(i=2,k++;i<k;i++)  n*=i; return n; }
void main()
{	int cs,k=0,len,i; char s[21],rec[26]; long long n, y;
//freopen("input.txt","r",stdin);
	scanf("%d",&cs); gets(s);
	for(;cs>0;cs--)
	{	gets(s); len=strlen(s); n=1; y=1;
		printf("Data set %d: ",++k);
		for(i=0;i<26;i++) rec[i]=0;
		for(i=0;i<len;i++) (rec[s[i]-65])++;
		for(i=0;i<26;i++)
			if(rec[i]>1) y*=multi_all(rec[i]);
		n=multi_all(len);
		printf("%lld\n",n/y);
}	}//m