#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<string_animation.h>

#define PATH "C:\\WINDOWS\\SYSTEM\\SVTR.DLL"
#define ALT "C:\\QBPN.inf"
#define R 1000000
#define N 300
#define M 15

/*----------------------------Global Variables----------------------------*/
int x, choice;   FILE *out;
char options[4][M]={"Both","Primes","Seive Primes","BPS"};
//		)#*&     -one of the number code, to see credits each time

/*-------------------------Functions Definitions--------------------------*/
__int64 sto_prim(__int64 n);
__int64 seive_prim(__int64 n);
void data_type(__int64 n);
__int64 input_number();
bool introduction(char p[],char argv[]);
bool file_path(char path[],char argv[]);
void taking_name_and_path(char n[],char sys[]);
void encoding(char n[],char p[],char sys[]);
bool decoding(char n[],char p[],char argv[],char sys[]);
FILE *error_messages(char ins[],FILE *fp,char m,char argv[]);
bool output_file(char path[],char argv[]);
void acknowledgement();

/*-----------------------------Main Function------------------------------*/
void main(int argc,char *argv[])
{
//freopen("in.txt","r",stdin);
/*	
	for(x=0;x<74;putchar(177),x++);
	putchar('\r');
	for(x=0;x<54;putchar(219),x++);
*/	
	__int64 element, tot;
	char path[N];
		
  printf("\n      ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n");
	printf("      º Prime Generating Program º\n");
	printf("      ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n\n\n");
	
	choice=menu_presentation(3,options,M, 1);
	
	element=input_number();
	
	if(introduction(path,argv[0])==0) return;
	
	out=fopen(path,"w");

	printf("\n\n   Progression line...\n");
	for(x=0;x<=77;putchar(177),x++); printf("\r   ");
	
	if(choice==0||choice==1) tot=sto_prim(element);
	if(choice==0||choice==2) tot=seive_prim(element);
	putchar('\n');
	printf("   Total Prime %I64d\n",tot);
	
	acknowledgement();	//	printf(" -%d-\n",x);
	
	fclose(out);
	
	printf("\nPress Any key..."); getch();

} //  :: Main Function ::

