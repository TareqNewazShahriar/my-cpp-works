#include<stdio.h>
#include<math.h>
void main()
{	char q,c[3000];   int s,d,i, n[3000];//No need to take this large array
//freopen("input.txt","r",stdin);         //of n[3000] index.
	while(scanf("%d%d",&s,&n[0])!=EOF)
	{    q='y';
		for(i=0;i<s;i++)	c[i]=0;
		for(i=1;i<s;i++)
		{ 	scanf("%d",&n[i]);
			if(q=='y')
			{	d=abs(n[i-1]-n[i]);
				if(d>0&&d<s)	c[d]=1;
				else   q='n';
			}//
		}
		if(q=='y')
			for(s--;s>0;s--)
				if(c[s]==0)   q='n';
		if(q=='y')   printf("Jolly\n");
		else	  printf("Not jolly\n");
	}//w
}//m