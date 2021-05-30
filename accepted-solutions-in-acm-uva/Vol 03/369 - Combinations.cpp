#include<stdio.h>
//#include<string.h>
#define R 100
#define T 50
/*-------------Greatest Common Devisor[GCD](num_1,num_2)----------------*/
void gcd_katakati(int *n,int y)
{	int a,b,i=0;
	while(y>1)
	{	a=*(n+i);
		if(a==1) { i++; continue; }
		b=y;
		while(b) 
		{	a%=b; 
			a^=b; b^=a; a^=b; }
		if(a!=1) { *(n+i)/=a; y/=a; } 
		i++;
}	}
/*--Converting unsigned int to string and return the lenth without adding_48--*/
/*----------(unsigned  number,char *string)------------*/
int num_alpha_48(long n,char *str)
{	int i;
	for(i=0;n>0;i++)
	{
		*(str+i)=n%10; n/=10;
	}
	*(str+i)=0;
	return i;
}
/*----Multiplication between string without subtracting 48----*/
/*--------int(des_str,str,int,len)---------*/
int si_multiplication_48(char *r, char *a, long b, int len)
{	long m=0;	int i;
	for(i=0;i<len;i++)
	{	m+= *(a+i)* b;
		*(r+i)=m%10;
		m/=10;
	}
	while(m){ *(r+ i++)=m%10; m/=10; }
	return i;
}
/*---------Reverse & assign the char's by adding 48 (str,len)----------*/
void rev_assign(char *s,int j)
{   int i=0;  char tmp;
	*(s+j)=0;
	for(j--;i<j;i++,j--){tmp=*(s+i)+48; *(s+i)=*(s+j)+48; *(s+j)=tmp;}
	if(i==j) (*(s+i))+=48; 
}

void main()/*+++++++++++++++++++++++++++++++++++++++++++*/
{
//freopen("G:\\Programming\\Problems Coding\\ACM Problems Coding\\in2.txt","r",stdin);
	int x,y, n[R],r[T], i,k,unt; 
	unsigned long comb[10];	//18446744073709551615__20 digi  long=4294967296__10 digit
	char com[2][T], flag;
	scanf("%d%d",&x,&y);
	while(x || y)
	{	comb[0]=1,comb[1]=1,comb[2]=1,comb[3]=1,comb[4]=1;
		printf("%d things taken %d at a time is ",x,y);

		if(x/2<y) y=x-y;
		unt=y; k=x;
		for(i=0; unt; unt--, n[i++]=k--);
		for(i=0,unt=y; unt; r[i++]=unt--);

		for(unt=0; unt<y; unt++)
		{
			for(i=0;n[i]%r[unt] && i<y; i++ );
			if(y>i) n[i]/=r[unt];
			else gcd_katakati(n,r[unt]);
		}
		for(unt=0,i=0;i<y;unt++)
		{
			for(comb[unt]=1; i<y && comb[unt]<2294967; comb[unt]*=n[i],i++);
		}
		if(unt>1)
		{////
		/*k=num_alpha_48(comb[0],com[0]);
		for(i=1,flag=0;i<unt; i++)
		{	if(comb[i]!=1)
			{
				flag=!flag;
				k=si_multiplication_48(com[flag],com[!flag],comb[i],k);
			}
		}
		rev_assign(com[flag],k);
		*/
		printf("%lu exactly.\n",comb[0]*comb[1]*comb[2]*comb[3]*comb[4]);
		}////
		else printf("%lu exactly.\n",comb[0]);
		scanf("%d%d",&x,&y);
}	}	