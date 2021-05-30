#include<stdio.h>
#include<string.h>
#define R 15000
char a[R],z[R];
/*---------Reverse & assign the char's by adding 48 (str,len)----------*/
void revcop(int j)
{    int i=0;
	for(j--;i<j;i++,j--) { a[i]=z[j]; a[j]=z[i]; }
	if(i==j) a[i]=z[i]; 	}
/*-----Multiplication between string and num without subtracting 48-----*/
/*---(des_str,str,num,len)-cautious about any str operation of des_str--*/
int si_multi_48(long m,int l1)//<Rquire rev_assign() >
{	char x[R],n2[4], sum; int l2=0,i,j,k, w=0;
	while(m>9) { n2[l2++]=m%10; m/=10; } n2[l2++]=m;
	for(j=l1+l2;j>-1;j--) z[j]=0;
	for(i=0;i<l2;i++) {	for(j=l1-1,m=0,k=0; j>-1; j--)
	{	m+=a[j]*n2[i]; x[k++]=(m%10); m/=10;}
		if(m!=0) x[k++]=m;
		for(j=w,k+=w,m=0; j<k; j++,m++)
		{	sum=z[j]+x[m]; if(sum>9) {z[j]=sum-10; z[j+1]++;}
			else z[j]=sum; }	w++;
	} if(sum>9) k++;  return k; }
void main()/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
{//m
	int n, len,k,i,j;
//freopen("out.doc","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{	printf("%d!\n",n);
		a[0]=1; z[0]=1; len=1;
		for(k=2,n++;k<n;k++)
		{	for(i=0,j=len-1;i<j;i++,j--) { a[i]=z[j]; a[j]=z[i]; }
			if(i==j) a[i]=z[i];
			len=si_multi_48(k,len);
		} for(k=len-1;k>-1;k--) printf("%d",z[k]); printf("\n");
}	}//m