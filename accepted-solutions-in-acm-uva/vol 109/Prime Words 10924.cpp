#include<stdio.h>
#define idx 1041
/*----Load Primes in a array untill index n by Sieve Algorithm(char array_name,int untill_n)----*/
//if prime then 0, else 1//
void seive_prim(char *prim)
{	int i,j;
	*prim=1;
	for(i=4;i<1041;*(prim+i)=1,i+=2);
	for(i=3;i<1041;i+=2)
	{	if(*(prim+i)==0)
			for(j=i+i;j<1041;*(prim+j)=1,j+=i);
}	}
//int alpha_num[52]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,0,0,0,0,0,0,
//					27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52};
int digit_sum(char *str)
{	int i,sum=0;
	for(i=0;*(str+i);i++) 
	{	if(*(str+i)<92)sum+= *(str+i)-38; 
		else sum+= *(str+i)-96;
	}
	return sum;
}

void main()
{	const int index=21;
	char instr[index]; static char prim[idx];
	seive_prim(prim);
//freopen("in.txt","r",stdin);
	while(gets(instr))
	{	
		//printf(" %d\n",sum); //fputs(str,stout);
		//fputs(instr,stdout); 
		if( prim[digit_sum(instr)] ) puts("It is not a prime word.");
		else	puts("It is a prime word."); //*/
}	}			