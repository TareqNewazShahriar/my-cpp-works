//Bismillahir Rohmanir Rohim
//Not That Kind of Graph
//9:34 AM 7/27/2006
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char g[200][200];
void main()
	{
	//SubhanALLOH SubhanALLOH SubhanALLOH
	bool flg=0;
	int ii,i,l,n,r[200],mxr,mnr,cs=1;
	char s[60];
freopen("10800.txt","r",stdin);
freopen("10800 not out.txt","w",stdout);
	scanf("%d",&n);
	while(n--)
		{
		scanf("%s",s);
		l=strlen(s);
		fill(r,r+180,0);
		for(ii=0;ii<180;ii++) fill(g[ii],g[ii]+180,0);
		i=mxr=mnr=100;
		switch(s[0])
			{
			case 'R': g[i][0]='/'; break;
			case 'C': g[i][0]='_'; break;
			case 'F': g[i][0]='\\';break;
			}
		for(ii=1;ii<l;ii++)
			{
			switch(s[ii])
				{
				case 'R'://raise
					{
					if(s[ii-1]=='R') i++;
					g[i][ii]='/';
					r[i]=ii;
					break;
					}
				case 'C'://const
					{
					if(s[ii-1]=='R') i++;
					//else if(s[ii-1]=='F') i--;
					g[i][ii]='_';
					r[i]=ii;
					break;
					}
				case 'F'://fall
					{
					if(s[ii-1]!='R') i--;
					g[i][ii]='\\';
					r[i]=ii;
					break;
					}
				}
			if(i>mxr) mxr=i;
			if(i<mnr) mnr=i;
			}
		flg?putchar(10):flg=1;
		printf("Case #%d:\n",cs++);
		for(ii=mxr;ii>=mnr;ii--)
			{
			printf("| ");
			for(i=0;i<=r[ii];i++)
				{
				if(g[ii][i]) printf("%c",g[ii][i]);//putchar(g[i][ii]);
				else putchar(32);
				}
			putchar(10);
			}
		printf("+--");
		for(i=0;i<l;i++) putchar('-');
		putchar(10);
		}
	putchar(10);
	}
//pause 9:40 -10:28 AM 7/27/2006, 11:45 - 12:16 AM 7/27/2006 ,1:00 PM -2:11 PM 7/27/2006
//10:21 AM 7/27/2006 
//AlhamduLILLAH AlhamduLILLAH AlhamduLILLAH#include<stdio.h>
