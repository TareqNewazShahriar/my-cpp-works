#include<stdio.h>
#define A 20
void main()
{	int m,n,k,i,j, count, travel;
	char circle[A];
//freopen("in3.txt","r",stdin);
	scanf("%d%d%d",&n,&k,&m);
	while(k!=0 || m!=0 || n!=0)
	{	for(i=1; i<=n; circle[i]=i,i++);
		i=0; j=n+1; count=n;
		while(count!=0)
		{
			travel=0;
 			while(travel!=k)
			{	if(i==n) i=0;	i++; 
				if(circle[i]) travel++;
			}
			printf("%3d",i);
			travel=0;/**/ count--;
		
			while(travel!=m)
			{	j--; 
				if(j==0) j=n;
				if(circle[j]) travel++;
			}
			if(i!=j) 
			{	printf("%3d",j);  circle[j]=0;
				count--;
			}
			circle[i]=0;
			if(count) putchar(',');
		}// count while
		putchar(10);
		scanf("%d%d%d",&n,&k,&m);
	}//entry while
}//main	