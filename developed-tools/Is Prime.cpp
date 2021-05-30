#include<stdio.h>
#include<math.h>
/*---------------Load Primes in a array(*ar,untill_num)-----------------*/
/*----If out of n number then i<n, else if up to n prime then s<n------*/
unsigned long is_prime(unsigned long p)
{	unsigned long sq, j;
	
	sq=sqrt(p)+1;
	for(j=2;j<sq;j++)
	{
		if(p%j==0) return 0;
	}
	//if(q=='0') *(p+s++)=i;
	return 1;
}
void main()
{
unsigned long p,q,i;
while(scanf("%lu%lu",&p,&q)!=EOF)
{
	if(p<q) p^=q; q^=p; p^=q;
	for(i=0 ;q<=p;q++)
	{
		if(is_prime(q)) i++, printf("%lu\t",q);
		
	}
	printf("\n%lu.\n",i);
}
}