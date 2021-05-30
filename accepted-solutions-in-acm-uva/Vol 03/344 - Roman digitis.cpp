#include<stdio.h>
void main()
{
int x,l,c, n, com,k, i[]={0,1,3,6,7,7,8,10,13,14},
	xlist[]={2,14,36,65,75,77,89,111,140,150}, v[]={0,0,0,0,1,2,3,4,5,5};
//freopen("in.txt","r",stdin);
while(scanf("%d",&n))
{	if(n==0) break;
	x=0,l=0,c=0, k=n/10, com=n-k*10;
	/**Calculating X's**/
	if(n>9)
	{
		if(com)
		{
			if(k==4||k==9)
			{	x=com;
			}
			else
				x=(k%5)*com;
			if(com==9)  x++;
		}
		x+=xlist[k-1];
	}
	else if(n==9) x=1;
	/**Evaluating L's**/
	if(n>39) l=n-39;
	{
		if(n>89) l-=n-89;
	}
	/**Enumerating C's**/
	if(n>89) c=n-89;
	printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,(k*14+i[com]),(k*5+v[com]),x,l,c);
}//w
}