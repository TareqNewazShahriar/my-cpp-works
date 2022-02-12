#include<stdio.h>
#define R 200

long bin_srch(long n,long s);
long ar[R], i,n=0;

void main()
	{
	long num;
	freopen("num.txt","r",stdin);
	freopen("Difference.txt","w",stdout);
	scanf("%ld",&n);
	for(i=0;i<n;scanf("%ld",&ar[i]),i++);

	while(scanf("%ld",&num)!=EOF)
		{
			if(!bin_srch(n,num))
				{
				printf("%ld ",num);
				}
		}
	putchar(10);
	}
/*------Binary Search(array, total_element, searching_number)--------*/
long bin_srch(long n,long s)
	{
	long i=n/2,ini=0;
	if(*ar==s) return 1;
	else if(ar[n-1]==s) i=n-1;
	
	while(n-ini>1)
		{	
		if(ar[i]==s)
			{	while(ar[i-1]==s) i--;
				return i+1; 
			}
		else
			{	
			if(ar[i]<s) { ini=i; i=(i+n)/2; }
			else { n=i; i=(ini+i)/2; }
			}
		}
	return 0;
	}
