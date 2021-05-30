#include<stdio.h>
#include<string.h>
int lenh,n,k=-1;
//Equalise the lenth of two string by adding ' ' & '\n':(str1,str2,len1,len2)
void spc(char *a,int len)
{    if(k!=0) for(;len<lenh;len++) *(a+len)='-';//32;
	else for(;len<lenh;len++) *(a+len)='\n';
}
void main()
{	
freopen("\\\\Khaledmahmood\\ACM & OS (D)\\ACM problems & solving\\tc\\bin\\in.txt","r",stdin);
freopen("\\\\Khaledmahmood\\ACM & OS (D)\\ACM problems & solving\\tc\\bin\\out.txt","w",stdout);
char a[101][101]; int len[100];
//freopen("input.txt","r",stdin);
//freopen("out.doc","w",stdout);
	while(gets(a[++k]))
	{ 	len[k]=strlen(a[k]); if(len[k]>lenh) lenh=len[k];	}
	n=--k;
	while(k>-1)
	{	if(len[k]!=lenh) spc(a[k],len[k]);	k--;	}
		//if(len>lenh) lenh=len;
	for(len[0]=lenh,lenh=0;lenh<len[0];lenh++)
	{	for(k=n;k>0;k--)
			printf("%c",a[k][lenh]);

		if(a[k][lenh]!='\n') printf("%c\n",a[k][lenh]);
		else printf("\n",a[k][lenh]);
	}
}//m