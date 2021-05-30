#include <stdio.h>
void main()
{
	int cs, fr;
	double sum;
	long int fy, tn, ef;
	scanf("%d",&cs);
	for(;cs>0;cs--)
	{// for
		sum=0.0;
		scanf("%d",&fr);
		for(;fr>0;fr--)
		{
			scanf("%ld%ld%ld",&fy,&tn,&ef);
			sum=sum+((double(fy)) * (double(ef)) );
		}
		printf("%.0lf\n",sum);
	}//for
}
