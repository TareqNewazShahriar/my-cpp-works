#include<stdio.h>
#include<string.h>
#define index 1001

/*------------Division of String and integer(des str,str,num,len)----------*/
int sn_dev(char *m,int len)
{   int i=0,j=0; long dev=0;
	while(dev<11&&j<len) 
	{	dev=dev*10; dev+=(*(m+j))-48; j++; }
	do
	{ 
		while(dev<11&&j<len)
		{	dev=dev*10; 
			dev+=(*(m+j))-48; j++;
			//if(dev<11&&j<len) 
			//	*(r+i++)=48;
		} 
		//*(r+i++)=dev/11+48; 
		dev%=11;
	}while(j<len); 
	//*(r+i)=0;  
	if(dev)	return 0;
	return 1;
}
void main()
{
	char instr[index];
//freopen("contest.txt","r",stdin);
	while(gets(instr))
	{	if(instr[0]==48&&instr[1]==0) break;
		fputs(instr,stdout);
		if(sn_dev(instr,strlen(instr)) )
			puts(" is a multiple of 11.");	
		else puts(" is not a multiple of 11.");
	}
}