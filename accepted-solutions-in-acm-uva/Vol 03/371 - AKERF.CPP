#include<stdio.h>
#include<math.h>
unsigned long frq; //long double num;
void akermann(long double n)
{   
	while(n!=1)
	{
		frq++;
		if(fmod(n,2)==0) n/=2;
		else  n=n*3+1;
}	}
void main()/*______________________________________________________________*/
{   
	unsigned long lo,hi,lon,hif;
	while(scanf("%lu%lu",&lo,&hi)!=EOF)
	{
		if(lo==0&&hi==0) break;
		if(lo>hi) { lon=hi; hi=lo; lo=lon; }
		
		printf("Between %lu and %lu, ",lo,hi);
		
		lon=lo; hif=0;
		for(hi++;lo<hi;lo++)
		{
			if(lo!=0)
			{
				if(lo==1) {frq=3;}
				else { frq=0; akermann(lo); }
				if(frq>hif) { hif=frq; lon=lo; }
			}
		}
		printf("%lu generates the longest sequence of %lu values.\n",lon,hif);
			//printf("%.0Lf\n",num);
}	}//m