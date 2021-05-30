/****************/
#include <stdio.h>
void main()
{// main
	char ch, al;
	int lp, lp2, k, c[26], v, cs;
//freopen("input.txt","r",stdin);
	scanf("%d",&cs);
	for(lp=0;lp<26;lp++)
		c[lp]=0;
	do
	{//d
		do
		{//d
		scanf("%c",&ch);
		if( (ch>64) && (ch<91) )
		{//1i
			v=ch-65;
			c[v]++;
		}//1i
		else if( (ch>96) && (ch<123) )
		{//1i
			v=ch-97;
			c[v]++;
		}//1i
		} while( (ch!='\n') || (ch==EOF) );
		cs--;
	} while(cs>=0);

	for(lp=0;lp<26;lp++)
	{//1 for s
		if(c[lp]!=0)
		{// 3 if s
			al=lp;
			v=c[lp];
			for(lp2=lp+1;lp2<26;lp2++)
			{//2 for s
				if(c[lp2]!=0)
				{// if s
					if ( v < (c[lp2]) )
					{// 2 if s
						al=lp2;
						v=c[lp2];
					}// 2 if e
				}// if e
			}//2 for e
			printf("%c %d\n",(al+65),v);
			c[al]=0;
			lp=-1;
		}// 3 if e
	}//1 for e

}//m