#include<stdio.h>
#include<string.h>
#define R 3000
char fib[2][R],r[R];
/*----------Addition of 2 strings(des str,str1,str2,len1,len2)------------*/
int ss_add(int len,int i)//<Require revcop & rev>
{    char sum;//m[R],n[R], sum;
	//revcop(&m[0],len,0); revcop(&n[0],i,1);
	if(len>i) for(;i<len;i++) fib[1][i]=0;
	else if(len<i) for(;len<i;len++) fib[0][len]=0;
	for(sum=0,i=0;i<len;i++)
	{	sum+=fib[0][i]+fib[1][i];
		if (sum>9) {	r[i]=sum-10; sum=1; }
		else  { r[i]=sum; sum=0; }
	}if(sum==1) {r[i++]=1;} return i;  }
void main()/*:::::::::::::::::::::::::::::::::::::::::::::*/
{	int len[2],k,n,i;
//freopen("out.doc","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{    printf("The Fibonacci number for %d is ",n);
		if(n==0) printf("0\n");
		else if(n<3) printf("1\n");
		else
		{	fib[0][0]=1; fib[1][0]=1;len[0]=1; len[1]=1;
			for(n-=2,k=1;n>0;n--)
			{    len[k]=ss_add(len[0],len[1]);
				for(i=len[k]-1;i>-1;i--) {fib[k][i]=r[i];}
				k=!k; //revcop(len[!k],k);
			} for(i=len[!k]-1;i>-1;i--) printf("%d",r[i]);
			printf("\n");
}	}	}//m