#include<stdio.h>
#define R 11
/*---------------------------Global Variables--------------------------*/
char digit[R][R][R]={{" - ","| |","   ","| |"," - "}, {"   ","  |","   ","  |","   "},
		{" - ","  |"," - ","|  "," - "}, {" - ","  |"," - ","  |"," - "}, {"   ","| |"," - ","  |","   "},
		{" - ","|  "," - ","  |"," - "}, {" - ","|  "," - ","| |"," - "}, {" - ","  |","   ","  |","   "},
		{" - ","| |"," - ","| |"," - "}, {" - ","| |"," - ","  |"," - "}},
		nums[R],spc[]="                                                                                                              ";
int font,len;
/*--------------------------Function Prototypes------------------------*/
void print_();
void horizontal(int d);
/*----------------------------main Function----------------------------*/
void main()
{
//freopen("706.txt","r",stdin);
	scanf("%d%s",&font,nums);

	while(font!=0||nums[0]!='0'||nums[1]!=0)
	{
		spc[font]=0;
		for(len=0;nums[len];len++) nums[len]-=48;

		print_();
		printf("\n");
		
		spc[font]=' ';

		scanf("%d%s",&font,nums);
	}

}
void print_()
{
	int i,j,k;
	char ch;
	
	for(j=0;j<5;j++)
	{
		if(j==1||j==3) horizontal(j);
		else
		{
			for(k=0;k<len-1;k++)
			{
				putchar(digit[nums[k]][j][0]);
				ch=digit[nums[k]][j][1];
				if(ch==' ') 
					printf("%s",spc);
				else  for(i=0;i<font;i++) putchar(ch);
				putchar(digit[nums[k]][j][2]);

				putchar(' ');
			}
			putchar(digit[nums[k]][j][0]);
			ch=digit[nums[k]][j][1];
			if(ch==' ') 
				printf("%s",spc);
			else  for(i=0;i<font;i++) putchar(ch);
			putchar(digit[nums[k]][j][2]);

			putchar(10);
		}
		//if(j==4) getch();
	}
}
void horizontal(int d)
{
	int i,j,k;
	char ch;

	for(j=0;j<font;j++)
	{
		for(k=0;k<len-1;k++)
		{
			putchar(digit[nums[k]][d][0]);
			ch=digit[nums[k]][d][1];
			if(ch==' ') 
				printf("%s",spc);
			else  for(i=0;i<font;i++) putchar(ch);
			putchar(digit[nums[k]][d][2]);

			putchar(' ');
		}
		putchar(digit[nums[k]][d][0]);
		ch=digit[nums[k]][d][1];
		if(ch==' ') 
			printf("%s",spc);
		else  for(i=0;i<font;i++) putchar(ch);
		putchar(digit[nums[k]][d][2]);

		putchar(10);
	}
}