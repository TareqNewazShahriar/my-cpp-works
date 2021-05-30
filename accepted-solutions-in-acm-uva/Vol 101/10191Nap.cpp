#include<stdio.h>
#define R 100
void selection_sort(int sh[],int sm[],int eh[],int em[],int n);
void main()
{	int i,day=0,sch, sh[R],sm[R],eh[R],em[R], dm,dh,lm,mm, apph,appm; char app[300];
							// start hour,minutes, end hour,minutes; appointment hour,minutes; 
//freopen("in3.txt","r",stdin);
while(scanf("%d",&sch)!=EOF)
{   lm=0; dh=10; mm=0; apph=10; appm=0;
	printf("Day #%d: the longest nap starts at ",(++day));
	for(i=0;i<sch;i++)
	{	scanf("%d:%d %d:%d",&sh[i],&sm[i],&eh[i],&em[i]); gets(app);  }
	selection_sort(sh,sm,eh,em,sch);
	for(i=0;i<sch;i++)
	{
		if(mm>sm[i]) dm=(sh[i]-dh-1)*60+60-mm+sm[i];
		else dm=(sh[i]-dh)*60+sm[i]-mm;
		if(dm>lm) { lm=dm; apph=dh; appm=mm; }
		dh=eh[i]; mm=em[i];
	}
	i=sch-1;
	dm=18-eh[i]; 
	if(em[i]>0) { dm--; em[i]=60-em[i]; }
	dm=dm*60+em[i];
	if(dm>lm)
	{ lm=dm; apph=dh; appm=mm; }

	printf("%d:%02d and will last for ",apph,appm);
	if(lm<60) printf("%d minutes.\n",lm);
	else printf("%d hours and %d minutes.\n",(lm/60),(lm%60));
}	}//m
/*-------------------Selection sort(int_array,element)--------------------*/
void selection_sort(int sh[],int sm[],int eh[],int em[],int n)
{   int i,j, m=n-1, lowh,lowm,indx,tmp;
	for(i=0;i<m;i++)
	{   lowh=sh[i],lowm=sm[i], indx=i;
		for(j=i+1;j<n;j++)
		{ 	if(sh[j]<lowh) { lowh=sh[j]; lowm=sm[j]; indx=j; }
			else if(sh[j]==lowh)
			{
				if(sm[j]<lowm) { lowm=sm[j]; indx=j; }
			}
		}//inner loop
		if(i!=indx)
			{
			tmp=sh[i],sh[i]=sh[indx],sh[indx]=tmp;
			tmp=sm[i],sm[i]=sm[indx],sm[indx]=tmp;
			tmp=eh[i],eh[i]=eh[indx],eh[indx]=tmp;
			tmp=em[i],em[i]=em[indx],em[indx]=tmp;
			}
	}
}
/*
Every endless night has a dawning day
Every darkest sky has a shining ray
And it shines on you baby can't you see
You're the only one who can shine for me

It's a private emotion that fills you tonight
And a silence falls between us
As the shadows steal the light
And wherever you may find it
Wherever it may lead
Let your private emotion come to me
Come to me

When your soul is tired
and your heart is weak
Do you think of love
as a one way street
Well it runs both ways,
open up your eyes
Can't you see me here,
how can you deny

It's a private emotion that fills you tonight...

Every endless night has a dawning day
Every darkest sky has a shining ray
It takes a lot to laugh as your tears go by
But you can find me here
till your tears run dry
It's a private emotion that fills you tonight... */