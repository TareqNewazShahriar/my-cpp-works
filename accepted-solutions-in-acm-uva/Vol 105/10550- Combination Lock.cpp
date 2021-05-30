// WA
#include<stdio.h>

void main()
	{
	//freopen("in10550.txt","r",stdin);

	int ini,one,two,three,degree;

	scanf("%d%d%d%d",&ini,&one,&two,&three);

	while(ini!=0||one!=0||two!=0||three!=0)
		{
		degree=ini-one;

		if(degree<0) degree+=40;
		
		if(one<=two) degree+=two-one;
		else	degree+=40-one + two;

		if(two>=three) degree+=two-three;
		else degree+=two + 40-three;

		printf("%d\n",degree*9+1080);

		scanf("%d%d%d%d",&ini,&one,&two,&three);
		}
	}