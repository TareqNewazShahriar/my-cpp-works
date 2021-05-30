#include<stdio.h>

/*************************User Defined Functions************************/
ackermann(int m,int n)
	{
	if(m==0) return n+1;
	else if(n==0) return ackermann(m-1,1);
	return ackermann(m-1,ackermann(m,n-1));
	}
/*****************************main Function*****************************/
void main()
	{
	int m,n;
	puts("\
\t Ackermann Function\n\
\tﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ\n");
	while( printf("Enter two values :"),scanf("%d%d",&m,&n)!=EOF )
		{
		printf("Ans :: %d\n",ackermann(m,n));
		}
	}