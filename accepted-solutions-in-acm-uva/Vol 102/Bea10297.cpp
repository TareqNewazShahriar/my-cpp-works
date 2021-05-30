#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323846
void main()
{	long D,v; float R;
//freopen("input.txt","r",stdin);
	while(scanf("%ld%ld",&D,&v)!=EOF)
	{    if(D==0&&v==0) break;
		R=(float)D/2;
		printf("%.3f\n",(pow( ((3*(PI*R*R*D-v))-2*PI*R*R*R)/(4*PI),(float)1/3)*2) );
}	}//m
		//r=(pow( (((3*(M_PI*R*R*D-v))-(2*M_PI*R*R*R))/4),(float)1/3 ))*2;
		//1   2 345  6       65 5       54  3 3     3    21
		//r=(3*(M_PI*R*R*D-v))-(2*M_PI*R*R*R);
		//r/=4*M_PI;
		//r=pow(r,(float)1/3)*2;

