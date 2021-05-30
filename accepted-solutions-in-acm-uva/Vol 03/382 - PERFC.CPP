#include<stdio.h>
void main()
{//m
	 long n, sum, i;
	 int len;
//freopen("input.txt","r",stdin);
	 printf("PERFECTION OUTPUT\n");
	 while(scanf("%ld",&n)!=EOF)
	 {//w
		if(n!=0)
		{	len=1; sum=0;
			for(i=n/2;i>0;i--)
			{//1f
				if(n%i==0)  sum+=i;
				if(sum>n)  break;
				if(i==(n/2))
					{ i=(n/3)+1;  continue;	}
			}//1f
			i=n;
			do
			{//d
				i=i/10;
				if(i>0)  len++;
			}while(i!=0);
			for(i=5-len;i>0;i--)  printf(" ");

			if(sum<n)  printf("%ld  DEFICIENT\n",n);
			else if(sum==n)  printf("%ld  PERFECT\n",n);
			else  printf("%ld  ABUNDANT\n",n);
		}//1i
	 }//w
	 printf("END OF OUTPUT\n");
}//m