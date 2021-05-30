#include<stdio.h>
#include<string.h>
#include<math.h>
#define SIZE 1000
typedef __int64 TYPe;
#define TYPE unsigned __int64
//18446744073709551615 
/****************************Global Variables***************************/
/*************************User Defined Functions************************/

/*---------------Decimal to Banary( des str, decimal num)--------------*/
int dec_bin(char *bin,TYPE dec)
{	
	int i, k=0;	
	*bin=48; *bin=0;
	for(i=0;dec;i++)
	{
		*(bin+i)=dec%2+48;
		dec/=2;	
		//if(*(bin+i)==1) k++; //How many one's;
	}
	*(bin+i)=0;
	return i;
}
/*---Convert Binary to Decimal(binary_str, decimal_num_destination)---*/
void bin_decimal(char *bin,TYPE &dec)
{	
	int i,len_val=strlen(bin)-1;
	for(i=0,dec=0;len_val>-1;len_val--,i++)
	{
		//for(j=i-1,res=2; j>0; res*=2,j--);//power; alternate of pow()
		//dec+=(bin[len_val]-48)*pow(2,i);
	}
}
/*****************************main Function*****************************/
void main()
	{
	freopen("10176.txt","r",stdin);
	char ch,bin[SIZE];
	TYPE dec;

	dec=dec_bin(bin,18446744073709551615);
	while(scanf("%[01]%c",bin,&ch)!=EOF)
		{
		while(ch!='#')
			scanf("%[01]%c",bin,&ch);
		
		dec_bin(bin,dec);
		}
	}