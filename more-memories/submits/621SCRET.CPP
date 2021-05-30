#include<stdio.h>
#include<string.h>
void main()
{//m
	int cs, l;
	char s[25], q,x;
//freopen("input.txt","r",stdin);
	scanf("%d",&cs);
	for(;cs>0;cs--)
	{//1f
		scanf("%s",s);	scanf("%c",&q);
		l=strlen(s);
		if((s[0]=='1'||s[0]=='4'||(s[0]=='7'&&s[1]=='8'))&&l<3)
			printf("+\n");
		else if(s[l-2]=='3' && s[l-1]=='5')	printf("-\n");
		else if(s[0]=='9' && s[l-1]=='4')	printf("*\n");
		else    printf("?\n");
	}//1f
}//m