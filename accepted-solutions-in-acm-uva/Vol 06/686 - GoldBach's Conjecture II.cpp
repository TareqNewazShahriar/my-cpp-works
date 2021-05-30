#include<stdio.h>
#include<math.h>
#define R 32768
#define T 3520
void sto_prim(unsigned int *p);
void seive_prim(char *prim);

void main()/*****************************/
{	
unsigned int i,n,m,tot, prm[T]; static char prim[R];
sto_prim(prm);
seive_prim(prim);
//freopen("submit.txt","r",stdin);
scanf("%u",&n);
while(n)
{	
	m=n/2+1;
	for(i=0,tot=0; prm[i]<m; i++)
	{
 		if( prim[ n-prm[i] ]==0 )
		{	tot++;	
			//printf("%u+%u ",prm[i],n-prm[i]);
		}
	}
	printf("%u\n",tot);
	scanf("%u",&n);
}//wh
}//main
/*---------------Load Primes in a array(*ar,untill_num)-----------------*/
/*------------If out of n then i<n, else if up to n then s<n------------*/
void sto_prim(unsigned int *p)
{	unsigned int s,sq, i,j; char q;
	*p=2; *(p+1)=3;  s=2;
	for(i=5;i<R;i+=2)
	{	q='0';
		sq=sqrt(i)+1;
		for(j=1;*(p+j)<sq;j++)
		{   
			if(i% *(p+j)==0) 
			{ 
				q='1';
				break; 
			}
		}
		if(q=='0')
			*(p+s++)=i;
	}
}
/*----Load Primes in a array untill index n by Sieve Algorithm(array_name, untill_n)----*/
//------------- prime 0 , non-prime 1 --------------
void seive_prim(char *prim)
{	unsigned int i,j;
	prim[0]=1;prim[1]=1;
	for(i=4;i<R;prim[i]=1,i+=2);
	for(i=3;i<R;i+=2)
	{	if(prim[i]==0)
			for(j=i+i;j<R;prim[j]=1,j+=i);
	}	
}