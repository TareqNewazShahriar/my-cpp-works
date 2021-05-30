#include<stdio.h>
void main()
{//m
	int s, n;
	char q;
//freopen("input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{//1w
		if(n!=0)
		{//i
			q='n';
			for(;n>0;n--)
			{//f
				scanf("%d",&s);
				if(s>0)
				{//i
					if(q=='y')
						printf(" %d",s);
					else
					{	printf("%d",s);   q='y';   }
				}//i
			}//f
			if(q=='n')
				printf("0");

			printf("\n");
		}//i
		else break;
	}//1w
}//m