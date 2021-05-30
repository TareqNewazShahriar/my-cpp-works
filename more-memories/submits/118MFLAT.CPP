#include<stdio.h>
void main()
{//m
	char cm, d, q, n[101], x[51],y[51];
	int  rr,cc, c,r;
//freopen("input.txt","r",stdin);
	scanf("%d%d",&rr,&cc);
	for(r=0; r<=rr||r<=cc; r++)  {  x[r]='a'; y[r]='a'; }
	while(scanf("%d%d%c%c%c",&r,&c,&d,&d,&cm)!=EOF)
	{    q='n';
		do{
			scanf("%c",&cm);
			if(cm=='R' || cm=='L')
			{//2i
				if(d=='N')
					if(cm=='R')  d='E';
					else	 d='W';
				else if(d=='E')
					if(cm=='R')  d='S';
					else	 d='N';
				else if(d=='S')
					if(cm=='R')  d='W';
					else	 d='E';
				else
					if(cm=='R')   d='N';
					else	 d='S';
			}//2i
			else if(cm=='F')
			{//1ei
				if(d=='N')
				{	if(c+1<=cc)  c++;
					else
					{	if(x[r]!=r&&y[c]!=c)
							{   q='L'; gets(n); }
					}
				}//3i
				else if(d=='E')
				{	if(r+1<=rr)   r++;
					else
					{	if(x[r]!=r&&y[c]!=c)
							{   q='L'; gets(n); }
					}
				}//2ei
				else if(d=='S')
				{	if(c-1>=0)	  c--;
					else
					{	if(x[r]!=r&&y[c]!=c)
							{   q='L'; gets(n); }
					}
				}//3ei
				else
				{	if(r-1>=0)   r--;
					else
					{	if(x[r]!=r&&y[c]!=c)
							{   q='L'; gets(n); }
					}
				}//1e
			}//1ei
		}while(cm!='\n' && q!='L');
		x[r]=r; y[c]=c;
		if(q=='L')  printf("%d %d %c LOST\n",r,c,d);
		else   printf("%d %d %c\n",r,c,d);
	}//w
}//m