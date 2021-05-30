#include<stdio.h>
#include<math.h>
#define R 1000
/*--------Lowest Common Multiple [LCM] (num1,num2)-//require gcd()---------*/
long lcm(long x,long y)
{    long a=x,b=y;
	while(b>0) { a%=b; a^=b; b^=a; a^=b; }
	return (x/a)*y;  }
void main()//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
{	long n,sq, lft[R], i, x,a,b;
//freopen();
	while(scanf("%ld",&n)!=EOF)
	{   
		if(n==0) break;
		for(sq=sqrt(n)+1,i=2,x=-1;i<sq;i++)
		{
			if(n%i==0)  {	lft[++x]=i; lft[++x]=n/i;  }
		}
		if(x>0&&lft[x]==lft[x-1]) x--;

		for(i=x+3;x>-1;x--)
			for(sq=x-1;sq>-1;sq--)
			{    a=lft[x],b=lft[sq];
				while(b>0) { a%=b; a^=b; b^=a; a^=b; }

				if( ((lft[x]/a)*lft[sq])==n) i++;
			}
		if(n==1) i--;
		printf("%ld %ld\n",n,i);
}	}//m