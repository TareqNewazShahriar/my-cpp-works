#include<stdio.h>
#include<math.h>
#include<algorithm>
#define R 10001
/*---------------------------Global Variables--------------------------*/
int n,book[R],money, one,index;
/*--------------------------Function Prototypes------------------------*/
int equal_cost()
{
	int i,j,m;
	
	for(i=index;i>=0;i--)
	{
		m=book[i];
		for(j=index+1;j<n;j++)
		{
			if(money==m+book[j]) return m;
		}
	}
	return money-one;
}

int comp_func(const int *x,const int *y)
{ return *x-*y; }
/*----------------------------main Function----------------------------*/
void main()
{
//freopen("11057.txt","r",stdin);
	int h,d,diff,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",book+i);
		
		qsort((void *)book,n,sizeof(int),( int (*)(const void *,const void *))comp_func);
		//sort(book,book+n);

		scanf("%d",&money);

		h=ceil(money/2.00);
		diff=1000001;
		for(i=0;book[i]<=h&&i<n;i++)
		{
			d=h-book[i];
			//if(d<0) d=-d;
			if(diff>d) 
			{
				index=i;
				diff=d;
			}
		}
		one=book[index];
		h=equal_cost();
		d=money-h;
		//book[index]=-1;
		//if(h>d) { diff=d; d=h; h=diff; }
		printf("Peter should buy books whose prices are %d and %d.\n\n",h,d);
	}

}
