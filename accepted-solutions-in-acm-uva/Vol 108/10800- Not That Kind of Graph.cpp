#include<stdio.h>
#define R 51
/*---------------------------Global Variables--------------------------*/
/*--------------------------Function Prototypes------------------------*/
/*----------------------------main Function----------------------------*/
void main()
{
//freopen("10800.txt","r",stdin);
//freopen("10800OUT.txt","w",stdout);
	int test,cs=0,i,x,high,rec, row[R];
	char g[R],d[R], line[R];
	for(scanf("%d",&test);test;test--)
	{
		scanf("%s",g);

		x=high=rec=0;

		for(i=0;g[i];i++)
		{
			if(g[i]=='R')
			{
				if(i>0&&g[i-1]=='R')
				{
					if(high==rec) high++;
					rec++;
				}
				row[i]=rec;
				d[i]='/';
			}
			else if(g[i]=='C')
			{
				if(i>0&&g[i-1]=='R')
				{
					if(high==rec) high++;
					rec++;
				}
				row[i]=rec;
				d[i]='_';
			}
			else if(g[i]=='F')
			{
				if(i>0&&g[i-1]!='R')
					rec--;
				if(rec<0)
				{
					for(x=0;x<i;x++) row[x]++;
					high++; rec=0;
				}
				row[i]=rec;
				d[i]='\\';
			}
		}// for i ; str length
		printf("Case #%d:\n",++cs);
		for(;high>=0;high--) // display
		{
			rec=0;
			printf("| ");
			for(x=0;x<i;x++)
			{
				if(high==row[x])
				{
					line[x]=d[x];
					rec=x;
				}
				else line[x]=' ';
			}
			line[rec+1]=0;
			puts(line);
		}
		printf("+-");
		for(x=0;x<i;x++) putchar('-');
		puts("-\n");
	}// for test
}//End of main