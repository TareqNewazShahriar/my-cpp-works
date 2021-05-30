#include<stdio.h>
#include<math.h>
int josephus(int n);
void main()
{//m
	int cs,k=0,i,j,n,sur,lp;
//freopen("input.txt","r",stdin);
	scanf("%d",&cs);
	for(;cs>0;cs--)
	{	scanf("%d",&n); lp=-1;
		do{	sur=n;lp++;
			n=josephus(n);
		}while(sur!=n);
		printf("Case %d: %d %d\n",++k,lp,sur);
	}
}//m
int josephus(int man)
{	int i,j;
	j=log10(man)/log10(3); j=pow(3,j);
	//for(i=man,j=1;i>1;i/=2) j*=2;
	man=(man-j)*2+1; return man;//*/
}