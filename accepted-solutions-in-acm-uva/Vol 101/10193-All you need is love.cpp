#include<stdio.h>
#include<math.h>
#include<string.h>
#define R 31

long gcd(long a,long b);
void bin_decimal(char *bin, long &dec,char *bin2, long &dec2);

void main()
{
int N,cs=0;  long dec1,dec2;
char bin1[R],bin2[R];
//freopen("in.txt","r",stdin);
scanf("%d",&N);
while(N)
{
	scanf("%s%s",bin1,bin2);
	bin_decimal(bin1,dec1,bin2,dec2);
	
	if(gcd(dec1,dec2)!=1) printf("Pair #%d: All you need is love!\n",++cs);
	else printf("Pair #%d: Love is not all you need!\n",++cs);
	N--;
}
}
/*-------------Greatest Common Devisor[GCD](num_1,num_2)----------------*/
long gcd(long a,long b)
{	while(b>0) { a%=b; a^=b; b^=a; a^=b; }
	return a;
}
/*-------Convert Binary to Decimal(binary_str, decimal_num_destination)---*/
void bin_decimal(char *bin, long &dec,char *bin2, long &dec2)
{	int i,len_val=strlen(bin)-1;
	//char ten[R];
	for(i=0,dec=0;len_val>-1;len_val--,i++)
	{
		//for(j=i-1,res=2; j>0; res*=2,j--);//power
		dec+=(bin[len_val]-48)*pow(2,i);
	}
	len_val=strlen(bin2)-1;
	for(i=0,dec2=0;len_val>-1;len_val--,i++)
	{
		dec2+=(bin2[len_val]-48)*pow(2,i);
	}
}	
