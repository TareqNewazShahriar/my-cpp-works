#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<string_animation.h>
#define N 350
#define PATH "C:\\WINDOWS\\SYSTEM\\SVTR.DLL"
#define ALT "C:\\QBPN.inf"
/*------------------------------------------------*/
FILE *out; int credit; char num[10];
/*------------------------------------------------*/
bool decoding(char n[],char p[],char sys[]);
void encoding(char n[],char p[],char sys[]);
/*-----------------------------------------------*/
/*-----------------------------------------------*/
void main(int argc, char *argv[])
{
	char n[N],p[N], sys[]=PATH, tmp[N];
	
	for( ;(out=fopen(sys,"r"))==0&&sys[0]<91;sys[0]++);
	if(out==0) { strcpy(sys,ALT); out=fopen(sys,"r"); }
	if(out)
	{
		if(decoding(n,p,sys)==1)
			{
			consecutively_appeared("Sorry, May be the Prime Gen. program was forcefully closed before.\nSaved data was lost! and you Buddy, are respponsible for that.",10,0);
			printf("\n\nPress any key..."); getch();
			return;
			}
		else 
			{
			printf("Current Name: %s",n);
			//string_brushing(n,10,5);
			puts("");
			}
		 
		printf("\nType A New Name (or press Enter to cancel) :");
		do
		{	gets(tmp);
			
			credit=strlen(tmp);
			if(credit>55) consecutively_appeared("Enter a name <55 char! :",10,1);

		}while( *n==0||credit>55 );
		
		if(credit>0) strcpy(n,tmp);

		encoding(n,p,sys);
		
		puts("");
		if(credit==0) 
			 consecutively_appeared("Previous Name Was Restored.",10,0);
		else consecutively_appeared("Name Was Changed.",10,0);
		puts("");
	}
	else puts("\nHey, perhaps you wouldn't run the Prime Generating Program yet.\n");

	printf("\nPress any key..."); getch();
	
}
/*-----------------------------------------------*/
void encoding(char n[],char p[],char sys[])
{
	short i;
	out=fopen(sys,"w");
	if(sys[3]=='Q')
		fprintf(out,"***Vital code File(don't change)***\n");
	//Writing the name
	for(i=0;n[i];i++) fprintf(out,"%c%c",i+40,n[i]-10);
	fprintf(out," \n");
	//Writing the path & credit
	fprintf(out,"%s%s",p,num);

	fclose(out);
}		
/*-----------------------------------------------*/
bool decoding(char n[],char p[],char sys[])
{
	if(sys[3]=='Q')  fgets(n,N,out);
//Decoding the name
	short i; char ch;
	i=-1;
	do
	{	i++;
		ch=fscanf(out,"%c%c",&ch,&n[i]);
		n[i]+=10;
	}while(n[i]!=20&&n[i]!=23&&ch!=EOF);
	n[i]=0;
//If DLL file is empty	
	if(ch==EOF) return 0;
//Just collecting Path and credit code
	fgets(p,N,out);
	fgets(num,N,out);
	fclose(out);
	return 1;
}	