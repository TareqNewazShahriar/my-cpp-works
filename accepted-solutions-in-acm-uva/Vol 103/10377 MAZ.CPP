#include<stdio.h>
void main()
{//m
	char mz[60][60], cm, d, q='n';
	int cs, c, r;
//freopen("input.txt","r",stdin);
	while(scanf("%d",&cs)!=EOF)
	{//w
		for(;cs>0;cs--)
		{//1f
			scanf("%d%d",&r,&c);
			scanf("%c",&cm);
			for(c=0;c<r;c++)
					gets(mz[c]);	//printf("%d %s",c,mz[c]);
			d='N';
			scanf("%d%d",&r,&c);
			r--; c--;
			if(q=='y')
				printf("\n");
			q='y';
			do
			{//d
				scanf("%c",&cm);
				if(cm=='R' || cm=='L')
				{//2i
					if(d=='N')
						if(cm=='R')
							d='E';
						else
							d='W';
					else if(d=='E')
						if(cm=='R')
							d='S';
						else
							d='N';
					else if(d=='S')
						if(cm=='R')
							d='W';
						else
									d='E';
					else
						if(cm=='R')
							d='N';
						else
							d='S';
					}//2i
				else if(cm=='F')
				{//1ei
					if(d=='N')
					{//3i
						if(mz[r-1][c]==' ')
							r--;
					}//3i
					else if(d=='E')
					{//2ei
						if(mz[r][c+1]==' ')
							c++;
					}//2ei
					else if(d=='S')
						{//3ei
						if(mz[r+1][c]==' ')
							r++;
					}//3ei
					else
					{//1e
						if(mz[r][c-1]==' ')
							c--;
					}//1e
				}//1ei
			}while(cm!='Q');
			printf("%d %d %c\n",(r+1),(c+1),d);
		}//1f
	}//w
}//m