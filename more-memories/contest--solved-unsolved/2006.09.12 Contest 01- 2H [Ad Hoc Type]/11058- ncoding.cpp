#include<stdio.h>
#include<string.h>
#define R 1005
#define T 5
/*---------------------------Global Variables--------------------------*/
/*--------------------------Function Prototypes------------------------*/
/*----------------------------main Function----------------------------*/
void main()
{
//freopen("11058.txt","r",stdin);
	char copy[110],str[110],ch[30][5], x[R][T], y[R][T];
	int cs=0,r,p[R],i,j,len, tmp;

	while(scanf("%s",str)!=EOF)
	{
		strcpy(copy,str);
		for(i=0;i<26;i++) scanf("%s",ch[i]);

		scanf("%d",&r);
		for(i=0;i<r;i++) scanf("%d%s%s",p+i,x[i],y[i]);

		len=strlen(str);
		
		for(i=0;i<len;i++)
		{
			copy[i]=ch[str[i]-97][0];
		}
		
		bool c[110]={0};
		for(i=0;i<r;i++)
		{
			tmp=p[i];
			for(j=tmp;j<len;j++)
			{
				if(x[i][0]==str[j])
				{
					str[j]=y[i][0];
					c[j]=1;
				}
			}
		}
		
		for(i=0;i<len;i++)
		{
			if(c[i]) copy[i]=str[i];
		}
		printf("Case #%d: The encoding string is %s.\n",++cs,copy);

	}
}