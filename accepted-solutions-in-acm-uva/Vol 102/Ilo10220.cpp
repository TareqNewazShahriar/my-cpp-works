#include<stdio.h>
#include<string.h>
#define R 5130
int len,l,i; long n; char a[R],z[R];
/*-----------------------Reverse(str,len)---------------------*/
void rev(char *s,int j)
{    char tmp;
	for(j--,i=0;i<j;i++,j--) { tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }
}
/*----Multiplication between string and int(des_str,str,int,len)----*/
/******The 2nd number b<21474836******/
int si_multiplication(char *r, char *a, long b, int len)
{	int i,j; unsigned long m=0;
	for(i=len-1,j=0;i>-1;i--)
	{	m+= (*(a+i)-48) * b;
		*(r+ j++)=(m%10)+48;
		m/=10;
	}
	while(m){ *(r+ j++)=(m%10)+48; m/=10; }
	if(*(r+j-1)==0) {*r=48; j=1;}
	else rev(r,j);  *(r+j)=0;
	return j;
}
/*----Multiplication between string without subtracting 48----*/
/*-----int(des_str,str,int,len)--The 2nd number b<21474836----*/
int si_multiplication_48(char *r, char *a, long b, int len)
{	int i,j; unsigned long m=0;
	for(i=len-1,j=0;i>-1;i--)
	{	m+= *(a+i)* b;
		*(r+ j++)=m%10;
		m/=10;
	}
	while(m){ *(r+ j++)=m%10; m/=10; }
	if(*(r+j-1)==0) {  *r=0; j=1; }
	else rev(r,j);  *(r+j)=0;
	return 1;
}
/*-----Multiplication between string and num without subtracting 48-----*/
/*---(des_str,str,num,len)-cautious about any str operation of des_str--*/
int si_multi_48(long m,int l1)//<Rquire rev_assign() >
{	char x[R],n2[4], sum; int l2=0,j,k, e=0;
	while(m>9) { n2[l2++]=m%10; m/=10; } n2[l2++]=m;
	for(j=l1+l2;j>-1;j--) z[j]=0;
	for(i=0;i<l2;i++) {	for(j=l1,m=0,k=0; j>-1; j--)
	{	m+=a[j]*n2[i]; x[k++]=(m%10); m=m/10;}
		if(m!=0) x[k++]=m;
		for(j=e,k=k+e,m=0; j<k; j++,m++)
		{	sum=z[j]+x[m]; if(sum>9) {z[j]=sum-10; (z[j+1])++;}
			else z[j]=sum; }	e++;
	} if(sum>9) k++; z[k]=0; rev(z,k); return k; }

void main()/*::::::::::::::::::::::::::::::::::::::::::::::::*/
{//m
//freopen("out.doc","w",stdout);
	while(scanf("%ld",&n)!=EOF)
	{    if(n<3) printf("%ld\n",n);
		else
		{	a[0]=1;a[1]=0; z[0]=1;z[1]=0; len=1;
			for(l=2,n++;l<n;l++)
			{	for(i=len--;i>-1;i--) a[i]=z[i];
				len=si_multi_48(l,len);
			}   for(i=0,n=0;i<len;i++) n+=z[i]; printf("%ld\n",n);
}	}	}//m