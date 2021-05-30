#include<stdio.h>
void main()
{//m
	char ch, q=0;
	int n;
//freopen("input.txt","r",stdin);
	while(scanf("%c",&ch)!=EOF)
	{//w
		if( ((ch=='!') || (ch=='\n')) && (q!=2) )
			{ q++;  printf("\n"); }
		else
		{//1e
			n=0;
			while( (ch>48) && (ch<58) )
				{ n+=ch-48; scanf("%c",&ch); }
			for(;n>0;n--)
				if(ch=='b')
					{ q=0; printf("%c",' '); }
				else if( ((ch>64) && (ch<91)) || (ch=='*') )
					{ q=0; printf("%c",ch); }
		}//1e
	}//w
	//printf("\n");
}//m