#include<stdio.h>

void main()
{
//freopen("F:\\Programming\\Problems Coding\\pACM Problems Coding\\in08.txt","r",stdin);
	int cs=0,n,byte,sum=0,time,sec,trans, x;
	scanf("%d",&n);
	while(n)
	{
		printf("Output for data set %d, %d bytes:\n",++cs,n);
		
		scanf("%d",&byte);
		sum=trans=byte; sec=time=1; 
		while(sum<n)
		{
			scanf("%d",&byte);
			sec++; sum+=byte; time++; trans+=byte;
			if(sec==5)
			{
				if(trans==0) puts("   Time remaining: stalled");
				else
				{	x=(n-sum)*5;
					x=(x+trans-1)/trans; // rounding up or ceiling
					printf("   Time remaining: %d seconds\n",x);
				}
				sec=trans=0;
			}
		}
		printf("Total time: %d seconds\n\n",time);

		scanf("%d",&n);
	}
}