#include<stdio.h>
#define SIZE 100
/****************************Global Variables***************************/
char a[SIZE],b[SIZE],c[SIZE];
/*************************User Defined Functions************************/
int check_tic_tac_toe(char t)
	{
	int count=0;
	if(a[0]==t&&a[1]==t&&a[2]==t) count++;
	if(b[0]==t&&b[1]==t&&b[2]==t) count++;
	if(c[0]==t&&c[1]==t&&c[2]==t) count++;

	if(a[0]==t&&b[0]==t&&c[0]==t) count++;
	if(a[1]==t&&b[1]==t&&c[1]==t) count++;
	if(a[2]==t&&b[2]==t&&c[2]==t) count++;

	if(a[0]==t&&b[1]==t&&c[2]==t) count++;
	if(a[2]==t&&b[1]==t&&c[0]==t) count++;

	return count;
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("10363.txt","r",stdin);
	int cs,i,tic,tac,u,v;
	
	scanf("%d",&cs);
	for(;cs;cs--)
		{
		scanf("%s%s%s",a,b,c);
		tic=tac=0;
		for(i=0;i<3;i++)
			{
			if(a[i]=='X') tic++;
			else if(a[i]=='O') tac++;
			}
		for(i=0;i<3;i++)
			{
			if(b[i]=='X') tic++;
			else if(b[i]=='O') tac++;
			}
		for(i=0;i<3;i++)
			{
			if(c[i]=='X') tic++;
			else if(c[i]=='O') tac++;
			}		
		i=tic-tac;
		if(i!=1&&i!=0)
			{ puts("no"); continue; }
		
		u=check_tic_tac_toe('X');
		if(u&&tic==tac)  { puts("no"); continue; }
		v=check_tic_tac_toe('O');
		if((u&&v)||v>1||(v&&tic!=tac))
			{ puts("no"); continue; }
		
		//if(u==0&&v==0&&(tic+tac)!=9) { puts("no"); continue; }

		puts("yes");
		}
	}