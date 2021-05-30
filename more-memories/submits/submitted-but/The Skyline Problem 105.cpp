#include<stdio.h>
#define R 5001
/*----------Global Variable----------*/
int a,z, left[R],right[R],height[R], j,out[R];
/*-----------------------------------*/
void out_line();
/*----------Main function------------*/
void main()
{
int i=0,tot,k;
while(scanf("%d%d%d",&left[i],&height[i],&right[i])==3)
	i++;
tot=i; k=right[0]; a=0;
for(i=0;i<tot;t++)
{
	if(k<left[i]) 
	{
		z=i;
		out_line();
		a=i+1; k=right[i];
	}
	else k=right[i];
}
}
void out_line()
{
	int i,k,tall; out[j++]=left[a];
	for(i=a;i<=z;i++)
	{
		if(left[i]==left[i+1])
		{	tall=0;
			while(left[i]==left[i+1])
				if(height[i]>tall) tall=height[i];
			out[j++]=tall;
		}
		if(height[i]<height[i+1])
		{
			out[]
		}
	}
}