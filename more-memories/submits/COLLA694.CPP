#include<stdio.h>
#include<math.h>
long frq; long double num=0;
void recurr(long double n)
{    while(n!=1)
	{	if(fmodl(n,2)==0) n/=2; else {n=n*3+1; if(n>num) num=n;}
		frq++;
}	}
void main()
{    long a,trm; double lim; int cs=0;
	while(scanf("%ld%lf",&a,&lim)!=EOF)
	{    if(a<0&&lim<0) break;
		num=0;
		printf("Case %d: A = %ld, limit = %.0lf, ",++cs,a,lim);
		for(lim++;a<lim;a++) if(a!=1&&a!=0)
		{ frq=0; recurr(a); if(frq>trm) trm=frq;  }
		printf("number of terms = %ld\n",trm);
		printf("%.0Lf\n",num);
}	}//m