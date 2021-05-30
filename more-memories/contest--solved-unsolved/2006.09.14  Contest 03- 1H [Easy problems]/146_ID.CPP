#include<stdio.h>
#include<string.h>
#include<algorithm>
//mk:@MSITStore:C:\Program%20Files\Microsoft%20Visual%20Studio\MSDN\2001JAN\1033\vclang.chm::/html/ALGORITH.HTM

using namespace std;
/*--------------------main Function--------------------*/
void main()
{
//freopen("146-ID-out.txt","w",stdout);
	char c,perm[1000];
	
	//int len=strlen(perm);
	//p=perm+len;
	gets(perm);
	while(perm[0]!='#')
	{
		/*
		for(len--;len>0;len--)
		{
			for(i=len-1;i>=0;i--)
			{
				if(perm[i]<perm[len]) break;
			}
		}
		if(i>=0)
		{   	ch=perm[len];
			for(j=len-1;j>i;j--) perm[j+1]=perm[j];
			perm[i+1]=perm[i]; perm[i]=ch;
			puts(perm);
		}
		*/
		c=next_permutation(perm,perm+strlen(perm));
		if(c) printf("%s\n",perm);
		else puts("No Successor");

		gets(perm);
	}
}