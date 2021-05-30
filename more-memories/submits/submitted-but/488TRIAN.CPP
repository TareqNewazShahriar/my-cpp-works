#include<stdio.h>
void main()
{//m
	char q='n', w='0';
	int cs,a, b, i, j;
//freopen("input.txt","r",stdin);
//freopen("scan.txt","w",stdout);
	scanf("%d",&cs);
	for(;cs>0;cs--)
	{	scanf("%d%d",&a,&b);
		i=0;j=1;
		for(;b>0;b--)
		{	if(q=='y' && w!='1') {	printf("\n");  w++;	   }
			for(i=1;i<=a;i++)
			{	w='0';
				for(j=0;j<i;j++)    printf("%d",i);
				printf("\n");
			}//3f
			for(i-=2;i>0;i--)
			{	for(j=0;j<i;j++) printf("%d",i);
				if(b>1 || i>1) printf("\n");
			} q='y';
		}//2f
	}//1f
}//m