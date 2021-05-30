#include<stdio.h>
#define R 20
#define K 100
/*---------------------------Global Variables--------------------------*/
/*--------------------------Function Prototypes------------------------*/
/*----------------------------main Function----------------------------*/
void main()
{
//freopen("11059.txt","r",stdin);
	int n,i,s[R],q,cs=0, hlow,neg,index;
	//__int64 multi; /*
	long long multi; //*/

	while(scanf("%d",&n)!=EOF)
	{
		q=neg=0; hlow= -K;

		for(i=0;i<n;i++)
		{
			scanf("%d",s+i);
			if(s[i]<0)
			{
				neg++;
				//if(s[i]!=-1) m*=s[i];
			}
			//else if(s[i]>0) q=1;
			
			if(s[i]<0&&s[i]>hlow)
			{
				hlow=s[i];
				index=i;
			}
		}

		if(n==1&&s[0]<0) multi=0;
		else
		{
			multi=1;
			if(neg%2==1) s[index]=1;
			for(i=0;i<n;i++) multi*=s[i];
		}

		//printf("Case #%d: The maximum product is %I64d.\n",++cs,multi);  /*
		printf("Case #%d: The maximum product is %lld.\n",++cs,multi); //*/	
	}
}