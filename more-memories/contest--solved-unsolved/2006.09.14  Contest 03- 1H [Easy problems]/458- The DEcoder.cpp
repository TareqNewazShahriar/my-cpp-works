#include<stdio.h>
#define R 1000
/*---------------------------Global Variables--------------------------*/
/*--------------------------Function Prototypes------------------------*/
/*----------------------------main Function----------------------------*/
void main()
{
	char str[R];
	int i;

	while(gets(str))
	{
		for(i=0;str[i];i++) str[i]-=7;
		puts(str);
	}
}