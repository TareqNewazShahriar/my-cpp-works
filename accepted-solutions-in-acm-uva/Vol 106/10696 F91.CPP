#include<stdio.h>
void main()
{// m
	long n;
	do
	{// d
	   scanf("%ld",&n);
	   if(n!=0)
	   {// 0 if
		if (n<102)
			printf("f91(%ld) = %d\n",n,91);
		else
			printf ("f91(%ld) = %ld\n",n,(n-10) );
	   }// if
	} while (n!=0);
}// m
