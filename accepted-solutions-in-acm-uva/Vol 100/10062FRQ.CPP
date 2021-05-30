/****************/
#include <stdio.h>
void main()
{// main
	char ch, al;
	int lp, lp2, k, tmp=0, c[95], v, min, max;
//freopen("input.txt","r",stdin);
	while(scanf("%c",&ch)!=EOF)
	{// w
		if ( (tmp!=0) && (tmp=='\n') )
			printf("\n");

		if ( (tmp==0) || (tmp=='\n') )
			for(lp=0;lp<95;lp++)
				c[lp]=0;

		if ( (ch!= '\n') && (ch!='\r') )
		{//0i
			v=ch-32;
			c[v]++;
			if ( (tmp==0) || (tmp=='\n') )
			{//
				min=v;
				max=v;
			}//
			if(min>v)
				min=v;
			else if (max<v)
				max=v;
		}//0i

	  if (ch=='\n')
	  {// 1 if
	  for(k=0,lp2=min;lp2<=max;lp2++)
		  if(c[lp2]!=0)
			k++;

	  for(;k>0;k/=2)
		for(lp=min;lp<=max;lp++)
		{//1 for s
			if(c[lp]!=0)
			{// 3 if s
				al=lp;
				v=c[lp];
				for(lp2=min;lp2<=max;lp2++)
				{//2 for s
					if(c[lp2]!=0)
					{// if s
						if ( v >= (c[lp2]) )
						{// 2 if s
							al=lp2;
							v=c[lp2];
						}// 2 if e
					}// if e
				}//2 for e
				printf("%d %d\n",(al+32),v);
					c[al]=0;
				if(min==al)
				{//7i
					for(min++;min<=max;min++)
					{//6f
						if(c[min]!=0)
						{//9i
							min--;
							break;
						}//9i
					}//6f
				}//7i
				else if(max==al)
				{//8ei
					for(max--;max>=min;max--)
					{//7f
						if(c[max]!=0)
						{//10i
							max++;
							break;
						}//10i
					}//7f
				}//8ei
			}// 3 if e
		}//1 for e
	  }// 1 if
	  tmp=1;
	  if ( (ch=='\n') || (ch=='\r') )
			tmp='\n';
	}// w

}// main