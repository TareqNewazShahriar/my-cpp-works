#include<stdio.h>
void main()
{	char q='n';  int cs,a, b, i, j;
//freopen("input.txt","r",stdin);
//freopen("scan.txt","w",stdout);
	scanf("%d",&cs);
	for(;cs>0;cs--)
	{	scanf("%d%d",&a,&b);  a++;
		for(;b>0;b--)
		{    for(i=1;i<a;i++)
			{    for(j=0;j<i;j++)    printf("%d",i);
				printf("\n");
			}//3f
			for(i-=2;i>0;i--)
			{	for(j=0;j<i;j++) printf("%d",i);
				printf("\n");
			}
			if(cs!=1||b!=1) printf("\n");
		}//2f
	}//1f
}//m