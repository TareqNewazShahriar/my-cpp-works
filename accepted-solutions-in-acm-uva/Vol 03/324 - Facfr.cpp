#include<stdio.h>
#include<string.h>
#define R 2300
/*-----------------------Reverse(str,len)---------------------*/
void rev(char *s,int j)
{    int i=0;  char tmp;
	for(j--;i<j;i++,j--) { tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }}
/*-----Multiplication between string and num without subtracting 48-----*/
/*---(des_str,str,num,len)-cautious about any str operation of des_str--*/
int si_multi_48(char *r,char *n1,long m,int l1)//<Rquire rev_assign() >
{	char x[R],n2[4], sum; int l2=0,i,j,k, z=0;
	while(m>9) { n2[l2++]=m%10; m/=10; } n2[l2++]=m;
	for(j=l1+l2;j>-1;j--) *(r+j)=0;
	for(i=0;i<l2;i++) {	for(j=l1,m=0,k=0; j>-1; j--)
	{	m+=*(n1+j)*n2[i]; x[k++]=(m%10); m=m/10;}
		if(m!=0) x[k++]=m;
		for(j=z,k=k+z,m=0; j<k; j++,m++)
		{	sum=*(r+j)+x[m]; if(sum>9) {*(r+j)=sum-10; (*(r+j+1))++;}
			else *(r+j)=sum; }	z++;
	} if(sum>9) k++; *(r+k)=0; rev(r,k); return k; }
void main()/*::::::::::::::::::::::::::::::::::::::::::::::::*/
{//m
	int n, len,k,i; char a[R],z[R]; unsigned char f[10];
//freopen("input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{    if(n==0) break;
		printf("%d! --\n",n);
		a[0]=1;a[1]=0; z[0]=1;z[1]=0; len=1;
		for(k=2,n++;k<n;k++)
		{	for(i=len--;i>-1;i--) a[i]=z[i];
			len=si_multi_48(z,a,k,len);
		}for(k=0;k<10;k++) f[k]=0; for(k=0;k<len;k++) f[z[k]]++;

		if(f[0]<10) printf("   (0)    %d",f[0]);
		else if(f[0]<100) printf("   (0)   %d",f[0]);
		else printf("   (0)  %d",f[0]);
		for(i=1;i<5;i++)
			if(f[i]>9) printf("    (%d)   %d",i,f[i]);
			else printf("    (%d)    %d",i,f[i]);
		if(f[5]>9)printf("\n   (5)   %d",f[5]);
		else printf("\n   (5)    %d",f[5]);
		for(i=6;i<10;i++)
			if(f[i]>9) printf("    (%d)   %d",i,f[i]);
			else printf("    (%d)    %d",i,f[i]);
		printf("\n");
}	}//m