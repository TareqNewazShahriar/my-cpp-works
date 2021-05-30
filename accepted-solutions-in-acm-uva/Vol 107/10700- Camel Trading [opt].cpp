#include<stdio.h>
#define R 25
/*----------------------Global Variables---------------------*/
int i,n, num[R], *v;
char *e, exp[R];
long double max,min,tmp[R], *t;
/*---------------------------Function------------------------*/
void minimum();
/*------------------------Main Function----------------------*/
void main()
{		
//freopen("in02.txt","r",stdin);
	for(scanf("%d",&n);n;n--)
	{	
		e=exp; v=num; t=tmp;
		scanf("%d%c",v,e);   //scanf("%d%[ \t]%c",v,e,e);
		*t= *v;
		while(*e!=10)
		{	
			if(*e==43)// 43 '+'  // max  3+11+4*1*13*12*8+3*3+8
			{
				v++, e++;
				scanf("%d%c",v,e);
				(*t)+= *v;
			}
			else
			{
				v++, e++;
				scanf("%d%c",v,e);
				*(++t)= *v;
			}			
		}	
		i=t-tmp;
		t=tmp+1;
		for(max=*tmp;i;i--,t++) max*=(*t);
		
		minimum();
		
		printf("The maximum and minimum are %.0Lf and %.0Lf.\n",max,min);
	}
}//end of main
/*---------------------------Function------------------------*/
void minimum()
{		
	v=num; e=exp; t=tmp;
	*t= *v;
		
	while(*e!=10)
	{	i++;
		if(*e==42)// 42 '*'	// max		3+11+4*1*13*12*8+3*3+8
		{
			v++, e++;
			(*t)*= *v;
			//tmpe[k]=*e;
		}
		else
		{
			v++, e++;
			*(++t)= *v;
			//tmpe[k++]=*e;
		}
	}	
	i=t-tmp;
	t=tmp+1;
	for(min=*tmp;i;i--,t++) min+=(*t);
}		