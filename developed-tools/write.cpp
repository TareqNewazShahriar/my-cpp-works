#include<stdio.h>

#define BEG 1
#define END 466

/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*****************************main Function*****************************/
void main()
	{
	freopen("D:\\Programming\\Problems Coding\\Contest\\2006.09.23 ACM ICPC-NSU\\b.txt","w",stdout);
	
	int i;	

	printf("%d\n",END-BEG+1);
	for(i=BEG;i<=END;i++)
		printf("%d\n",i);
	printf("\n");
	}