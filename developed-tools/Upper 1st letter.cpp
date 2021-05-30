#include<stdio.h>
#include<ctype.h>
void main()
{
freopen("F:\\Web\\Acm Related\\Author's Files\\Misc Authors Statistics\\Contestent Name.txt","r",stdin);
freopen("F:\\Web\\Acm Related\\Author's Files\\Misc Authors Statistics\\Contestent Name_.txt","w",stdout);
char str[100];
while(scanf("%s",str)!=EOF)
{
	str[0]=toupper(str[0]);
	printf("%s",str); 
	//str[0]=0;
	scanf("%[ \t\n]",str);
	printf("%s",str);
}}		
