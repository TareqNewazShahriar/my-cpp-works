#include<stdio.h>
#include<conio.h>
/*-------------------Global Variables------------------*/
/*-----------------Functions Prototypes----------------*/
/*--------------------main Function--------------------*/
void main()
{
	freopen("ASCII.txt","w",stdout);
	clrscr();
	int i;
	for(i=0;i<256;i++)
	{
		printf("%d=[%c] ",i,i);
	}
}