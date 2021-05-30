#include<stdio.h>
void main()
{//m
	int cs, b[10], i, f, w;
	unsigned long n, r, d;
//freopen("input.txt","r",stdin);
	while(scanf("%d",&cs)!=EOF)
	{//w
		for(;cs>0;cs--)
		{//1f
			scanf("%lu",&n);
			w=0;
			do
			{//2d
				d=n; i=0; f=0;
				do
				{//d
					if(d<10)
					{//
						b[i++]=d;
						break;
					}//
					b[i++]=d%10;
					d=d/10;
					f++;
				}while(d>0);
				r=b[0];
				for(i=0;i<f;i++)
					r=r*10+b[i+1];
				if(r!=n)
				{//2i
					n+=r;
					w++;
				}//2i
			}while(r!=n);
			printf("%d %lu\n",w,n);
		}//1f
	}//w
}//m