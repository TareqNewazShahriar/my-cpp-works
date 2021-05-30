// INCOMPLETE
#include<stdio.h>
#define SIZE 1000
/****************************Global Variables***************************/
int i,l=0,a=SIZE,start=0,info[SIZE],link[SIZE],avail=1;
/*************************User Defined Functions************************/
void insert() // INCOMPLETE
	{
	if(a==0) puts("Overflow");
	else
		{
		int loc,data;
		printf("Enter the Position and Value :");
		scanf("%d%d",&loc,&data);

		if(loc==0)
			{
			start=avail; link[start]=0;
			info[start]=data; avail=link[avail];
			}
		else if(link[loc]==0)
			{

			}
		}
	}
/*****************************main Function*****************************/
void main()
	{
	int choice;
	
	puts("\tLinked List");
	puts("\t___________");
	puts("Type any Menu number:-");
	puts("Menu::");
	puts("  1. Insert");
	puts("  2. Delete");
	puts("  3. Traverse the List");
	puts("  4. Used / Available");
	puts("  0. Quit");
	
	for(i=1;i<SIZE;link[i]=i+1,i++); // creating available list
	link[SIZE-1]=0;

	scanf("%d",&choice);
	while(choice)
		{
		if(choice==1) insert();
		else if(choice==2) del();
		else if(choice==3) traverse();
		else if(choice==4) status();

		scanf("%d",&choice);
		}
	}