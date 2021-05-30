#include<stdio.h>
#include<string.h>
#include<math.h>
#define R 50  //9999999999(10)[10 digit] ==>> 1001010100000010111110001111111111(2)[34 digit]
/**Convert the alpha chars to number ASCII equivalent (num_string)**e.g. A -> 58 **/
void int_equival(char *s)
{
	int i;
	for(i=0;*(s+i);i++)
	{
		if(*(s+i)>64 && *(s+i)<71)
			*(s+i)-=7;
}	}
/******Make the num in ASCII equivalent******/
void ASCII_equiv(char *s)
{
	int i;
	for(i=0;*(s+i);i++)
	{
		if(*(s+i)>57)
			*(s+i)+=7;
}	}
/**Convert the val from "from" to "to".||Require equival(), ascii_equiv()***/
/*******(str_value, base_from, base_to, stored_string)*******/
int base_conv(char *val,int from,int to,char *load)
{	int i,digi,len_val=strlen(val);
	//char ten[R];
	if(from>10)
		int_equival(val);
	for(len_val--,i=0,digi=0;len_val>-1;len_val--,i++)
	{
		digi+= (val[len_val]-48)*pow(from,i);
	}
	i=0;
	while(digi)/*converting the value to the dest. base*/
	{
		*(load+ i++)=digi%to +48;
		digi=digi/to;
	}
	if(i==0) *(load+ i++)=48;
	*(load+i)=0;
	if(to>10)
		ASCII_equiv(load);
	return i;
}
/*-----------------------Reverse(str,len)---------------------*/
void rev(char *s,int j)
{   int i=0;  char tmp;
	for(j--;i<j;i++,j--) { tmp=*(s+i); *(s+i)=*(s+j); *(s+j)=tmp; }
}

void main()//[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]
{
//freopen("in.txt","r",stdin);
	int from,to;
	char nums[R],conv[R];
	while(scanf("%s%d%d",&nums,&from,&to)==3)
	{
		from=base_conv(nums,from,to,conv);
		//_itoa(nums,conv,to);
		if(from<8)
		{
			rev(conv,from);
			printf("%7s\n",conv);
		}
		else	{	puts("  ERROR");  }
}	}