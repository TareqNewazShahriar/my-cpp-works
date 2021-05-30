#include<stdio.h>
#include<math.h>
/******************Decimal to Banary( des str, decimal num)*****************/
int dec_bin(long dec)
{	int k=0;	
	while(dec)
	{
		if(dec%2==1) k++; //How many one's;
		dec/=2;	
	}
	return k;
}
/**Convert the val from 16 to 2.***/
int base_conv(int val)
{	int i,digi;
	for(i=0,digi=0;val;i++)
	{
		digi+= (val%10)*pow(16,i);
		val/=10;
	}
	i=0;
	while(digi)
	{
		if(digi%2==1) i++;
		digi/=2;
	}
	return i;
}

void main()
{
int csn, n;//   char bin[R];
scanf("%d",&csn);
while(csn)
{	csn--;
	scanf("%d",&n);
	
	printf("%d ",dec_bin(n));
	
	printf("%d\n",base_conv(n));
}
}
