#include<stdio.h>
#define R 25
/*----------------------------------*/ // multimap vector stack
int n,a,b;
char block[R][R], adrs[R],index[R], freq[R], i,x,y,z,var, m;
/*----------------------------------*/
void move_onto();	void move_over();
void pile_onto();	void pile_over();
void display();
/*----------------------------------*/
void main()
{
//freopen("in02.txt","r",stdin);
char comm[20],ins[20];
while(scanf("%d",&n)!=EOF)
{
	for(i=n-1; i>-1; block[i][0]=i,adrs[i]=i,freq[i]=1,index[i]=0,i--);
	scanf("%s",comm);
	while(comm[0]!='q')
	{	
		scanf("%d %s %d",&a,ins,&b);
		x=adrs[a]; y=adrs[b];
		if(x!=y)
		{	if(comm[0]=='m')
			{
				if(ins[1]=='n') move_onto();
				else move_over();
			}
			else
			{	if(ins[1]=='n') pile_onto();
				else pile_over();
		}	}
		scanf("%s",comm);
	}
	display();
}}//main
void return_stack(short k)
{	
	m=adrs[k]; z=freq[m];
	for(i=index[k]+1;i<z;i++)
	{
		var=block[m][i];
		block[var][0]=adrs[var]=var;
		freq[var]=1; index[var]=0;
	}
}
void move_onto()
{
	return_stack(a); return_stack(b);
	z=index[b];
	block[y][z+1]=a;
	freq[x]=index[a]; freq[y]=z+2;
	index[a]=index[b]+1;
	adrs[a]=y;
}
void move_over()
{	
	return_stack(a);
	block[y][freq[y]++]=a;
	freq[x]=index[a];
	index[a]=freq[y]-1;
	adrs[a]=y;
}
void pile_onto()
{
	return_stack(b);
	z=freq[x];
	freq[x]=index[a];  freq[y]=index[b]+1;
	for(i=index[a];i<z;i++)
	{
		var=block[x][i];
		index[var]=freq[y];
		block[y][freq[y]++]=var;
		adrs[var]=y;
	}
}
void pile_over()
{
	z=freq[x]; freq[x]=index[a];
	for(i=index[a];i<z;i++)
	{
		var=block[x][i];
		index[var]=freq[y];
		block[y][freq[y]++]=var;
		adrs[var]=y;
	}
}
void display()
{	
	for(i=0;i<n;i++)
	{
		printf("%d:",i);
		z=freq[i];
		for(m=0;m<z;m++) printf(" %d",block[i][m]);
		putchar(10);
	}
}		