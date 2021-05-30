#include<stdio.h>
#include<stdlib.h>
#define A 10000
int bin_srch(int *ar,int n,int s);

int num_com(const void *a,const void *b)
{    int *x=(int *)a; int *y=(int *)b;
	return *x-*y;
}
int compare_(const int *a,const int *b)
	{ return *a-*b; }

int comp_func(const int *x,const int *y)
	{ return *x-*y; }

void main()//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::
{	int cs=0,n,q,x,find,mar[A];
//freopen("marble.txt","r",stdin);
	while(scanf("%d%d",&n,&q)!=EOF)
	{   if(n==0&&q==0) break;
		
		printf("CASE# %d:\n",++cs);
		
		for(x=0;x<n;x++) scanf("%d",&mar[x]);
		
		qsort((void *)mar,n,sizeof(int),( int (*)(const void *,const void *))comp_func);
		for(;q>0;q--)
		{	
			scanf("%d",&x);
			//find=(int*)bsearch(&x,mar,n,sizeof(int),num_com);
			//), (int (*)(const void*, const void*))compare );
			find=bin_srch(mar,n,x);
			//if(find)	while(*(find-1)==x && (find-1)>=mar ) find--;
			if(find) printf("%d found at %d\n",x,find);
			else printf("%d not found\n",x);
}	}	}//m
/*---Binary Search (array_name, elements, searching_key)----*/
int bin_srch(int *ar,int n,int s)
{   
	int i=n/2,ini=0;
	if(*ar==s) return 1;  else if(*(ar+n-1)==s) i=n-1;
	while( (n-ini)>1 )
	{		
		if(*(ar+i)==s)
		{	while(*(ar+i-1)==s) i--; return i+1; }
		else
		{	
			if(*(ar+i)<s) { ini=i; i=(i+n)/2; }
			else { n=i; i=(ini+i)/2; }
		}
	}
	return 0;
}	