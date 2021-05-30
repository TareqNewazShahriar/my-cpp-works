#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define R 200
/*---------------------------Global Variables--------------------------*/
class COMPETE
{	
public:
int min,sec,mil;
char name[25];
}compete[R];
/*--------------------------Function Prototypes------------------------*/
int comp_func(const COMPETE *x,const COMPETE *y)
{ 
	if(x->min!=y->min) return  x->min - y->min;
	else if(x->sec!=y->sec) return x->sec - y->sec;
	else if(x->mil!=y->mil) return x->mil - y->mil;
	return  strcmp(x->name,y->name);
}
/*----------------------------main Function----------------------------*/
void main()
{
//freopen("11056.txt","r",stdin);
	int i,N,q,row;
	char str[R];

	scanf("%d",&N);
	while(N)
	{
		const int n=N;;

		for(i=0;i<n;i++) scanf("%s%s%d%s%d%s%d%s",compete[i].name,str,
			&compete[i].min,str,&compete[i].sec,str,&compete[i].mil,str);
		
		qsort((void *)compete,n,sizeof(COMPETE),( int (*)(const void *,const void *))comp_func);
		
		q=2; row=0;
		
		for(i=0;i<n;i++)
		{
			if(q>1)
			{
				printf("Row %d\n",++row);
				q=0;
			}
			q++;
			puts(compete[i].name);
		}
		putchar(10);

		scanf("%d",&N);
	}

}
