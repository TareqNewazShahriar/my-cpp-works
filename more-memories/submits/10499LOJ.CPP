#include<stdio.h>
void main()
{//m
	float f;
//freopen("input.txt","r",stdin);
	while(scanf("%f",&f)!=EOF)
	{//w
		if(f>=0)
		{//1i
			if(f==0)   printf("0%%");
			else
			{	f=100/f;
				printf("%.0f%%\n",f);
			}
		}//1i
		else break;
	}//w
}//m