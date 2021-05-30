#include<stdio.h>
#include<string.h>
#define R 105
char fib[2][R],r[R];
/*---------------------string Compare(str1,str2,len1,len2)-----------------*/
int str_cmp(char *a,char *b,int lena,int lenb)
{    if(lena>lenb) return 1;
	else if(lenb>lena) return -1;
	else
	{   for(lena=0,lenb--;lenb>-1;lena++,lenb--)//comparing "b" reversely.
			if(*(a+lena)>(*(b+lenb))) return 1;
			else if(*(b+lenb)>(*(a+lena))) return -1;
	} return 0;
}
/*----------Addition of 2 strings(des str,str1,str2,len1,len2)------------*/
int ss_add(int len,int i)//<Require revcop & rev>
{    char sum;//m[R],n[R], sum;
	//revcop(&m[0],len,0); revcop(&n[0],i,1);
	if(len>i) for(;i<len;i++) fib[1][i]=48;
	else if(len<i) for(;len<i;len++) fib[0][len]=48;
	for(sum=0,i=0;i<len;i++)
	{	sum+=fib[0][i]+fib[1][i];
		if (sum>105) {	r[i]=sum-58; sum=1; }
		else  { r[i]=sum-48; sum=0; }
	}if(sum==1) {r[i++]=49;} r[i]=0; return i;  }
void main()/*:::::::::::::::::::::::::::::::::::::::::::::*/
{	int len[2],k,n,lena,lenb,x; char a[R],b[R];
//freopen("input.txt","r",stdin);
//freopen("out.doc","w",stdout);
	while(scanf("%s%s",a,b)!=EOF)
	{    if(strcmp(a,"0")==0&&strcmp(b,"0")==0) break;
		lena=strlen(a); lenb=strlen(b);
		if(lenb<lena||(lenb==lena&&strcmp(a,b)>0))
			{strcpy(r,a);x=lena;strcpy(a,b);lena=lenb;strcpy(b,r);lenb=x;}
		//if((strcmp(a,"0")==0||strcmp(a,"1")==0||strcmp(b,"2")==0)&&(strcmp(a,"0")!=0||strcmp(b,"1")!=0)) n++;
		fib[0][0]=49;fib[0][1]=0; fib[1][0]=49;fib[1][1]=0;
		len[0]=1; len[1]=1; k=0;
		x=str_cmp(a,fib[0],lena,len[0]);
		while(x>0)
		{    len[k]=ss_add(len[0],len[1]); strcpy(fib[k],r);
			x=str_cmp(a,fib[k],lena,len[k]);k=!k; //revcop(len[!k],k);
		} x=str_cmp(b,fib[!k],lenb,len[!k]);
		n=0;
		while(x>=0)
		{    len[k]=ss_add(len[0],len[1]); strcpy(fib[k],r);
			x=str_cmp(b,fib[k],lenb,len[k]); k=!k; n++;//revcop(len[!k],k);
		} printf("%d\n",n);
}	}//m