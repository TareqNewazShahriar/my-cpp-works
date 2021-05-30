#include<stdio.h>
#include<string.h>
/*--------Global Variable---------*/
long power[32];
/*------Load (2^n)-1 in a global array (dest_array)--------*/
void power_of_two(long power[])
{
	unsigned long pow=1;
	for(int i=0;i<31;i++)
	{
		power[i]=(pow*=2)-1;
	}
}
/*--Skew Binary {base 3 & power is (2^n)-1, where n>=1} (inputted_str)--*/
long skew_binary_to_decimal(char *in)
{
	long out=0, i=strlen(in)-1, j=0;
	for(;i>-1;i--)
	{
		out+=(in[i]-48)*power[j++];
	}
	return out;
}
/*---------------Main Function---------------*/
void main()
{
//freopen("in08.txt","r",stdin);
char in[1000];
power_of_two(power);
scanf("%s",in);
while(in[0]!=48)
{
	printf("%ld\n",skew_binary_to_decimal(in));

	scanf("%s",in);
}
}