#include<stdio.h>
#include<string.h>
//#include<time.h>
#define R 180
/*-----------------------Reverse(str,len)---------------------*/
void rev(char *s,int j)
{    int i=0;  char tmp;
	for(j--;i<j;i++,j--) { tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }
}
/*----Reverse and copy to destination simultaneously(des_str,str,len)----*/
void revcop(char *des,char *s,int j)
{    int i=0;	*(des+j)='\0';
	for(j--;i<j;i++,j--) { *(des+i)=*(s+j); *(des+j)=*(s+i); }
	if(i==j) *(des+i)=*(s+i);	}
/*----Multiplication between string and int(des_str,str,int,len)----*/
int si_multiplication(char *r, char *a, long b, int len)
{	int i,j,m=0;
	for(i=len-1,j=0;i>-1;i--)
	{	m+= (*(a+i)-48)* b;
		*(r+ j++)=(m%10)+48;
		m/=10;
	}
	while(m){ *(r+ j++)=(m%10)+48; m/=10; }
	if(*(r+j-1)==0) {*r=48; *(r+1)=0;}
	else { *(r+j)=0;  rev(r,j); }
	return j;
}
/*----------Addition of 2 strings(des str,str1,str2,len1,len2)------------*/
int ss_add(char *r,char *u,char *v,int len,int i)//<Require revcop & rev>
{    char m[R],n[R], sum;
	revcop(m,u,len); revcop(n,v,i);
	if(len>i) for(;i<len;i++) n[i]=48;
	else if(len<i) for(;len<i;len++) m[len]=48;
	for(sum=0,i=0;i<len;i++)
	{	sum+=(m[i]+n[i]);
		if (sum>105) {	*(r+i)=sum-58; sum=1; }
		else  { *(r+i)=sum-48; sum=0; }
	}if(sum==1) { *(r+i)=49; *(r+(++i))=0; }
	 else  *(r+i)=0; 	rev(r,i);
	return i;
}
/***********It doesn't work****************/
void swap(char *s1,char *s2)
{	char *tmp;
	tmp=s1; 
	s1=s2; 
	s2=tmp; 
}

void main()//:::::::::::::::::::::::::::::::::::::::::::::::::::::
{	char  q, str[2][R],til[R],add[R];	//char t1[10],t2[10];
	int n,a,k,lenstr,lentil,lenadd;
//freopen("in.txt","r",stdin);
//freopen("out.doc","w",stdout);
	//_strtime( t1 );
	while(scanf("%d%d",&n,&a)!=EOF)
	{   str[0][0]=49;str[0][1]=0; lenstr=1;
		*add=48;add[1]=0; lenadd=1;
		for(k=1,n++,q=0;k<n;k++)
		{	
			lenstr=si_multiplication(str[!q],str[q],a,lenstr);   q=!q;
			lentil=si_multiplication(til,str[q],k,lenstr);
			lenadd=ss_add(add,add,til,lenadd,lentil);
			
			//swap(str,t);
		}
		
		printf("%s\n",add);
	}
	//_strtime( t2 );
	//printf( "OS time: %s\n", t1 );
	//printf( "OS time: %s\n", t2 );

}//m
