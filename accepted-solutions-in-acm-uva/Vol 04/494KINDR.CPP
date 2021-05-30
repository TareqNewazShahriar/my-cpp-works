#include<stdio.h>
void main()
{//m
	int n=0, c;
	char ch, q='y';
//freopen("input.txt","r",stdin);
	while(scanf("%c",&ch)!=EOF)
	{//1w
		c=ch;
		if( (q=='y') && ( ((ch>64) && (ch<91)) || ((ch>96) && (ch<123)) ) )
		{//1i
			n++;
			q='n';
		}//1i
		else if( ((ch>90) || (ch<65)) && ((ch>122) || (ch<97)) && (ch!='\n') )
			q='y';
		else if(ch=='\n')
		{//1ei
			printf("%d\n",n);
			n=0;
			q='y';
		}//1ei

	}//1w
}//m