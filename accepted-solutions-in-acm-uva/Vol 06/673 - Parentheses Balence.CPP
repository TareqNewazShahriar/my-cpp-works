]#include<stdio.h>
#include<string.h>
void main()
{	int cs,k,len,i; char par[300],cmp[258],que;
//freopen("input.txt","r",stdin);
	scanf("%d%c",&cs);
	for(;cs>0;cs--)
	{	gets(par); len=strlen(par); que=0; cmp[0]=0;
		for(i=0;i<259;i++) cmp[i]=0;
		for(k=1,i=0;i<len;i++)
		{   
			if(par[i]=='(') cmp[k++]='(';
			else if(par[i]=='[') cmp[k++]='[';
			else if(par[i]==')'&&cmp[k-1]=='(') k--;
			else if(par[i]==']'&&cmp[k-1]=='[') k--;
			else { que=1; break; }
		}
		if(que==0&&k==1) printf("Yes\n"); else printf("No\n");
}	}//m