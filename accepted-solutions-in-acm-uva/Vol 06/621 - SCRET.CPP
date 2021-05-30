#include<stdio.h>
#include<string.h>
void main()
{	int cs, len;	char s[500],q=1;
//freopen("input.txt","r",stdin);
	scanf("%d",&cs);
	for(;cs>0;cs--)
	{	scanf("%s",s);
		len=strlen(s)-1;
		if(q==0) printf("\n"); q=0;
		if(len>0)
		{	if(s[len-1]=='3'&&s[len]=='5')  printf("-");
			else if(s[0]=='9'&&s[len]=='4') printf("*");
			else if(s[0]=='1'&&s[1]=='9'&&s[2]=='0') printf("?");
			else	printf("+");
		}
		else printf("+");
	}
}//m