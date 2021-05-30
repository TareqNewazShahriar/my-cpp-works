#include<stdio.h>
#include<string.h>
#define R 255
char a[R],b[R],c[600];

void ss_multi(char *c,char *a,char *b,int l1,int i);
int si_multiplication(char *r, char *a, long b, int len);

/*---------Reverse & assign the char's by adding 48 (str,len)----------*/
void rev_assign(int j)
{    int i=0;  char tmp;
	for(j--;i<j;i++,j--){tmp=c[i]+48; c[i]=c[j]+48; c[j]=tmp;}
	if(i==j) c[i]+=48; 	  }
/*------Multiplication between 2 strings(des_str,str1,str2,len1,len2)------*/
void ss_multi(char *c,char *a,char *b,int l1,int i)//<Require rev_assign() >
{	char x[R]; int j,k,sum, m,z=0;
	for(j=l1+i;j>-1;j--)  c[j]=0;
	for(i--;i>-1;i--)
	{	for(j=l1-1,m=0,k=0; j>-1; j--)
		{ 	m+=(a[j]-48)*(b[i]-48); x[k++]=m%10; m/=10; }
		if(m!=0) x[k++]=m;
		for(j=z,k+=z,m=0; j<k; j++,m++) { sum=c[j]+x[m];
			if(sum>9) { c[j]=sum-10; c[j+1]++; } else {c[j]=sum;}
		} z++;
	} if(sum>9) k++; c[k]=0;
	if(c[k-1]==0) {c[0]=48; c[1]=0;} else rev_assign(k);
}
/*--------------------------Finding Zero(str)--------------------*/
void fzero(char *s)
{	int i,z=0;
	for(i=0;*(s+i)==48;i++) {z++;}
	if(z>0) {strcpy(s,s+z);}
}
void main()/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
{//m
	int lena,lenb;    char ar[12];ar[0]=0;
freopen("in.txt","r",stdin);
//freopen("out.doc","w",stdout);
	while(gets(a))
	{    gets(b);
		fzero(a); fzero(b);
		lena=strlen(a); lenb=strlen(b);
		if(lena==0||lenb==0) printf("0\n");
		else { ss_multi(c,a,b,lena,lenb); 
		printf("%s\n",c); }

}	}//m
