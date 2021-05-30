#include<stdio.h>
void main()
{	char alp[26],s[20],q; int i;
	alp[0]=0;alp[1]=1;alp[2]=2;alp[3]=3;alp[4]=0;alp[5]=1;alp[6]=2;
	alp[7]=0;alp[8]=0;alp[9]=2;alp[10]=2;alp[11]=4;alp[12]=5;
	alp[13]=5;alp[14]=0;alp[15]=1;alp[16]=2;alp[17]=6;alp[18]=2;
	alp[19]=3;alp[20]=0;alp[21]=1;alp[22]=0;alp[23]=2;alp[24]=0;
	alp[25]=2;
//freopen("input.txt","r",stdin);
	while(gets(s))
	{    for(q=0,i=0;s[i]!=0;i++)
		{	if(alp[s[i]-65]!=0&&q!=s[i]&&alp[s[i]-65]!=alp[q-65])
				 printf("%d",alp[s[i]-65]);
			q=s[i];
		}
		printf("\n");
}	}//m
