#include<stdio.h>
void main()
{//m
	char ch, q='0';
	int n;
//freopen("scan.txt","r",stdin);
	while(scanf("%c",&ch)!=EOF)
	{//w
		if( ((ch=='!') || (ch=='\n')) && (q!='2') )
		{//1i
			printf("\n");
			q++;
		}//1i
		else
		{//1e
			n=0;
			while( (ch>48) && (ch<58) )
			{//2w
				n+=ch-48;
				scanf("%c",&ch);
			}//2w
			for(;n>0;n--)
				if(ch=='b')
				{//1i
					q='0';
					printf("%c",' ');
				}//1i
				else if( ((ch>64) && (ch<91)) || (ch=='*') )
				{//ei
					printf("%c",ch);
					q='0';
				}//ei

		}//1e
	}//w
	//printf("\n");
}//m