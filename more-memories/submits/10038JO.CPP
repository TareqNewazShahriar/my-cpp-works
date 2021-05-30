#include<stdio.h>
#include<math.h>
void main()
{//m
	char q;
	int s, i, n[2];
//freopen("input.txt","r",stdin);
	while(scanf("%d",&s)!=EOF)
	{//w
		q='n';
		i=0;
		scanf("%d",&n[0]);
		if(s!=1)
		{//1i
			for(s--;s>0;s--)
			{//1f
				i=!i;
				scanf("%d",&n[i]);
				if( (abs(n[!i]-n[i])!=s) && (q=='n') )
				{//e
					printf("Not jolly\n");
					q='y';
				}//e
			}//1f
		}//1i
		if(q=='n')
		{//0i
			printf("Jolly\n");
		}//0i
	}//w
}//m