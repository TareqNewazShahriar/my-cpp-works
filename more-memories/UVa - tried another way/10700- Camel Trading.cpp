#include<stdio.h>
#define R 25
/*----------------------Global Variables---------------------*/
int i,n, num[R], *v, k;
char *e, exp[R];
long double max,min,tmp[R];
/*---------------------------Function------------------------*/
void minimum();
/*------------------------Main Function----------------------*/
void main()
{		
//freopen("in02.txt","r",stdin);
	for(scanf("%d",&n);n;n--)
	{	
		e=exp; v=num;
		scanf("%d%c",v,e);   //scanf("%d%[ \t]%c",v,e,e);
		*tmp= *v; k=0;
		while(*e!=10)
		{	
			if(*e=='+')  // max  3+11+4*1*13*12*8+3*3+8
			{
				v++, e++;
				scanf("%d%c",v,e);
				tmp[k]+= *v;
			}
			else
			{
				v++, e++;
				scanf("%d%c",v,e);
				tmp[++k]= *v;
			}			
		}	
		max=tmp[0];	
		for(i=1;i<=k;i++) max*=tmp[i];
		
		minimum();
		
		printf("The maximum and minimum are %.0Lf and %.0Lf.\n",max,min);
	}
}//end of main
/*---------------------------Function------------------------*/
void minimum()
{		
	v=num; e=exp;
	k=0; *tmp= *v;
		
	while(*e!=10)
	{	i++;
		if(*e=='*')  // max		3+11+4*1*13*12*8+3*3+8
		{
			v++, e++;
			tmp[k]*= *v;
			//tmpe[k]=*e;
		}
		else
		{
			v++, e++;
			tmp[++k]= *v;
			//tmpe[k++]=*e;
		}
	}	
	min=tmp[0];
	for(i=1;i<=k;i++) min+=tmp[i];
}		