#include<stdio.h>
#include<math.h>
#define R 20
/*--------------------------------------------------*/
void west(); void north();
void east(); void south();
/*--------------------------------------------------*/
int n; char d,top,dval,temp, m[10],tmp,
		pos[][R]={"0",{3,2,4,5,3,2,4,5},{3,6,4,1,3,6,4,1},{6,2,1,5,6,2,1,5},
					{1,2,6,5,1,2,6,5},{3,4,6,3,1,4,6,3},{2,3,5,4,2,3,5,4}},
		loc[][R]={"0",{0,0,5,4,2,3,0},{0,3,0,4,2,0,5},{0,2,1,0,0,3,4},
						{0,4,5,0,0,3,2},{0,4,0,3,5,0,2},{0,0,4,5,3,2,0}};
//void (*run_it[122])(void);  //functions must be pre-defined
/*--------------------------------------------------*/
void main()
{
//freopen("in02.txt","r",stdin);
//	(*run_it['w'])=west; (*run_it['n'])=north; 
//	(*run_it['e'])=east; (*run_it['s'])=south;
	while(scanf("%d",&n)&&n)
	{
		top=1; dval=3; d='w';
		for(;n;n--)
		{
			scanf("%s",m);
			temp=loc[top][dval];
			//(*run_it[*m])();
			switch(*m)
			{
				case 'w': west(); break;
				case 'n': north(); break;
				case 'e': east(); break;
				case 's': south(); break;
			}
		}
		printf("%d\n",top);
	}
}
void west()
{
	tmp=dval; dval=top;
	if(d=='w') top=7-tmp;
	else if(d=='n') top=pos[top][temp+1];
	else if(d=='e') top=tmp;
	else top=pos[top][temp-1];
	d='w';
}
void east()
{
	tmp=dval; dval=top;
	if(d=='w') top=tmp;
	else if (d=='n') top=pos[top][temp-1];
	else if(d=='e') top=7-tmp;
	else top=top=pos[top][temp+1];
	d='e';
}
void north() // OK
{
	tmp=dval; dval=top;
	if(d=='w') top=pos[top][temp-1];
	else if(d=='n') top=7-tmp;
	else if (d=='e') top=pos[top][temp+1];	
	else top=tmp;
	d='n';
}
void south()
{
	tmp=dval; dval=top;
	if(d=='w') top=pos[top][temp+1];
	else if (d=='n') top=tmp;
	else if(d=='e') top=pos[top][temp-1];
	else top=7-tmp;
	d='s';
}	