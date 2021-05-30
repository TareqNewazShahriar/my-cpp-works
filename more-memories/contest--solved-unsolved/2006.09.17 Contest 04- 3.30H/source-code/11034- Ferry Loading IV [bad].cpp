#include<stdio.h>
#define R 10
/*---------------------------Global Variables--------------------------*/
/*++++++++++++++++++++++++User Defined Functions+++++++++++++++++++++++*/
/*----------------------------main Function----------------------------*/
void main()
	{
	freopen("11034.txt","r",stdin);
	int cs,len,m,i, arrive,left,right,count;
	char lside[R],rside[R],q;
	scanf("%d",&cs);
	for(;cs;cs--)
		{
		scanf("%d%d",&len,&m);
		len*=100; // may be a float 
		lside[0]=rside[0]=q=1;
		count=-1; i=0;
		while(i<m)
			{
			if(q)
				{
				q=0; count++;
				if(lside[0]=='l') arrive=left;
				else arrive=0;
				for(;arrive+left<=len&&lside[0]=='l';i++)
					{
					scanf("%d%s",&left,lside);
					arrive+=left;
					}
				if(lside[0]=='r') { right=left; lside[0]=0; }
				}
			else
				{
				q=1; count++;
				if(rside[0]=='r') arrive=right;
				else arrive=0;
				for(;arrive+right<=len&&rside[0]=='r';i++)
					{
					scanf("%d%s",&right,rside);
					arrive+=right;
					}
				if(rside[0]=='r') { left=right; rside[0]=0; }
				}
			}//for i
		printf("%d\n",count);
		}// for cs
	}// main