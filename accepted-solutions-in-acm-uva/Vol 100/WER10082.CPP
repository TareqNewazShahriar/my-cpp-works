#include<stdio.h>
#include<string.h>
void main()
{	char ch,q, n[4][15]; int i,j;
	strcpy(n[0],"`1234567890-=\\"); strcpy(n[1],"QWERTYUIOP[]");
	strcpy(n[2],"ASDFGHJKL;'"); strcpy(n[3],"ZXCVBNM,./");
//freopen("input.txt","r",stdin);
	while(scanf("%c",&ch)!=EOF)
	{	if(ch==32) printf(" ");
		else if(ch!='\n')
		{	for(i=0,q=0;i<4&&q==0;i++)
			{    if(i==0) j=13; else if(i==1) j=11;
				else if(i==2) j=10; else j=9;
				for(;j>-1;j--)
					if(ch==n[i][j])
						{ printf("%c",n[i][j-1]); q=1; break; }
			}
		}
		else printf("\n");
	}
}//m