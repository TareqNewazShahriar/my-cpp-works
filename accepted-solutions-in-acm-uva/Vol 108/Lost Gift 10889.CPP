#include<stdio.h>
#include<math.h>
void main()
{   	double red,b, blk, per; long x,y; char q;
//freopen("input.txt","r",stdin);
	while(scanf("%lf%lf",&red,&b)!=EOF)
	{    if(red==0&&b==0) break;
		blk=(1+2*red-sqrt(8*red+1))/2;  q=0;
		if(blk==floor(blk))
		{   
			per=(b*100)/blk;
			if(per>=70&&per<=100) { x=blk-b; q=1; }
			
			blk=(1+2*red+sqrt(8*red+1))/2;
			per=(b*100)/blk;
			
			if(per>=70&&per<=100) { y=blk-b; q+=2; }
			
			if(q==0) printf("No. of black balls invalid\n");
			else if(q==1) printf("%ld\n",x);
			else if(q==2) printf("%ld\n",y);
			else 
				{
				if(x<y) printf("%ld %ld\n",x,y);
				else printf("%ld %ld\n",y,x);	   
				}
		}
		else printf("No. of red balls invalid\n");
}	}//m