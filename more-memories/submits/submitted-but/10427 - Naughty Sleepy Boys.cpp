#include<stdio.h>

void main()
{
//freopen("F:\\Programming\\Problems Coding\\pACM Problems Coding\\in08.txt","r",stdin);
	char num[15];
	long n,i,m,div,mod,
	digit[]={0,10,190,2890,38890,488890,5888890,68888890,788888890, 1000000001},//8888888890
	fol[]={0,0,10,100,1000,10000,100000,1000000,10000000,100000000};
	while(scanf("%ld",&n)==1)
	{
		for(i=1;n>=digit[i];i++);
		
		m=n-digit[i-1];
		div=fol[i]+(m/i); mod=m%i;
		i=-1;
		do
		{	num[++i]=div%10; div/=10;
		}while(div);

		printf("%d\n",num[i-mod]);
	}
}