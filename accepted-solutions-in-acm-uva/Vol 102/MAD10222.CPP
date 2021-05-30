#include<stdio.h>
#include<string.h>
void main()
{	char ch,q, n[7][15]; int i,j;
	strcpy(n[0],"`1234567890-=\\"); strcpy(n[1],"qwertyuiop[]");
	strcpy(n[2],"asdfghjkl;'"); strcpy(n[3],"zxcvbnm,./");
	strcpy(n[4],"QWERTYUIOP[]"); strcpy(n[5],"ASDFGHJKL;'");
	strcpy(n[6],"ZXCVBNM,./");
//freopen("input.txt","r",stdin);
	while(scanf("%c",&ch)!=EOF)
	{	if(ch==32) printf(" ");
		else if(ch!='\n')
		{	for(i=0,q=0;i<7&&q==0;i++)
			{    if(i==0) j=13; else if(i==1||i==4) j=11;
				else if(i==2||i==5) j=10; else j=9;
				for(;j>-1;j--)
					if(ch==n[i][j])
					{ if(i>3) i-=3;
					printf("%c",n[i][j-2]); q=1; break; }
			}
		}
		else printf("\n");
	}
}//m