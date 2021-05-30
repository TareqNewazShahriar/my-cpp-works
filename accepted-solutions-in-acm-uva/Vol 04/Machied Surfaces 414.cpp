#include<stdio.h>
#include<string.h>
#define R 12
#define T 25
void main()
{
int n, i,lenspc[R],smallspc, voidspc;
char x[T], spc[T];
//freopen("in4.txt","r",stdin);

scanf("%d",&n);
while(n)
{
	gets(x);
	smallspc=25;
	for(i=0;i<n;i++)
	{
		scanf("%s",x);
		spc[0]=0;
		scanf("%[ ]",spc); 
		if(spc[0])	{	lenspc[i]=strlen(spc); scanf("%s",x);  }
		else lenspc[i]=0;
		if(lenspc[i]<smallspc) smallspc=lenspc[i];
	}
	i=0, voidspc=0;
	while(i<n)
	{
		voidspc+=lenspc[i++]-smallspc;
	}
	printf("%d\n",voidspc);

	scanf("%d",&n);
}
}