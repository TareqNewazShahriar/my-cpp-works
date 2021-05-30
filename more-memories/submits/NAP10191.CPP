#include<stdio.h>
void main()
{	int day=0,sch, sh,sm,eh,em, dm,dh,lm,mm, apph,appm; char app[300];
//freopen("input.txt","r",stdin);
	while(scanf("%d",&sch)!=EOF)
	{    lm=0; dh=10; mm=0; apph=10; appm=0;
		printf("Day #%d: the longest nap starts at ",(++day));
		for(;sch>0;sch--)
		{	scanf("%d:%d %d:%d",&sh,&sm,&eh,&em); gets(app);
			if(mm>sm) dm=(sh-dh-1)*60+60-mm+sm;
			else dm=(sh-dh)*60+sm-mm;
			if(dm>lm) { lm=dm; apph=dh; appm=mm; }
			dh=eh; mm=em;
		} dm=18-eh; if(em>0) { dm--; em=60-em; } dm=dm*60+em;
		if(dm>lm) { lm=dm; apph=dh; appm=mm; }

		printf("%d:%02d and will last for ",apph,appm);
		if(lm<60) printf("%d minutes.\n",lm);
		else printf("%d hours and %d minutes.\n",(lm/60),(lm%60));
}	}//m