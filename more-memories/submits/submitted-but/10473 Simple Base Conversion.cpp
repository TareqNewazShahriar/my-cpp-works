#include<stdio.h>
void main()
{
//freopen("F:\\Programming\\Problems Coding\\pACM Problems Coding\\in09.txt","r",stdin);
	long n; char str[50];
	while(1)
	{
		*str=str[1]=0;
		scanf("\n%[0x]",str);
		if(str[1]=='x')
		{	scanf("%lX",&n); printf("%ld\n",n); }
		else if(*str==48)
			puts("0x0");
		else 
		{	
			scanf("%ld",&n);
			if(n==-1) break;
			printf("0x%X\n",n); 
		}

	}
}