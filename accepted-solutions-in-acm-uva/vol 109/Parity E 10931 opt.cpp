#include<stdio.h>
#define index 40

void main()
{	char bin[index];
	long dec;  int i,one;
//freopen("contest.txt","r",stdin);
	scanf("%ld",&dec);
	while(dec)
	{	if(dec==0) break;
		*(bin+39)=0;
		for(i=38,one=0;dec;i--)
		{
			*(bin+i)=dec%2+48; dec/=2;
			if(*(bin+i)==49) one++;
			//bin[i]=dec%2+48; dec/=2;
			//if(bin[i]==49) one++;

			//one+=bin[i]-48;
		}
		printf("The parity of %s is %d (mod 2).\n",&bin[i+1],one);
		scanf("%ld",&dec);
}	}			