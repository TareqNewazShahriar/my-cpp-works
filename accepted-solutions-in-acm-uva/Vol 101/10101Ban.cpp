#include<stdio.h>
#include<string.h>
void main()
{	char num[16]; int cs=1,i,n,len;
//freopen("input.txt","r",stdin);
	while(scanf("%s",num)!=EOF)
	{    if(cs<10) printf("   %d.",cs++);
		else if(cs<100) printf("  %d.",cs++);
		else if(cs<1000) printf(" %d.",cs++);
		else printf("%d.",cs++);
		len=strlen(num);
		for(i=0,len;len>2;i++,len--)
		{    if(len==3||len==10)
			{ 	if(num[i]!=48) printf(" %c shata",num[i]); }
			else if(len==12||len==5)
			{	n=((num[i]-48)*10)+(num[i+1]-48); i++;
				if(n!=0) printf(" %d hazar",n); len--;
			}
			else if(len==11||len==4)
			{	if(num[i]!=48) printf(" %c hazar",num[i]); }
			else if(len==14||len==7)
			{	n=(num[i]-48)*10+(num[i+1]-48); i++;
				if(n!=0) printf(" %d lakh",n); len--;
			}
			else if(len==13||len==6)
			{	if(num[i]!=48) printf(" %c lakh",num[i]);  }
			else if(len==15||len==8)
			{	if(num[i]!=48) printf(" %c",num[i]);
				printf(" kuti");
			}
			else
			{	n=((num[i]-48)*10)+(num[i+1]-48); i++;
				if(n!=0) printf(" %d",n);
				printf(" kuti");  len--;
			}
		}
		if(len==2)
		{	n=((num[i]-48)*10)+(num[i+1]-48);
			if(n!=0) printf(" %d",n);
		}
		else printf(" %c",num[0]);
		printf("\n");
}	}//m