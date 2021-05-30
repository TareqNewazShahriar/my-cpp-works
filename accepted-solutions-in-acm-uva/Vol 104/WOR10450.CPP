#include<stdio.h>
void main()/*:::::::::::::::::::::::::::::::::::::::::::::*/
{	int cs,c,k,n; double a[2];
//freopen("out.doc","w",stdout);
	scanf("%d",&cs);
	for(c=1,cs++;c<cs;c++)
	{    scanf("%d",&n);//printf("Scenario #1\n");
		if(n==0) printf("1\n");
		else
		{    a[0]=1; a[1]=1;
			for(k=1;n>0;n--)
			{	k=!k; a[k]=a[0]+a[1]; }
			printf("Scenario #%d:\n%.0lf\n\n",c,a[k]);
}	}	}//m