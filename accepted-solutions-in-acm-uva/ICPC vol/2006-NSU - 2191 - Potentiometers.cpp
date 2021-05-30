#include<stdio.h>
#define SIZE 200005
#define P 100
typedef int Type;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*****************************main Function*****************************/
void main()
	{
	//freopen("b.txt","r",stdin);
	
	Type cs=0,n,k,i,x,y,u,v,sum,total[SIZE/P+5]={0}, R[SIZE], *a,*z, tmp, *ini=R+1;
	char act[10],q=0;

	scanf("%d",&n);
	while(n)
		{
		if(q) putchar('\n'); q=1;
		a=ini;
		z=ini+n;
		x=n-(n%10);
		sum=0;
		k=1;
		if(x)
			{
			//scanf("%d%d%d%d%d%d%d%d%d%d",a,a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,a+9);
			//sum+= *a+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9];
			//a+=10;
			for(i=0;i<x;a+=10,i+=10)
				{
				scanf("%d%d%d%d%d%d%d%d%d%d",a,a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,a+9);
				sum+= *a+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9];
				if(i%P==90)
					{	total[k++]=sum; sum=0; }
				}
			}
		
		for(i++;a<z;a++,i++)
			{
			scanf("%d",a);
			sum+= *a;
			if(i%P==0)
				{	total[k++]=sum; sum=0; }
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
				if(x%P==0) k=x/P;
				else k=(x/P)+1;
				total[k]+=tmp;
				}
			else if(x/P==y/P)
				{
				a=R+x;  z=R+y+1;
				for(sum=0; a<z; sum+=*a,a++);
				printf("%d\n",sum);
				}
			else
				{
				k=x%P;
				if(k==0) { u=x/P+1; z=R+x+1; }
				if(k==1) { u=x/P+1; z=0x000; }
				else { u=(x/P)+2; z=R+((u-1)*100)+1; }
				v=y/P;

				a=R+x;
				sum=0;
				for(;a<z;sum+=*a,a++);
				for(i=u;i<=v;i++) sum+=total[i];
				
				a=R+(v*100)+1; z=R+y+1;
				for( ; a<z; sum+=*a,a++);
				
				printf("%d\n",sum);
				}

			scanf("%s",act);
			}
		scanf("%d",&n);
		}
	}