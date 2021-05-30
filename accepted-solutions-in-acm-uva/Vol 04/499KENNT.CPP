/****************/
#include <stdio.h>
void main()
{// main
	char ch, tmp='0', m;
	int lp, c[52], v, min, max, k;
//freopen("input.txt","r",stdin);
	while(scanf("%c",&ch)!=EOF)
	{// w
		if ( (tmp=='0') || (tmp=='\n') )
		{//i
			m='n';
			for(lp=0;lp<52;lp++)
				c[lp]=0;
		}//i
		if (ch!= '\n')
		{//0i
			if( (ch>64) && (ch<91) )
			{//1i
				m='y';
				v=ch-65;
				c[v]++;
			}//1i
			else if( (ch>96) && (ch<123) )
			{//1i
				m='y';
				v=ch-71;
				c[v]++;
			}//1i
			if(m=='y')
			{//7i
				if ( (tmp=='0') || (tmp=='\n') )
				{//
					min=v;
					max=v;
				}//
				if(min>v)
					min=v;
				else if (max<v)
					max=v;
			}//7i
		}//0i

		if ( (ch=='\n') && (m=='y') )
		{// 1 if
			v=c[min];
			for(lp=min+1;lp<max;lp++)
			{//0f
				if(v<c[lp])
					v=c[lp];
			}//0f

			for(lp=min;lp<=max;lp++)
			{//5f
				if (c[lp]==v)
				{//
					if(lp<26)
						printf("%c",(lp+65) );
					else
						printf("%c",(lp+71) );
				}//
			}///5f
		  printf(" %d\n",v);
	  }// 1 if
		tmp='1';
		if(ch=='\n')
			tmp='\n';
	}// w

}// main