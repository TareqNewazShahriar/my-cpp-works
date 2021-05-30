// ...3:00pm- 
#include<stdio.h>
#include<string.h>
#define Size 100
typedef int Type;
/****************************Global Variables***************************/
char X[Size],Y[Size],load[Size];
/*************************User Defined Functions************************/
int what_base(char k[])
	{
	char n='1';
	
	for( ; *k; k++)
		if(*k>n) n=*k;

	if(n<58) return n-47;
	return n-54;
	}
/**Convert the val from "from" to 10 base.***/
/**(res_str, base_from, base_to, inputted_string)**It can Handle 0-1,A-Z; 2-36 base**/
int base_conv(char *v,int from)
{	
	int i,j,len_val=strlen(v),unit,power;
	char *s,val[Size];
	strcpy(val,v);

	if(from>10)				// Convert the alpha digits to
		for(s=val;*s;s++)	// decimal digit; e.g. A -> 58
			{
			if(*s>64)
				(*s)-=7;
			}
	for(len_val--,i=0,unit=0;len_val>-1;len_val--,i++) 
	{										// convert 'val' to 10 base
		if(i==0) power=1;
		else for(j=i-1,power=from; j; power*=from,j--);
		
		unit+=(val[len_val]-48)*power;
	}
	return unit;
}	
/*****************************main Function*****************************/
void main()
	{
	//freopen("343.txt","r",stdin);
	Type X10,Y10,bY,bX;
	bool q;
	
	while(scanf("%s%s",X,Y) != -1)
		{
		bX=what_base(X);
		bY=what_base(Y);
		q=0;
		//if(bX<=bY)	{
			Y10=base_conv(Y,bY);
			for(;bX<37;bX++)
				{
				X10=base_conv(X,bX);
				if(X10==Y10) { q=1; break; }
				}
		//	}
		if(q==0)
			{
			X10=base_conv(X,bX);
			for(;bY<37;bY++)
				{
				Y10=base_conv(Y,bY);
				if(X10==Y10) { q=1; break; }
				}
			}
		if(q) printf("%s (base %d) = %s (base %d)\n",X,bX,Y,bY);
		else printf("%s is not equal to %s in any base 2..36\n",X,Y);
		}
	}