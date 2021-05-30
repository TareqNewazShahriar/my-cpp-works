#include<stdio.h>
void main()
{	int cs,a,b,sum,i=0;
//freopen("input.txt","r",stdin);
	scanf("%d",&cs);
	for(;cs>0;cs--)
	{    scanf("%d%d",&a,&b);
		if(a>b) { sum=b; b=a;a=sum; }
		if( (a%2)==0 ) a++; if(b%2!=0) b++;
		for(sum=0;a<b;a+=2) sum+=a;
		printf("Case %d: %d\n",++i,sum);
}	}//m