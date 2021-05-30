#include<stdio.h>
void main()
{	int cs, n, lp, ar[50], tmp, sw, c;
	char q;
	//freopen("scan.txt","r",stdin);
	scanf("%d",&cs);
	for(;cs>0;cs--)
	{// f
		sw=0;
		scanf("%d",&n);
		for(lp=0;lp<n;lp++)
		{
			scanf("%d",&ar[lp]);
		}
		n=n-1;
		for(;n>0;n=n-c;)
		{// 3f
			q='n';
			for(lp=0;lp<n;lp++)
			{// 2f
				if(ar[lp]>ar[lp+1])
				{// 1if
					tmp=ar[lp];
					ar[lp]=ar[lp+1];
					ar[lp+1]=tmp;
					c=n-lp;
					sw++;
					q='y';
				}// 1if
			}// 2f
			if(q=='n')
				break;
		}// 3f
		printf("Optimal train swapping takes %d swaps.\n",sw);
	}//1 for
}// main