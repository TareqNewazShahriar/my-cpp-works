#include<stdio.h>
#include<string.h>
#define INDEX 1001

int digit_sum(char *str)
{	int i,sum=0,count=0;
	do
	{	count++;
		for(i=0;sum;i++)
		{	*(str+i)=sum%10+48;
			sum/=10;		
		}
		if(i) *(str+i)=0;
		for(i=1,sum=*str-48;*(str+i);i++) 
		{	sum+= *(str+i)-48; }
	}while(sum>9);
	if(sum==9) return count;
	return 0;
}
void main()
{
	int degree;
	char str[INDEX];
//freopen("in.txt","r",stdin);
	while(gets(str))
	{	if(str[0]==48&&str[1]==0) break;
		fputs(str,stdout);
		//len=strlen(str);
		degree=digit_sum(str);
		if(degree) printf(" is a multiple of 9 and has 9-degree %d.\n",degree);
		else puts(" is not a multiple of 9.");
	}
}				