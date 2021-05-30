#include<stdio.h>
#define R 20000
void main()
{
//freopen("in01.txt","r",stdin);
//freopen("out01.doc","w",stdout);
static int seq[R][2], pve[R], nve[R], n=1,num, i, tmp;
while(scanf("%d",&num)!=EOF)
{
	if(num>0)
	{	if(pve[num]) { seq[pve[num]][1]++; }
		else { pve[num]=n; seq[n][0]=num; seq[n++][1]++; }
	}
	else
	{	num=-num;
		if(nve[num]) { seq[nve[num]][1]++; }
		else  { nve[num]=n; seq[n][0]=-num; seq[n++][1]++; }
	}
}//while
for(i=1; i<n; printf("%d %d\n",seq[i][0],seq[i][1]),i++);
}//main