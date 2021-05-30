// AC
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 51
#define SIZE 100

char x[SIZE*2],y[SIZE*2];
int compare_( const char *s1, const char *s2 )
{
	strcpy( x,s1 );
	strcpy( y,s2 );

	strcat( x,s2 );
	strcat( y,s1 );

	return strcmp(y,x);
}

void main()
{	
	//freopen("10905.txt","r",stdin);	
	int i,n;
	char str[N][SIZE];

	scanf("%d",&n);
	while(n)
	{
		for(i=0;i<n;i++) scanf("%s",str+i);

		qsort((void *)str,n,sizeof(str[0]),(int(*)(const void *,const void *))compare_);

		for(i=0;i<n;i++) printf("%s",str[i]);
		puts("");
		
		scanf("%d",&n);
	}
}