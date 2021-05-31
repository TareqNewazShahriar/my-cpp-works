#include<stdio.h>
#define SIZE 101
typedef long long Type;
/****************************Global Variables***************************/
Type cube[SIZE][SIZE]={{0},{1,1},{-1,0,0},{6,3,4,5},{18,4,7,8,17}};
/*************************User Defined Functions************************/
void load_sum_of_n_cubes()
	{
	Type *cu,i,j,k,b, u,v;
	bool q;
	// for odd n
	for(i=5;i<SIZE;i+=2)
		{
		cu=cube[i];
		k=i-2;
		for(j=k;j>=0;j--)
			cu[j]=cube[k][j];
		k++;
		b=*cu*2;
		u=v=((b*2)-*cu)/2;
		q=1;
		for( ; u>*cu; u--,v++)
			{
			if( (b*b*b)==(*cu*(*cu)*(*cu)+u*u*u+v*v*v) )
				{	q=0; cu[k]=u, cu[k+1]=v, *cu=b; break; }
			}
		if(q)
			{
			for(cu[0]=-1,j=1;j<=i;cu[j]=0,j++);
			}
		}
	// for even n
	for(i=6;i<SIZE;i+=2)
		{
		cu=cube[i];
		k=i-2;
		for(j=k;j>=0;j--)
			cu[j]=cube[k][j];
		k++;
		b=*cu*2;
		u=v=((b*2)-*cu)/2;
		q=1;
		for( ; u>*cu; u--,v++)
			{
			if( (b*b*b)==(*cu*(*cu)*(*cu)+u*u*u+v*v*v) )
				{	q=0; cu[k]=u, cu[k+1]=v, *cu=b; break; }
			}
		if(q)
			{
			for(cu[0]=-1,j=1;j<=i;cu[j]=0,j++);
			}
		}
	}
/*****************************main Function*****************************/
void main()
	{
	Type t,cs=0,i,n;

	//freopen("out01.doc","w",stdout);
	
	load_sum_of_n_cubes();
	scanf("%lld",&t);
	for(;t;t--)
		{
		scanf("%lld",&n);

		printf("Case %lld:",++cs);
		for(i=0;i<=n;i++)
			printf(" %lld",cube[n][i]);
		putchar('\n');
		}
	}