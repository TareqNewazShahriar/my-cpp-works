#include<stdio.h>
#include<string.h>
#include<algorithm>
#define WORD 101
#define WLETTER 22
#define SIZE 85
#define MAX 128

using namespace std;

typedef int Type;
/****************************Global Variables***************************/
Type n;
char word[WORD][WLETTER];
const int K=WORD;
/*************************User Defined Functions************************/
int comp(const char *a, const char *b)
{
	return strcmp(a,b);
}

void assign_char_value(bool strmat[K][MAX])
	{
	Type i;
	char *ch;
	for(i=0;i<n;i++)
		{
		for(ch=word[i]; *ch; ch++)
			{
			strmat[i][*ch]=1;
			}
		}
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("inE.txt","r",stdin);
	Type i,j,x, pch,nch;
	char ch,c, *t,*tmp, term[SIZE], posit[SIZE], negat[SIZE];
	
	scanf("%s",word[0]);
	while(word[0][0]!='#')
		{
		for(i=1;word[i-1][0]!='*';i++) scanf("%s",word[i]);
		n=i-1;
		qsort((void *)word,n,sizeof(word[0]),( int (*)(const void *,const void *))comp);

		//*(int *)&K=n+1;
		bool strmat[K][MAX]={0};
		assign_char_value(strmat);

		gets(term);
		scanf("%[\n]",term);
		scanf("%[*]",term);
		while(*term!='*')
			{
			x=5000; ch=0;
			while(ch!='\n')
				{
				scanf("%[a-z*+-]%c",term,&ch);
				pch=nch=0;
				for(t=term;*t>96&&*t<123;t++);
				tmp=t;
				for( ; *t; t++)
					{
					if(*t=='+') posit[pch++]=*(++t);
					else negat[nch++]=*(++t);
					}
				*tmp=0;
				for(i=0;i<n;i++)
					{
					for(t=term; *t; t++)
						{
						if(strmat[i][*t]==1)
							{
							for(j=0;j<pch;j++)
								if(strmat[i][posit[j]]==0) break;
							if(j<pch) break;
							
							for(j=0;j<nch;j++)
								if(strmat[i][negat[j]]==1) break;
							if(j<nch) break;

							if(x>i) { x=i; i=n; break; }
							}
						}
					}
				}//while(ch!='\n');
			if(x==5000) puts("NONE");
			else puts(word[x]);
			scanf("%[*]",term);
			} // while(*term!='*')
		puts("$");

		scanf("%s",word[0]);
		}
	}