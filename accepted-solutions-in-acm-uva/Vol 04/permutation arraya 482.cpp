#include<stdio.h>
#include<string.h>
#define R 10000
#define T 100000
#define S 20
void main()
{
char q=0,fl[R][S], str[T];
int perm,i=0,k,cs;
//freopen("G:\\Programming\\Problems Coding\\ACM Problems Coding\\in2.txt","r",stdin);
scanf("%d",&cs);
while(cs)
{	if(q) putchar(10); q=1;
	gets(str); gets(str);  //taking blank lines

	gets(str);//taking input
	for(i=0,perm=0,k=1;str[i];i++)
	{
		if(str[i]>47&&str[i]<58)   perm=perm*10+str[i]-48;
		else if(perm)  {	scanf("%s",fl[perm]); k++;  perm=0;  }
	}
	if(perm) {  scanf("%s",fl[perm]); k++;  }

	for(i=1;i<k;i++)  puts(fl[i]);
	cs--;
}//w

}//main