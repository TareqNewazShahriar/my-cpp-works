#include<stdio.h>
#include<math.h>

void main()
{
//freopen("in08.txt","r",stdin);
	long cs,csn=0, u,v,x,y,uv,xy, sum;
	for(scanf("%ld",&cs);cs;cs--)
	{
		scanf("%ld%ld%ld%ld",&u,&v,&x,&y);
		
		uv=u+v; xy=x+y;
		sum=uv-u;
		sum+=((xy*(xy+1))/2) -(uv*(uv+1))/2;
		if(uv) sum-=uv;
		if(x) sum+=x;
		
		printf("Case %ld: %ld\n",++csn,sum);
		
		/*
		if(uv==0 && xy!=0))
			printf("Case %ld: 1\n",++csn);
		

		if(uv==xy)
			printf("Case %ld: %d\n",++csn,x-u);
		else
		{
			sum=uv-u;
			sum+=((xy*(xy+1))/2) -(uv*(uv+1))/2;
			if(uv) sum-=uv;
			if(x) sum+=x;
			//else  sum+=1;
			printf("Case %ld: %ld\n",++csn,sum);
		}
		*/
}	}	 