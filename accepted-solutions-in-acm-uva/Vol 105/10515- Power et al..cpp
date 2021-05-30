#include<stdio.h>
#include<string.h>
#define SIZE 105
/****************************Global Variables***************************/
char n[SIZE],p[SIZE];
/*************************User Defined Functions************************/
int power_y_of_x() //perameter: char n[],char p[]
	{
	if(p[0]=='0'&&p[1]==0) return 1;
	
	int num,power,res;	
	
	num=strlen(n);
	power=strlen(p);
	
	if(num>1) num=(n[num-2]-48)*10+ n[num-1]-48;
	else  num=n[0]-48;
	
	if(power>1) power=(p[power-2]-48)*10+p[power-1]-48;
	else  power=p[0]-48;
	
	power%=4;
	if(power==0) power=4;
	for(res=num; power>1; res*=num,power--);
	
	return (res%10);
	}
/*****************************main Function*****************************/
void main()
	{
	scanf("%s%s",n,p);
	while( n[0]!='0' || p[0]!='0')
		{
		printf("%d\n",power_y_of_x());

		scanf("%s%s",n,p);
		}
	}