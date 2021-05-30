#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793

void main()
{
double a1,a2,a3,b1,b2,b3, x,y,tmp;
//freopen("in.txt","r",stdin);

while(scanf("%lf%lf%lf%lf%lf%lf",&a1,&b1,&a2,&b2,&a3,&b3)!=EOF)
{
	y=(a1*a2*a2-a1*a3*a3+a1*b2*b2-a1*b3*b3-a2*a1*a1+a2*a3*a3-a2*b1*b1+a2*b3*b3+a3*a1*a1-a3*a2*a2+a3*b1*b1-a3*b2*b2);
	y/=2*(a1*b2-a1*b3-a2*b1+a2*b3+a3*b1-a3*b2);
	x=a2*a2+b2*b2-a1*a1-b1*b1-2*(b2*y-b1*y);
	tmp=2*(a2-a1);
	if(tmp==0)
	{
		tmp=2*(a3-a1);
		if(tmp)	x=(a3*a3+b3*b3-a1*a1-b1*b1-2*(b3*y-b1*y))/tmp;
		else 
		{
			x=a3*a3+b3*b3-a2*a2-b2*b2-2*(b3*y-b2*y);
			x/=2*(a3-a1);
		}
	}
	else x/=tmp; 
	a3=sqrt((x-a1)*(x-a1)+(y-b1)*(y-b1));
	printf("%.2lf\n",2*PI*a3);
}

}