#include<stdio.h>
#define R 1000
lovecalc(char name[]);
void main()
{
//freopen("F:\\Programming\\Problems Coding\\pACM Problems Coding\\in03.txt","r",stdin);
	int a,b; char m[R],n[R];
	while(gets(m))
	{
		gets(n);
		a=lovecalc(m); b=lovecalc(n);

		if(a<b) printf("%.2f %%\n",((float)a/b)*100);
		else printf("%.2f %%\n",((float)b/a)*100);
	}
}
/*----------------------------*/
lovecalc(char name[])
{
	short i,sum=0,val;
	for(i=0;name[i];i++)
	{
		if((val=name[i])>64 && val<91)
			sum+=val-64;
		else if(val>96 && val<123)
			sum+=val-96;
	}
	while(sum>9)
	{
		val=0;
		while(sum)
		{
			val+=sum%10; sum/=10;
		}
		sum=val;
	}
	return sum;
}