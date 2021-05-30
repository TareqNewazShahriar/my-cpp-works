#include<stdio.h>
#include<math.h>
/*---------------------------------------------*/
/*---------------------------------------------*/
void main()
{
//freopen("in03.txt","r",stdin);
	long n, u,v,c, u2,v2; bool i;
	scanf("%ld",&n);
	while(n)
	{
		u=sqrt(n); i=u%2; u2=u*u; v=u+1;
		if(u2==n)
		{
			if(i) printf("1 %ld\n",u);
			else  printf("%ld 1\n",u);
		}
	/*	else if(u2+1==n)
		{
			if(i) printf("1 %ld\n",v);
			else  printf("%ld 1\n",v);
		}
	*/
		else
		{	v2=v*v; c=v2-v+1;
			//if(c==n) printf("%ld %ld\n",v,v);
			if(i)
			{	
				if(n<c)  printf("%ld %ld\n",n-u2,v);
				else	 printf("%ld %ld\n",v,v2-n+1);
			}
			else
			{	
				if(n<c)  printf("%ld %ld\n",v,n-u2);
				else	 printf("%ld %ld\n",v2-n+1,v);
			}
		}
		scanf("%ld",&n);
}	}	