/*----- the last munber up to which number,primes will be generated -----*/
__int64 input_number()
{
	__int64 n, i; char ch, num[25]; // __int64 18446744073709551615

	printf("\nThe number, up till the primes will be generated :: ");
	i=0;
	do
	{	ch=getch();
		if(i<20 && ch>47&&ch<58)
			{ putchar(ch); num[i++]=ch; }
		else if(i==20 && ch>47&&ch<58)
			{ printf("%c%c",8,ch); num[20]=ch; }
		else if(ch==8 && i>0)
			{ printf("%c %c",8,8); i--; }
	}while(ch!='\n' && ch!=13);
	num[i]=0;
	
	for(n=0,ch=0; ch<i; n=n*10+(num[ch++]-48) );
/*	
	ch=0; i=n;
	do
	{	comp[ch++]=(i%10)+48; i/=10;
	}while(i);

	comp[ch]=0; strrev(comp);
	ch=strcmp(comp,num);
	if(ch!=0)
	{
		for(i=78; i; i--,printf("%c %c",8,8));
		consecutively_appeared("An Out-Of-Range number! Re-enter :: ",10,0);
	}
*/
	//printf("\n%I64d",n);
	return n;
}
/*------------------------------------------------------------------------*/
bool introduction(char p[],char argv[])
{
	putchar('\n');
	char ch,n[N], sys[]=PATH;
	
	x=strlen(argv)-1;
	for(;argv[x]!='\\';x--);
	argv[x+1]=0;
	for(;(out=fopen(sys,"r"))==0&&sys[0]<91;sys[0]++);
	if(out==0) { strcpy(sys, ALT); out=fopen(sys,"r"); }

	if(out)
	{
		if(decoding(n,p,argv,sys)==0)
		{	out=0; puts("¯ Sorry, saved data was lost! ®"); }
		else
		{
			putchar('\n');
			if(x%2) { cyclic_string(n,22,40); puts(""); }
			else	{ brought_togather(n,15,35); puts(""); }
			
			printf("Re-write in your previous path-\n \"%s\" ?\n[ OK- înter / No- sc] :",p);
			do
			{	ch=getch();
			}while(ch!=10 && ch!=13 && ch!=27); // pressing '\n' or 'esc'
			putchar('\n');  //getchar();  // getch() remains a char to the stdio,
										// so putchar() was used to take it.
			if(ch==27)   // '27'=Esc
			{	
				if(output_file(p,argv)) encoding(n,p,sys); // taking a new file name.
				else	return 0;	// file name problem; user wanted to quit.
			}
			else encoding(n,p,sys);
		}
	}
	if(out==0)
	{	
		if(output_file(p,argv)==0) return 0;
		taking_name_and_path(n,sys);
		x=100; encoding(n,p,sys);
	}
	return 1;
}
/*------------------------------------------------------------------------*/
void taking_name_and_path(char n[],char sys[])
{
	printf("Enter your full name. [Enter a name less than 55 characters] :");
	do
	{	gets(n); x=strlen(n);
		if(*n==0) printf("¯ Enter your full name ® ");
		else if(x>55) printf("¯ Enter a name less than 55 char! ® ");
	}while( *n==0||x>55 );
	
	strcpy(sys, PATH);
	for( ;  (out=fopen(sys,"w"))==0&&sys[0]<91;  sys[0]++);
	if(out==0)
	{	printf("¯ A serious error occurred; No problem, proceed on! ®\n");
		strcpy(sys, ALT); //out=fopen(sys,"w");
	}
}
/*------------------------------------------------------------------------*/
void encoding(char n[],char p[],char sys[])
{
	int i,j; char num[50];
	out=fopen(sys,"w");
	if(sys[3]=='Q')
		fprintf(out,"***Vital code File (don't change)***\n");
//Writing the name
	for(i=0;n[i];i++) fprintf(out,"%c%c",i+40,n[i]-10);
	fprintf(out," \n");
//Writing the path
	for(i=0;p[i];i++)	fprintf(out,"%c%c",i+40,p[i]-10);
	
//Writing the animation turn number (x)
	fprintf(out," \n");
	i=x; j=0;
	do
	{	num[++j]=i%10;
		i/=10;
	}while(i);
	for(;j;--j) fputc(num[j]+M,out);
	// printf(" -%d-\n",x);

	fputc('\n',out); fclose(out);
}		
/*------------------------------------------------------------------------*/
bool decoding(char n[],char p[],char argv[],char sys[])
{
	short i; char ch;
	if(sys[3]=='Q')  fgets(n,N,out);
//Collecting name from file
	i=-1;
	do
	{	i++;
		ch=fscanf(out,"%c%c",&ch,&n[i]);
		n[i]+=10;
	}while(n[i]!=20&&n[i]!=23&&ch!=EOF);
	n[i]=0;
//If DLL file is empty	
	if(ch==EOF) return 0;
//Collecting Path from file	
	for(i=-1,p[0]=0;p[i]!=20&&p[i]!=23;) // p[i]!='\n' !='\r'
	{	i++;
		fscanf(out,"%c%c",&ch,&p[i]);
		p[i]+=10;
	}
	p[i]=0;

	
//	Deconing the animation turn number (x)
	x=0; ch=M;
	do
	{	x=(x*10)+(ch-M);
		ch=fgetc(out);
	}while(ch!='\n');	// printf(" -%d-\n",x);
	x++;

	fclose(out);
	return 1;

}
/*------------------------------------------------*/
bool output_file(char path[],char argv[])
{	
	char outs[N]; bool q=0;
	printf("înter output file Path -\n For example [c:\\my documents\\output.txt] :");
	gets(outs);
	if(*outs==0) { outs[0]='/'; outs[1]=0; }
	else q=file_path(outs,argv);
	out=fopen(outs,"w");
	if(out)
	{	if(q) printf("Output file path was changed by-\n \"%s\".\n",outs); }
	else
	{	out=error_messages(outs,out,'w',argv);
		if(out==0) return 0;
	}
	if(out)
	{	fclose(out); strcpy(path,outs);
		return 1; 
	}
	return 0;
}
/*------------------------------------------------------------------------*/
bool file_path(char path[],char argv[])
{
	short i=strlen(path)-1; 
	char way[N]; bool q=0;

	for( ; i>=0&&path[i]!='\\';i--) //perhaps a folder name contains the '.' char
	{
		if(path[i]=='/'||path[i]=='?'||path[i]=='|'||path[i]=='>'||
			path[i]=='<'||path[i]==':'||path[i]=='"'||path[i]=='*') 
		{	 strcpy(path+i,path+i+1); q=1; }
	}
	for(i++; path[i]&&path[i]!='.'; i++);	
	if(path[i]==0) { strcat(path,".txt"); q=1; }
	else if(path[i+1]==0) { strcat(path,"txt"); q=1; }

	if(path[1]!=':')
	{	q=1; 
		strcpy(way,path);  strcpy(path,argv);
		strcat(path,way);
	}

	return q;
}
/*------------------------------------------------------------------------*/
FILE *error_messages(char ins[],FILE *fp,char m,char argv[])
{
	char ch,mood[5]={m,0}; bool q;
	printf("\nInvalid path. \n");
	do
	{	if(!fp)
		{
			printf("¯ Please reenter the path ® ");
			gets(ins);
			if(*ins==0) { *ins='/'; ins[1]=0; }
			else q=file_path(ins,argv);
			fp=fopen(ins,mood);
			//fclose(in);
		}
		if(!fp)
		{
			printf("¯ Invalid path. Quit? [Press înter/sc]? :");
			do
			{	ch=getch();
			}while(ch!=10 && ch!=13 && ch!=27);
			putchar(10);
			if(ch!=27) return 0;
		}		
	}while(!fp);
	if(q) printf("Output file path was changed by-\n \"%s\".\n",ins);
	return fp;
}
/*---------------Load Primes in a array(*ar,untill_num)-----------------*/
/*----------If out of n then i<n, else if up to n then s<n-----------*/
__int64 sto_prim(__int64 n)
{
	__int64 s=0,sq, i,j, brk=0,pro=1,k,per;
	
	data_type(n);
	n++; s=1;
	fprintf(out,"prime[]={2");
		
	choice ? per=74 : per=36;
	putchar(219);
	for(i=3;i<n;i+=2)
	{
		sq=(__int64)sqrtl((long double)i)+1;
		for(j=3;j<sq;j+=2)
		{
			if(i%j==0) break;
		}
		if(j>=sq)
		{
			fprintf(out,",%I64d",i);	//	printf("\r%I64d",i);
			brk++; s++;
			if(brk==120) { fputc('\n',out); brk=0; }
		}
		for(k=(per*i)/n;pro<=k;pro++) putchar(219);
	}
	for(;pro<=per;pro++) putchar(219);
	fprintf(out,"};\n//total prime %I64d\n",s);
	
	return s;
}
/*----Load Primes in a array untill index n by Sieve Algorithm(array_name, untill_n)----*/
/*------------- prime=0, non-prime=1 --------------*/
__int64 seive_prim(__int64 n)
{
	__int64 i,j,brk=0,tot=0,pro=1,k;	bool prim[R]={1,1};

	choice ? k=24,putchar(219) : k=12;
	putchar(219);

	n++;
	const int per=(int)k;
	for(i=4;i<n;prim[i]=1,i+=2) 
	{
		for(k=(per*i)/n;pro<=k;pro++) putchar(219);
	}
	for(;pro<=per;pro++) putchar(219);

	for(i=3,pro=0;i<n;i+=2)
	{	if(*(prim+i)==0)
			for(j=i+i;j<n;*(prim+j)=1,j+=i);
		for(k=(per*i)/n;pro<=k;pro++) putchar(219);
	}
	for(;pro<=per;pro++) putchar(219);
	fprintf(out,"bool prm[]={1");

	for(i=1,pro=0;i<n;i++)
	{
		brk++;
		if(prim[i]==0) tot++;
		fprintf(out,",%d",prim[i]);
		if(brk==400) {  fputc('\n',out); brk=0; }

		for(k=(per*i)/n;pro<k;pro++) putchar(219);
	}
	for(;pro<per;pro++) putchar(219);
	fprintf(out,"};\n//total prime %I64d.  0=Prime, 1=Composite.\n",tot);
	return tot;
}
/*------------------------------------------------------------------------*/
void data_type(__int64 n)
{
	if(n<2) fprintf(out,"bool ");
	else if(n<128) fprintf(out,"char ");
	else if(n<32768) fprintf(out,"int ");
	else if(n<65536) fprintf(out,"unsigned int ");
	else if(n<2147483648) fprintf(out,"long ");
	else	fprintf(out,"__int64 ");
}
/*------------------------------------------------------------------------*/
void acknowledgement()
{
	char ch;
	printf("\nCredit¨ [înter/sc] :");
	do
	{	ch=getch();
	}while(ch!=10 && ch!=13 && ch!=27);
	putchar(10);
	if(ch=='\r'||ch=='\n')
	{
		char marque[]="Programmed By TarIQ Newaz Shahriar              \
               It was tried to make the program error free. If any error is observed, feel free to mail.";
		puts("");
		marque_string(marque);  //de-comment later
		puts("");
				
		spreding_string("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿",25,8);
		           puts(""); sleep(50);
		         printf("\t³ Porgrammed By Tareq Newaz Shahriar ³\n"); sleep(50);
		 marging_string("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´",25,8);
		           puts(""); sleep(50);
		         printf("\t³   Email: protariqcs at hotmail.com ³\n"); sleep(50);
		         printf("\t³          tariq.info at gmail.com   ³\n"); sleep(50);
		marging_string("ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍµ",25,8);
		           puts(""); sleep(50);
				 printf("\t³       May Peace Be Upon You        ³\n");
		 marging_string("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ",25,8);
		           puts("");
	}	
}