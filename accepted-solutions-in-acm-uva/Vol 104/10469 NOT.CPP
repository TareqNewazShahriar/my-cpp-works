#include<stdio.h>
void main()
{//m
	unsigned long int a, b;
	while(scanf("%lu%lu",&a,&b)!=EOF)
	{//w
		printf("%lu\n",(a^b));
	}//w
}//m