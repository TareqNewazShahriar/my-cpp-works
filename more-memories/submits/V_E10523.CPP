#include<stdio.h>
#include<string.h>
#define R 500
char a[2],b[R],x[R], y[R],z[R];
/*----Reverse and copy to destination simultaneously(des_str,str,len)----*/
void revcop(char *des,char *s,int j)
{    int i=0;
	for(j--;i<j;i++,j--) { *(des+i)=*(s+j); *(des+j)=*(s+i); }
	if(i==j) *(des+i)=*(s+i);	}
/*-----------------------Reverse(str,len)---------------------*/
void rev(char *s,int j)
{    int i=0;  char tmp;
	for(j--;i<j;i++,j--) { tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }}
/*---------------Addition of 2 strings with subtrcting 48----------------*/
/*-(des_str,str1,str2,len1,len2)-cautious about any str operatio of des_str*/
int ss_add_48(int len,int i)//<Require revcop & rev>
{    char m[R],n[R], sum;
	revcop(&m[0],y,len); revcop(&n[0],x,i);
	if(len>i) for(;i<len;i++) n[i]=0;
	else if(len<i) for(;len<i;len++) m[len]=0;
	for(sum=0,i=0;i<len;i++)
	{	sum+=(m[i]+n[i]);
		if (sum>9) { z[i]=sum-10; sum=1; }
		else  { z[i]=sum; sum=0; }
	}if(sum==1) { z[i]=1; z[++i]=0; }
	 else  z[i]=0; revcop(y,z,i);  return i;   }
/*---Addintion of 2 string in practical way(des_str,str1,str2,len1,len2)---*/
/*---------Assume that no a carry; Carefull about any str operation--------*/
int ss_add_048(int len,int ln)
{    char sum=0; int i=0,k=len; if(len<ln) k=ln;
	for(len--,ln--;ln>-1&&len>-1;len--,ln--)
	{	sum+=y[len]+x[ln];
		if (sum>9) { z[i++]=sum-10; sum=1; }
		else  { z[i++]=sum; sum=0; }
	} if(len>-1) for(;len>-1;len--)
		{ sum+=y[len]; if (sum>9) { z[i++]=0; sum=1; }
		else{z[i++]=sum;sum=0;for(len--;len>-1;len--)z[i++]=y[len];break;}}
	  else if(ln>-1) for(;ln>-1;ln--)
		{ sum+=x[ln]; if (sum>9) { z[i++]=0; sum=1; }
		else{ z[i++]=sum; sum=0; for(ln--;ln>-1;ln--) z[i++]=x[ln];break;}}
	  if(sum==1) { for(k++;i>0;i--) z[i]=z[i-1]; z[0]=1; }
		revcop(y,z,k); return k; }
/*-------Multiplication between string and num without subtracting 48------*/
/*---(des_str,str,num,len)-cautious about any str operation of des_str--*/
int sn_multi_48(long m,int l1)//< Require rev() >
{	char v[R],n2[4], sum; int l2=0,i,j,k, z=0;
	while(m>9) { n2[l2++]=m%10; m/=10; } n2[l2++]=m;
	for(j=l1+l2;j>-1;j--) x[j]=0;
	for(i=0;i<l2;i++) {	for(j=l1-1,m=0,k=0; j>-1; j--)
	{	m+=b[j]*n2[i]; v[k++]=(m%10); m=m/10;} if(m!=0) v[k++]=m;
		for(j=z,k=k+z,m=0; j<k; j++,m++)
		{	sum=x[j]+v[m]; if(sum>9) {x[j]=sum-10; x[j+1]++;}
			else x[j]=sum; } z++;
	} if(sum>9) k++; x[k]=0;
	  if(x[k-1]==0) {x[0]=0; k=1;} else rev(x,k); return k; }
/*--------Multiplication between 2 strings without subtracting 48---------*/
/*-(des_str,str1,str2,len1,len2)-cautious about any str operatio of des_str*/
int ss_multi_48(int l1,int i)//< Require rev() >
{	char v[R], sum; int j,k, m,z=0;
	for(j=l1+i;j>-1;j--)  x[j]=0;
	for(i--;i>-1;i--)
	{	for(j=l1-1,m=0,k=0; j>-1; j--)
		{ 	m+=b[j]*a[i];
			v[k++]=(m%10); m=m/10; }
		if(m!=0) v[k++]=m;
		for(j=z,k=k+z,m=0; j<k; j++,m++) { sum=x[j]+v[m];
			if(sum>9) { x[j]=sum-10; x[j+1]++; } else x[j]=sum;
	}z++;} if(sum>9) k++; x[k]=0;
	if(x[k-1]==0) {x[0]=0; k=1;} else revcop(b,x,k); return k; }
int main()//:::::::::::::::::::::::::::::::::::::::::::::::::::::
{	int n,i,k,lenb,lena, d,j,leny;
	while(scanf("%d%s",&n,a)!=EOF)
	{    lena=strlen(a); leny=0; a[0]-=48; a[1]-=48;
		for(k=1,n++;k<n;k++)
		{    lenb=lena; b[0]=a[0];b[1]=a[1];
			for(i=1;i<k;i++)
			{  lenb=ss_multi_48(lenb,lena);  }
			lenb=sn_multi_48(k,lenb);
			//for(j=0;j<leny;j++) y[j]=z[j];
			leny=ss_add_048(leny,lenb);
		} for(j=leny-1;j>-1;j--) printf("%d",z[j]); printf("\n");
}return 1;	}//m