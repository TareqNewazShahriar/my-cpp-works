#include<stdio.h>
#include<math.h>
void main()
{//m
	int  m; float h;
//freopen("input.txt","r",stdin);
	while(scanf("%f:%d",&h,&m)!=EOF)
	{	
		if(h==0.0) break;
		h=fabs( (h*30)+(m*0.5)-(m*6) );
		if(h>180) h=360-h;
		printf("%.3f\n",h);
		
}	}//m