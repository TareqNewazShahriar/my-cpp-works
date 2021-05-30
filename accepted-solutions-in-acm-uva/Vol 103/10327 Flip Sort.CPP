#include <stdio.h>
void main()
{	int in, i, ar[1000], tmp, c;
	long int sw;
	char q;
//freopen("input.txt","r",stdin);
	while(scanf("%d",&in)!=EOF)
	{//w
		sw=0;
		for(i=0;i<in;i++)
		{
			scanf("%d",&ar[i]);
		}
		for(in=in-1;in>0;in=in-c)
		{// 3f
			q='n';
			for(i=0;i<in;i++)
			{// 2f
				if(ar[i]>ar[i+1])
				{// 1if
					tmp=ar[i];
					ar[i]=ar[i+1];
					ar[i+1]=tmp;
					c=in-i;
					sw++;
					q='y';
				}// 1if

			}// 2f
			if(q=='n')
				break;
		}// 3f
		printf("Minimum exchange operations : %ld\n",sw);
	}//w
}// main