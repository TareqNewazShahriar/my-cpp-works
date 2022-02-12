#include<stdio.h>
#include<math.h>
#define R 1000000

void sto_prim(unsigned long n);
void seive_prim(unsigned long n);

void main()
{
	int choice;  unsigned long element;
	char path[100];
	printf("\t\tPrime Generating Program\n\t\t________________________\
\n\tPrimes Will be written in \"F:\\Pimes.out\"\n\
1. Write primes\n2. Seive prime in char array(prime=0,non-prime=1)\n\
3. Both\nSelect your choice(1,2,3): ");
	scanf("%d",&choice);
	printf("Last number: "); scanf("%lu",&element);  gets(path);

	freopen("D:\\Pimes.out","w",stdout);
	//printf("Writing file path: "); gets(path);
	//freopen(path,"a",stdout);
	if(choice==1||choice==3) sto_prim(element);
	if(choice==2||choice==3) seive_prim(element);
}

/*---------------Load Primes in a array(*ar,untill_num)-----------------*/
/*----------If out of n then i<n, else if up to n then s<n-----------*/
void sto_prim(unsigned long n)
{	
	unsigned long s,sq, i,j, p[R], brk=0; char q;
	printf("primes[]={2,3");
	n++; *p=2; *(p+1)=3;  s=2;
	for(i=5;i<n;i+=2)
	{	q=1;
		sq=sqrt(i)+1;
		for(j=1;*(p+j)<sq;j++)
		{    if(i% *(p+j)==0) { q=0; break; }
		} 
		if(q) 
		{	*(p+s++)=i; printf(",%lu",i);
			brk++; if(brk==150) {  putchar(10); brk=0; }
		}
		
	}
	printf("};\n//total %lu\n",s);
}
/*----Load Primes in a array untill index n by Sieve Algorithm(array_name, untill_n)----*/
//------------- prime=0, non-prime=1 --------------
void seive_prim(unsigned long n)
{	
	unsigned long i,j,brk=0,tot=0;	bool prim[R]={1,1};
	n++;
	for(i=4;i<n;prim[i]=1,i+=2);
	for(i=3;i<n;i+=2)
	{	if(*(prim+i)==0)
			for(j=i+i;j<n;*(prim+j)=1,j+=i);
	}
	printf("bool prm[]={1");
	for(i=1;i<n;i++)
	{	
		brk++;
		if(prim[i]==0) tot++;
		printf(" %d",prim[i]);
		if(brk==150) {  putchar(10); brk=0; }
	}
	printf("};\n//total prime %lu\n",tot);
}