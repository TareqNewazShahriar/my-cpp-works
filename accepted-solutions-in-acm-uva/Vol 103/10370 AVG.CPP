#include<stdio.h>
void main()
{
	int gd[1000], cs, st, i;
	float avg;
	long sum;
//freopen("input.txt","r",stdin);
	scanf("%d",&cs);
	if(cs!=0)
	{//6i
		for(;cs>0;cs--)
		{//1f
			sum=0;
			scanf("%d",&st);
			for(i=0;i<st;i++)
			{//2f
				scanf("%d",&gd[i]);
				sum+=gd[i];
			}//2f
			if(st!=0)
			{//5i
				avg=sum/st;
				sum=0;
				for(i=0;i<st;i++)
				{//3f
					if(gd[i]>avg)
					{//1i
						sum++;
					}//1i
				}//3f
				avg= ( float(sum) / float(st) )*100;
				printf("%.3f%%\n",avg);
			}//5i
			else
				printf("%.3f%%",0.000);
		}//1f
	}//6i
}//m
