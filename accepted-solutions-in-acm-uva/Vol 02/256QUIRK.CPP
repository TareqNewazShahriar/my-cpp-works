#include<stdio.h>
#include<math.h>
void main()
{	long sq, d;
	int b[8],n,i,x,j,a,c;
	while(scanf("%ld",&x)!=EOF)
	{	n=0;
		for(i=x/2;i<x;i++)  n=n*10+9;
		for(j=0;j<=n;j++)
		{	sq=pow(j,2);
			d=sq;  i=x;
			do
			{  b[--i]=d%10;  d=d/10;  }while(i>0);
			a=b[0];  c=b[x/2];  x=x/2-1;
			for(i=0;i<x;i++)  a=a*10+b[i+1];
			for(x++,i=x,x=x*2-1;i<x;i++)  c=c*10+b[i+1];
			x++;
			if( sq==pow((a+c),2) )
			{	for(i=0;i<x;i++)  printf("%d",b[i]);
				printf("\n");
			}//4i
		}//1f
	}//1w
}//m