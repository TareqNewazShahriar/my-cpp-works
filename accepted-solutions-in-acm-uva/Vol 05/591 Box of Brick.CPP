#include <stdio.h>
void main()
{	int wl, ar[50], i, sum, dev, set=0;
	//freopen("input.txt","r",stdin);
	while(scanf("%d",&wl)!=EOF)
	{
		if(wl==0)
			break;
		/*if(set!=0)
			printf("\n");*/
		set++;
		sum=0;
		for(i=0;i<wl;i++)
		{
			scanf("%d",&ar[i]);
			sum+=ar[i];
		}
		dev=sum/wl;
		sum=0;
		for(i=0;i<wl;i++)
		{
			if(ar[i]<dev)
			{
				sum+=dev-(ar[i]);
			}
		}
		printf("Set #%d\n",set);
		printf("The minimum number of moves is %d.\n\n",sum);
	}
}