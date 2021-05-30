#include<stdio.h>
#include<string.h>
#define R 300
void main()/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
{	int i,k,len; char a[R],x[R];
//freopen("input.txt","r",stdin);
	while(gets(a))
	{   
		len=strlen(a); k=0;
		if(a[0]>47&&a[0]<58)
		{	
			for(len--;len>-1;len--)
			{
				i=((a[len]-48)*10)+a[--len]-48;
				if(i<23) i=i*10+(a[--len]-48);  x[k++]=i;
			}
			x[k]=0; printf("%s\n",x);
		}
		else
		{   
			for(len--;len>-1;len--)
			{
				i=a[len];
				while(i>9)
				{ 
					printf("%d",i%10); 
					i/=10;
				}
				printf("%d",i);
			}
			printf("\n");
		}
	}
}//m