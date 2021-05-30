#include<stdio.h>
void main()
{//m
	char q='n', w='0';
	int cs,a, b, i, j;
//freopen("input.txt","r",stdin);
//freopen("scan.txt","w",stdout);
	scanf("%d",&cs);
	for(;cs>0;cs--)
	{//0f
		scanf("%d%d",&a,&b);
		i=0;j=1;
		for(;b>0;b--)
		{//1f
			if(q=='y' && w!='1')
			{	printf("\n");  w++;	   }
			for(i=1;i<=a;i++)
			{//2f
				w='0';
				for(j=0;j<i;j++)    printf("%d",i);
				printf("\n");
			}//2f
			for(i-=2;i>0;i--)
			{//4f
				for(j=0;j<i;j++)	printf("%d",i);
				if(b>1 || i>1)
				printf("\n");
			}//4f
			q='y';
		}//1f
	}//0f
}//m