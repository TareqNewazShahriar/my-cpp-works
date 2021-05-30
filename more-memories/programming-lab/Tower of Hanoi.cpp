#include<stdio.h>
typedef int Type;
/****************************Global Variables***************************/
Type count;
/*************************User Defined Functions************************/
void tower_of_hanoi(Type n,char beg,char mid,char end)
	{
	if(n==1)
		{
		printf("%-5d# %d: %c -> %c\n",count++,n,beg,end);
		return;
		}
	tower_of_hanoi(n-1,beg,end,mid);

	printf("%-5d# %d: %c -> %c\n",count++,n,beg,end);

	tower_of_hanoi(n-1,mid,beg,end);
	}
/*****************************main Function*****************************/
void main()
	{
	Type n,cs=0;
	while(printf("%d: Tower of Hanoi. Input disc number :",++cs),scanf("%d",&n)!=EOF)
		{
		count=1;
		tower_of_hanoi(n,'A','B','C');
		puts("");
		}
	}