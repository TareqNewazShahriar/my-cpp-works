#include<stdio.h>
#define R 10
/*---------------------------Global Variables--------------------------
/*--------------------------Function Prototypes------------------------*/
void save_hridoy(int n);
void _save_hridoy(int n);
/*----------------------------main Function----------------------------*/
void main()
{
//freopen("my.txt","w",stdout);
	int n;

	scanf("%d",&n);
	while(n)
	{
		if(n>0) save_hridoy(n);
		else
		{
			n=-n;
			_save_hridoy(n);
		}
		puts("\n");

		scanf("%d",&n);
	}
}
void _save_hridoy(int n)
{
int i,j;
//S
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("....");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("....");
	for(i=0;i<n;i++) printf("*");	
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".....");
	putchar(10);
}
//A
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("***");
	for(i=0;i<n;i++) printf(".");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".....");
	putchar(10);
}
// V
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".....");
	putchar(10);
}
// E
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("....");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("***");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("....");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
// Space
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".....");
	putchar(10);
	for(i=0;i<n;i++) printf(".....");
	putchar(10);
	for(i=0;i<n;i++) printf(".....");
	putchar(10);
}
// H
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".....");
	putchar(10);
}
// R
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("**");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".....");
	putchar(10);
}
// I
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".....");
	putchar(10);
}
// D
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("***");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("***");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".....");
	putchar(10);
}
// O
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".....");
	putchar(10);
}
// Y
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
}//end
void save_hridoy(int n)
{
	int i,j;
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("***");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("***");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".....");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".......");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("***");
	for(i=0;i<n;i++) printf(".....");
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("....");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".......");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".....");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	for(i=0;i<n;i++) printf("**");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf(".");
	for(i=0;i<n;i++) printf("***");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*****");
	for(i=0;i<n;i++) printf("...");
	for(i=0;i<n;i++) printf("*");
	for(i=0;i<n;i++) printf("..");
	putchar(10);
}
}//
