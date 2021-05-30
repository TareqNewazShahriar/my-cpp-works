#include<stdio.h>
//#define R 100
/*---------------------------------------------*/
short dec_bin(short dec);
/*---------------------------------------------*/
void main()
{
//freopen("in02.txt","r",stdin);
	int cs,n,i,d,hex; char hexa[]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
	for(scanf("%d",&cs);cs;cs--)
	{
		scanf("%d",&n);
		
		d=dec_bin(n);		
		i=-1; hex=0;
		do
		{	hex+=hexa[n%10];
			n/=10;
		}while(n);
		
		printf("%d %d\n",d,hex);
	}
}
/******************Decimal to Banary( des str, decimal num)*****************/
short dec_bin(short dec)
{	int i, k=0; bool bin=0;
	for(i=0;dec;i++)
	{
		bin=dec%2;
		dec/=2;	
		if(bin) k++; //How many one's;
	}
	return k;
}		