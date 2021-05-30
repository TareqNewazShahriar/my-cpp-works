#include<stdio.h>
#include<string.h>
//#include<conio.h>
#define INDEX 31
void main()
{
	char *alpha="22233344455566677778889999", ins[INDEX];
	int i,len;
//freopen("in.txt","r",stdin);
	while(gets(ins))
	{
		//len=strlen(alpha);
		len=strlen(ins);
		for(i=0;i<len;i++)	
		{	if(ins[i]<58)
				putchar(ins[i]);	//: ; < =>?@A
			else
				putchar(alpha[ins[i]-65]);
		}
		putchar(10);	// "\n"
	}
}
