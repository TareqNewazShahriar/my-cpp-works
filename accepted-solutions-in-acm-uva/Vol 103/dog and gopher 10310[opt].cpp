#include<stdio.h>
#define R 50
void main()
{	
int n,i; char str[R];
float gx,gy,dx,dy, x,y,  p,q,r,s;
//freopen("G:\\Programming\\Problems Coding\\Submit\\Submitted, But\\in.txt","r",stdin);
while(scanf("%d",&n)!=EOF)
{	
	scanf("%f%f%f%f",&gx,&gy,&dx,&dy);
	for(i=0;i<n;i++)
	{
		scanf("%f%f",&x,&y);
		/*
		if( 4*((x-gx)*(x-gx)+(y-gy)*(y-gy)) <= ( (x-dx)*(x-dx)+(y-dy)*(y-dy) ) )
		{	printf("The gopher can escape through the hole at (%.3f,%.3f).\n",x,y);
			break;
		}
		/*/
		p=x-gx, q=y-gy,   r=x-dx, s=y-dy;
		if(4*(p*p + q*q)<=(r*r + s*s))
		{	printf("The gopher can escape through the hole at (%.3f,%.3f).\n",x,y);
			break;
		}
		//*/
	}
	if(i==n) puts("The gopher cannot escape.");
	else if(i+1!=n) 
		while(i<n) i++, gets(str);
}	
}	
