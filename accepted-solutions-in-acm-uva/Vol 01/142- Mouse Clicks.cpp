#include<stdio.h>

#define R_SIZE 26
#define I_SIZE 51
#define M_SIZE 3000
/*---------------------------------------------------*/
int icon=1,region=1,click=1, sel[I_SIZE], M[M_SIZE][2], I[I_SIZE][2], R[R_SIZE][4];
/*---------------------------------------------------*/
void click_N_select();
void find_overlapped_icons();
/*---------------------------------------------------*/
void main()
{
//freopen("in07.txt","r",stdin);
	char com[R_SIZE];
	while(scanf("%s",com)==1)
	{
		//tot++;
		if(*com=='I')
		{	scanf("%d%d",&I[icon][0],&I[icon][1]); icon++; }
		else if(*com=='R')
		{	scanf("%d%d%d%d",&R[region][0],&R[region][1],&R[region][2],&R[region][3]); region++; }
		else if(*com=='M')
		{	scanf("%d%d",&M[click][0],&M[click][1]); click++; }
		else break;
	}
	click_N_select();
}	
/*----------------click_N_select()-----------------*/
void click_N_select()
{
	int i,j,select, c1,c2, d,d1,nearer;
	
	find_overlapped_icons();
	for(j=1;j<click;j++)
	{
		select=0;
		c1=M[j][0]; c2=M[j][1];
		for(i=region-1;i;i--)  // check for REGION
		{
			if(R[i][0]<=c1&&c1<=R[i][2] && R[i][1]<=c2&&c2<=R[i][3])
			{	select=i; printf("%c\n",select+64); break; }
		}
		if(select==0) 
		{					// check for ICON
			nearer=500000;		// (499^2)*2 = 498002
			for(i=1;i<icon;i++)
			{
				d=I[i][0]-c1; d1=I[i][1]-c2;
				d=(d*d)+(d1*d1);
				if(d<nearer)
				{	sel[0]=i; select=1; nearer=d; }
				else if(d==nearer)
				{	sel[select]=i; select++; }
			}
			for(i=0;i<select;i++) printf("%3d",sel[i]);
			putchar(10);
		}
	}	
}		
/*--Find the Icons which is overlapped by another Region()--*/
void find_overlapped_icons()
{
	int i,j, i1,i2;
	for(i=icon-1;i;i--)
	{
		i1=I[i][0]; i2=I[i][1];
		for(j=region-1;j;j--)
		{
			if(R[j][0]<=i1&&i1<=R[j][2] && R[j][1]<=i2&&i2<=R[j][3])
			{	I[i][0]=1000; I[i][1]=1000; }
		}
	}	
}		