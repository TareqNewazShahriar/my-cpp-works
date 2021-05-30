#include<stdio.h>
#include<string.h>
#define SIZE 10000
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*****************************main Function*****************************/
void main()
	{
	freopen("C:\\Program Files\\Microsoft Visual Studio\\VC98\\Include\\BigInteger.h","r",stdin);
	freopen("BigInegert.h","w",stdout);

	char str[SIZE]="";
	while(scanf("%[ \t]%[//*]",str,str)!=EOF)
		{
		if(strcmp(str,"//")==0)
			gets(str);
		else if(strstr(str,"/*"))
			{
			do
				{
				gets(str);
				}while(strstr(str,"*/")==0);
			
			}
		else 
			{
			printf("%s",str);
			gets(str);
			puts(str);
			}
		/*
		if(strstr(str,"temp.Multiply(2);"))
			int a=0;
		//*/
		*str=0;
		}
	}