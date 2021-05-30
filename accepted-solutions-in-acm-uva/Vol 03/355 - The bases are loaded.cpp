#include<stdio.h>
#include<string.h>
#include<math.h>
#define R 50
/*-----------------------Reverse(str,len)---------------------*/
void rev(char *s,int j)
{    int i=0;  char tmp;
	for(j--;i<j;i++,j--) { tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }
}
/**Convert the alpha chars to number ASCII equivalent (num_string)**e.g. A -> 58 **/
void num_equiv(char *s,int &base)
{
	int i;
	for(i=0;*(s+i);i++)
	{
		if(*(s+i)>64 && *(s+i)<71)
			*(s+i)-=7;
		//cheak base validity
		if( (s[i]-48)>=base )
		{	base=-1;	return;
		}
	}
	
}
/******Make the num in ASCII equivalent******/
void ASCII_equiv(char *s)
{
	int i;
	for(i=0;*(s+i);i++)
	{
		if(*(s+i)>57)
			*(s+i)+=7;
}	}
/**Convert the val from "from" to "to".||Require- num_equiv(), ASCII_equiv(),rev()***/
/**(res_str, base_from, base_to, inputted_string)**It can Handle 0-1,A-Z; 2-36 base**/
int base_conv(char *val,int from,int to,char *load)
{	int i,len_val=strlen(val);
	double digi;
	//char ten[R];
	num_equiv(val,from);
	
	if(from==-1) return -1;
	
	for(len_val--,i=0,digi=0;len_val>-1;len_val--,i++)
	{
		digi+= (val[len_val]-48)*pow(from,i);
	}//1099511627775
	i=0;
	while(digi)
	{
		*(load+ i++)=fmod(digi,to) +48;
		digi=floor(digi/to);
	}
	if(i==0) *(load+ i++)=48;
	*(load+i)=0;
	if(to>10)  ASCII_equiv(load);
	rev(load,i);
	return i;
}	
void main()
{
int v,from,to;
char num[R];

while(scanf("%d%d%s",&from,&to,num)!=EOF)
{
	printf("%s ",num);
	v=base_conv(num,from,to,num);
	if(v==-1) printf("is an illegal base %d number\n",from);
	else printf("base %d = %s base %d\n",from,num,to);
}
}