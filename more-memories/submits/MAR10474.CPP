#include<stdio.h>
#include<search.h>
typedef int (*fptr)(const void*, const void*);
 #define NELEMS(arr) (sizeof(arr) / sizeof(arr[0]))
 int numarray[] = {123, 145, 512, 627, 800, 933};
 int numeric (const int *p1, const int *p2)
 {  return(*p1 - *p2); }
 #pragma argsused
 int lookup(int key)
 {  int  *itemptr;
	// The cast of (int(*)(const void *,const void*))
	// is needed to avoid a type mismatch error at
	// compile time
	itemptr = (int *) bsearch (&key, numarray, NELEMS(numarray),
		 sizeof(int), (fptr)numeric);
	return (itemptr != NULL);
 }
/* int main(void)
 {  if ( lookup(512) )   printf("512 is in the table.\n");
    else   printf("512 isn't in the table.\n");
    return 0;  }   //*/
int bin_srch(int *ar,int n,int s)
{    int i=n/2,ini=0;
	if(*ar==s) return 0;  else if(*(ar+n-1)==s) i=n-1;
	for(;(n-ini)>1;)
	{	if(*(ar+i)==s)
		{    while(*(ar+i-1)==s) i--; return i; }
		else
		{	if(*(ar+i)<s) { ini=i; i=(i+n)/2; }
			else { n=i; i=(ini+i)/2; }
	}	} return -1;   }
int num_com(const void
*a,const void *b)
{    int *x=(int *)a; int *y=(int *)b;
	return *x-*y;
}
void main()//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::
{	int cs=0,n,q,x,i,j,find,mar[10001];
//freopen("input.txt","r",stdin);
	while(scanf("%d%d",&n,&q)!=EOF)
	{    if(n==0&&q==0) break;
		printf("CASE# %d:\n",++cs);
		for(i=0;i<n;i++) scanf("%d",&mar[i]);
		//sel_sort(mar,n);
		qsort(mar,n,2,num_com);
		for(j=0;j<q;j++)
		{	scanf("%d",&x);
			find=bin_srch(mar,n,x)+1;
			if(find>0) printf("%d found at %d\n",x,find);
			else printf("%d not found\n",x);
}	}	}//m
/* int main(void)
 {  if (lookup(512)) printf("512 is in the table.\n");
    else printf("512 isn't in the table.\n");
    return 0;  }    //*/