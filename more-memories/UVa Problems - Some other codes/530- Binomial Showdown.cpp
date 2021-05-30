// wa
#include<stdio.h>
#define R 50000

typedef unsigned long long Type;
/*-------------Greatest Common Devisor[GCD](num_1,num_2)----------------*/
void gcd_katakati(Type *n,Type y)
{	
	Type a,b,i=0;
	while(y>1)
	{	
		a=n[i];
		if(a==1) { i++; continue; }
		b=y;
		while(b) 
		{	a%=b; 
			a^=b; b^=a; a^=b; 
		}
		if(a!=1) { n[i]/=a; y/=a; } 
		i++;
	}
}
void main()/*+++++++++++++++++++++++++++++++++++++++++++*/
{
//freopen("G:\\Programming\\Problems Coding\\ACM Problems Coding\\in2.txt","r",stdin);
	Type x,y, n[R],r[R], i,k,unt, comb;
	
	scanf("%llu%llu",&x,&y);
	while(x || y)
	{	
		if(x/2<y) y=x-y;
		unt=y; k=x;
		
		for(i=0; unt; unt--, n[i++]=k--);
		for(i=0,unt=y; unt; r[i++]=unt--);

		for(unt=0; unt<y; unt++)
		{
			for(i=0; n[i]%r[unt]&&i<y; i++ );
			
			if(y>i) n[i]/=r[unt];
			else gcd_katakati(n,r[unt]);
		}

		for(comb=1; i<y; comb*=n[i],i++);
		printf("%llu\n",comb);

		scanf("%llu%llu",&x,&y);
	}
}