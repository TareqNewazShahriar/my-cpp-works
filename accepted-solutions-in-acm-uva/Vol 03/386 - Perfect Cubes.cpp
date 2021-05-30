#include<stdio.h>
void main()
{
	int i,j,k,l;
	//unsigned long a,b,c,d;
	//unsigned __int64 a,b,c,d;
	long a,b,c,d;
	//double a,b,c,d;
	for(i=6;i<201;i++)
	{	a=i*i*i;
		for(j=2;j<i;j++)
		{	b=j*j*j;
			for(k=j;k<i;k++)
			{	c=k*k*k;
				if(a<b+c) 
					break;
				for(l=k;l<i;l++)
				{	d=l*l*l;
					if(a<b+c+d) break;
					if(a==b+c+d) printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
				}
			}	
		}
	}
}