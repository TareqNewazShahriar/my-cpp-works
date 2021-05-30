#include<stdio.h>
#include<string.h>
void main()
{//m
	char cn[2000][25], q, con[73];
	int c[2000], cs, r=0, i, j;
	//int *ptr=new int[100];
	//delete ptr;
//freopen("input.txt","r",stdin);
	while(scanf("%d",&cs)!=EOF)
	{//w
		c[0]=0;
		for(i=0;i<cs;i++)
		{//1f
			scanf("%s",cn[i]);
			gets(con);
			q=0;
			for(j=0;j<=r;j++)
			{//2f
				if(strcmp(cn[i],cn[j])==0)
				{// 1 if s
					c[j]++;
					q=1;
					break;
				}// 1 if e
			}// for e
			if(q==0)
			{// 2 if s
				r++;
				c[r]=0;
				strcpy(cn[r],cn[i]);
				c[r]++;
			}// 2 if e
		}//1f
	do
	{//2d
		q='n';
		for(i=0;i<=r;i++)
		{//2f
			if(cn[i][0]!='\0')
			{//4i
				q='y';
				strcpy(con,cn[i]);
				cs=i;
				for(j=0;j<=r;j++)
				{//3f
					if(cn[j][0]!='\0')
						if(strcmp(con,cn[j])>0)
						{//3i
								strcpy(con,cn[j]);
								cs=j;
						}//3i
				}//3f
				printf("%s %d\n",cn[cs],c[cs]);
				cn[cs][0]='\0';
			}//4i
		}//2f
	}while(q=='y');
	}//w
}//m