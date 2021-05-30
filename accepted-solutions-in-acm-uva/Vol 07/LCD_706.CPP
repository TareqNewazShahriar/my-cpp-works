#include<stdio.h>
#include<string.h>
#define T 5
#define X 10
char s[9],*n[X][T]={{" - ","| |","   ","| |"," - "},
	{"   ","  |","   ","  |","   "},{" - ","  |"," - ","|  "," - "},
	{" - ","  |"," - ","  |"," - "},{"   ","| |"," - ","  |","   "},
	{" - ","|  "," - ","  |"," - "},{" - ","|  "," - ","| |"," - "},
	{" - ","  |","   ","  |","   "},{" - ","| |"," - ","| |"," - "},
	{" - ","| |"," - ","  |"," - "}};
int a,j,len,i,k;

void display(void);
void print(void);

void main()
{
//freopen("input.txt","r",stdin);
//freopen("out.txt","w",stdout);
	while(scanf("%d",&a)!=EOF)
	{	
		scanf("%s",s);
		if(a==0&&s[0]==48&&s[1]==0) {break;}
		len=strlen(s);
		for(i=0;i<5;i++)
		{
			if(i==0||i==2||i==4) print();
			else display();
		}
		printf("\n");
}	}//m

void print(void)
{    
	for(j=0;j<len;j++)
	{
		printf("%c",n[s[j]-48][i][0]); // 124 = '|'   45 = '-'
		for(k=a;k>0;k--)
			printf("%c",n[s[j]-48][i][1]);
		printf("%c",n[s[j]-48][i][2]);
		if(j!=len-1)printf(" ");
	} 
	printf("\n");
}
void display(void)
{   
	int x;
	for(x=a;x>0;x--)
	{
		for(j=0;j<len;j++)
		{
			printf("%c",n[s[j]-48][i][0]); // 124 = '|'   45 = '-'
			for(k=a;k>0;k--)
				printf("%c",n[s[j]-48][i][1]);
			printf("%c",n[s[j]-48][i][2]);
			if(j!=len-1)printf(" ");
		} 
		printf("\n");
	}
}