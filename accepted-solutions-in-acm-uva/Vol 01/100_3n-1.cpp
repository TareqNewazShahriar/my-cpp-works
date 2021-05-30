#include<stdio.h>
void main()
{//m
	int len, cy;
	char q;
	unsigned long n1, n2, i, n;
	//freopen("input.txt","r",stdin);
	while(scanf("%ld%ld",&n1,&n2)!=EOF)
	{
		len=1;
		q='n';
		if(n2<n1)
		{
			q='y';
			i=n1;
			n1=n2;
			n2=i;
		}//1i
		for(i=n2; i>=n1; i--)
		{
			cy=1;
			n=i;
			while(n!=1)
			{
				if(n%2==0)
				{
					cy++;
					n=n/2;
				}
				else
				{
					cy++;
					n=(3*n)+1;
				}
			}//w
			if(len<cy)
			    len=cy;
		}//f
		if(q=='n')
			printf("%ld %ld %d\n",n1,n2,len);
		else
			printf("%ld %ld %d\n",n2,n1,len);
	}//w
}//m