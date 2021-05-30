#include<stdio.h>
void main()
{
	//freopen("in08.txt","r",stdin);
	int n,i,x; char g[10];

	scanf("%d",&n);

	while(n)
	{
		char w[11]={0};
		i=0;
		do
		{	x=n;
			scanf("%s%s%d",g,g,&n);
			if(*g=='h')
				{
				if(w[x]&&w[x]!=2) i=1;
				w[x]=2;
				}
			else if(*g=='l')
				{
				if(w[x]&&w[x]!=1) i=1;
				w[x]=1;
				}
		}while(*g!='o');
		
		if(i||w[x]) i=1;
		else
			{
			for(i=10;i;i--)
				if( (w[i]==2&&i<x)||(w[i]==1&&i>x) ) break;
			}
		if(i) puts("Stan is dishonest");
		else  puts("Stan may be honest");
	}
}