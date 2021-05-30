#include<stdio.h>
#define SIZE 200005
typedef int Type;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*****************************main Function*****************************/
void main()
	{
	freopen("b.TXT","r",stdin);
	
	Type cs=0,n,i,x,y,sum,half,total, R[SIZE], *a,*z, tmp, *r=R+1;
	char act[10];

	scanf("%d",&n);
	while(n)
		{
		half=n/2+1;
		a=r;
		z=r+n;
		x=n/10;
		total=0;
		for(i=0;i<x;a+=10,i++)
			{
			scanf("%d%d%d%d%d%d%d%d%d%d",a,a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,a+9);
			total+= *a+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9];
			}
		for(;a<z;a++)
			{
			scanf("%d",a);
			total+= *a;
			}

		printf("Case %d:\n",++cs);
		scanf("%s",act);
		while(*act!='E')
			{
			scanf("%d%d",&x,&y);
			if(*act=='S')
				{
				tmp=R[x];
				R[x]=y;
				tmp=y-tmp;
				total+=tmp;
				}
			else
				{
				if( (y-x)<=half )
					{
					a=R+x;  z=R+y+1;
					for(sum=0; a<z; sum+=*a,a++);
						
					printf("%d\n",sum);
					}
				else
					{
					a=r; z=R+x;
					sum=0;
					for( ; a<z; sum+= *a++);
					a=R+y+1; z=R+n+1;
					for( ; a<z; sum+= *a++);
					printf("%d\n",total-sum);
					}
				}

			scanf("%s",act);
			}
		puts("");
		scanf("%d",&n);
		}
	}