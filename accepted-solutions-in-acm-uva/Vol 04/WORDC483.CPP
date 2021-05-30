#include<stdio.h>
#include<string.h>
void main()
{	int len; char wrd[100],ch,c,q=0;
//freopen("input.txt","r",stdin);
	while(scanf("%s%c",wrd,&ch)!=EOF)
	{    if(q==1) printf("%c",c);  q=1;
		len=strlen(wrd)-1; //rev(wrd,len);
		for(;len>-1;len--) printf("%c",wrd[len]);
		c=ch;
}	}//m