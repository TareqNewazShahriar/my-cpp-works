#include<stdio.h>
#include<math.h>
void main()
{
double x,y,z,s;
while(scanf("%lf%lf%lf",&x,&y,&z)!=EOF)
{
	s=(x+y+z)/2;
	if(s) s=sqrt(s*(s-x)*(s-y)*(s-z))/s;
	printf("%.3lf\n",s);
}}		
