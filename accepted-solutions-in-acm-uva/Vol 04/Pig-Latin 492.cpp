#include<stdio.h>
//#include<string.h>
#define T 1000001

void main()
{
long i;
char str[T], q;
//freopen("in4.txt","r",stdin);
while(gets(str))
{
	for(i=0,q=0;str[i];i++)
	{
		if( q && ((str[i]>64&&str[i]<91) || (str[i]>96&&str[i]<123)) )
			putchar(str[i]);
		else
		{	if(q>1) printf("%cay",q);
			else if(q) printf("ay");
			q=0;
			switch(str[i])
			{
				case 97: q=97; break;	
				case 101: q=101; break;
				case 105: q=105; break; 
				case 111: q=111; break;
				case 117: q=117; break;	
				case 65: q=65; break;
				case 69: q=69; break;
				case 73: q=73; break;
				case 79: q=79; break;
				case 85: q=85; break;
			}
			if(q==0 && ((str[i]>64&&str[i]<91) || (str[i]>96&&str[i]<123)) )
				q=str[i];
			else 
			{	putchar(str[i]);
				if(q) q=1;
			}			
		}
	}//for
	putchar(10);
}//while
}