#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<string_animation.h>
/*	  )#*&     -one of the number code to see credit each time	 */
#define PATH "C:\\WINDOWS\\SYSTEM\\SVTR.DLL"
#define ALT "C:\\QBPN.inf"
#define R 1000000
#define N 300
#define M 33
/*------------------------------------------------------------------------*/
FILE *out; int credit; char choice; // __int64 18446744073709551615
/*------------------------------------------------------------------------*/
void sto_prim(__int64 n);
void seive_prim(__int64 n);
void data_type(__int64 n);
bool introduction(char p[],char argv[]);
bool file_path(char path[],char argv[]);
void taking_neme__path(char n[],char sys[]);
void encoding(char n[],char p[],char sys[]);
bool decoding(char n[],char p[],char argv[],char sys[]);
char presentation();
char press();
char move_cursor(char &c);
FILE *error_messages(char ins[],FILE *fp,char m,char argv[]);
bool output_file(char path[],char argv[]);
void acknowledgement();
void marque_text(char marque[],short j,short speed);
void left_right_collide(char text[],short speed);
void cyclic_text(char text[],short speed);
/*------------------------------------------------------------------------*/
void main(int argc,char *argv[])
{
//freopen("in.txt","r",stdin);
	char path[N];  __int64 element;

	choice=presentation();
	printf("Last number :");
	scanf("%I64d",&element); gets(path); // taking extra characters

	if(introduction(path,argv[0])==0) return;
	
	out=fopen(path,"w");

	printf("\n\n   Progression line...\n   ÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝ\r   ");
	if(choice==0||choice==1) sto_prim(element);
	if(choice==0||choice==2) seive_prim(element);
	putchar(10);
	
	if(credit%4==0)
		acknowledgement();
	fclose(out);
//	printf(" -%d-\n",credit);
	printf("\nPress the \"Any\" key..."); getch();
}
/*------------------------------------------------------------------------*/
bool introduction(char p[],char argv[])
{
	char ch,n[N], sys[]=PATH;

	credit=strlen(argv)-1;
	for(;argv[credit]!='\\';credit--); 
	argv[credit+1]=0;
	for(;(out=fopen(sys,"r"))==0&&sys[0]<91;sys[0]++);
	if(out==0) { strcpy(sys, ALT); out=fopen(sys,"r"); }

	if(out)
	{
		if(decoding(n,p,argv,sys)==0)
		{	out=0; puts("¯ Sorry, saved data was lost! ®"); }
		else
		{
			putchar(10);
			if(credit%2) cyclic_text(n,30);
			else	 left_right_collide(n,20);
			printf("Write in your previous path-\n \"%s\" ?\n[ OK- înter / No- sc] :",p);
			do
			{	ch=getch();
			}while(ch!=10 && ch!=13 && ch!=27);
			putchar(10);  //getchar(); // getch() remains a char to the stdio

			if(ch==27)
			{	
				if(output_file(p,argv)) encoding(n,p,sys);				
				else	return 0;
			}
			else encoding(n,p,sys);
		}
	}
	if(out==0)
	{	
		if(output_file(p,argv)==0) return 0;
		taking_neme__path(n,sys);
		credit=8292;   encoding(n,p,sys);
	}
	return 1;
}
/*------------------------------------------------------------------------*/
void taking_neme__path(char n[],char sys[])
{
	printf("Enter your full name. [You can't change this name leter] :");
	do
	{	gets(n); credit=strlen(n);
		if(*n==0) printf("¯ Enter your full name ® :");
		else if(credit>55) printf("¯ Enter a name < 55 char! ® :");
	}while( *n==0||credit>55 );
	
	strcpy(sys, PATH);
	for(;(out=fopen(sys,"w"))==0&&sys[0]<91;sys[0]++);
	if(out==0)
	{	printf("¯ A serious error occurred; No problem, proceed on! ®\n");
		strcpy(sys, ALT); //out=fopen(sys,"w");
	}
}
/*------------------------------------------------------------------------*/
void encoding(char n[],char p[],char sys[])
{
	int i; char j,num[10];
	out=fopen(sys,"w");
	if(sys[3]=='Q')
		fprintf(out,"***Vital code's File(don't change)***\n");
//Writing the name
	for(i=0;n[i];i++) fprintf(out,"%c%c",i+40,n[i]-10);
	fprintf(out," \n");
//Writing the path
	for(i=0;p[i];i++)	fprintf(out,"%c%c",i+40,p[i]-10);
//Writing the credit number
	fprintf(out," \n");
	i=credit; j=0;
	do
	{	num[++j]=i%10;
		i/=10;
	}while(i);
	for(;j;--j) fputc(num[j]+M,out);
	fputc('\n',out); fclose(out); // printf(" -%d-\n",credit);
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
//If DLL file is empty	
	if(ch==EOF) return 0;
//Collecting Path from file
	n[i]=0;
	for(i=-1,p[0]=0;p[i]!=20&&p[i]!=23;) // p[i]!='\n' !='\r'
	{	i++;
		fscanf(out,"%c%c",&ch,&p[i]);
		p[i]+=10;
	}
	p[i]=credit=0; ch=M;
//Collecting the credit count
	do
	{	credit=(credit*10)+(ch-M);
		ch=fgetc(out);
	}while(ch!='\n');
	// printf(" -%d-\n",credit);
	credit++;
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
char presentation()
{
	char a,c=0;

  printf("\n              ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n");
	printf("              º Prime Generating Program º\n");
	printf("              ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n\n\n");
	do
	{	if(c==0)
		{	printf("\r\t[ ]BOTH   []Primes   []Seive Prime\r"); printf("\t["); }
		else if(c==1)
		{	printf("\r\t[]Both   [ ]PRIMES   []Seive Prime\r"); printf("\t[]Both   ["); }
		else
		{	printf("\r\t[]Both   []Primes   [ ]SEIVE PRIME\r");
			printf("\r\t[]Both   []Primes   [");
		}
		a=move_cursor(c);
	}while(a!=10);

	if(c==0)
		printf("\r\t[û]BOTH   []Primes   []Seive Prime\n");
	else if(c==1)
		printf("\r\t[]Both   [û]PRIMES   []Seive Prime\n");
	else
		printf("\r\t[]Both   []Primes   [û]SEIVE PRIME\n");

	return c;
}
/*--------------------------------------------*/
char move_cursor(char &c)
{
	char a;
	do
	{	a=press();
		if(a=='p'||a=='P') { c=1; return 10; }
		else if(a=='s'||a=='S') { c=2; return 10; }
		else if(a=='B'||a=='b') { c=0; return 10; }
		else if(a==' '||a=='\r'||a=='\n') return 10;
		else if(a=='\t'||a=='K')
		{
			if(c==0)
			{	if(a=='\t') c=1;
				else if(a=='K') c=2;
			}
			else if(c==1)
			{	if(a=='\t') c=2;
				else if(a=='K') c=0;
			}
			else
			{	if(a=='\t') c=0;
				else if(a=='K') c=1;
			}
		}
	}while(a!='\t'&&a!='K');
	return c;
}
/*------------------------------------------------------------------------*/
char press()
{
	char a,b;
	a=getch();
	if(a==0||a==-32)
	{
		b=getch();
		if(b=='H'||b=='M') a='\t';
		else if(b=='K'||b=='P'||b==15) a='K';
	}
	return a;
}
/*------------------------------------------------------------------------*/
FILE *error_messages(char ins[],FILE *fp,char m,char argv[])
{
	char ch,mood[5]={m,0}; bool q;
	printf("\nInvalid path. \n");
	do
	{	if(!fp)
		{
			printf("¯ Please reenter the path ® :");
			gets(ins);
			if(*ins==0) { *ins='/'; ins[1]=0; }
			else q=file_path(ins,argv);
			fp=fopen(ins,mood);
			//fclose(in);
		}
		if(!fp)
		{
			printf("It seems that you forgot the file path.\nQuit? [Press înter/sc]? :");
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
void sto_prim(__int64 n)
{
	__int64 s=0,sq, i,j, brk=0,pro=1,k,per;
	
	if(n<2) fprintf(out,"bool prime[]={");
	else
	{
		n++; data_type(n); s=1;
		fprintf(out,"prime[]={2");
	}	
	choice ? per=73 : per=36;
	putchar('');
	for(i=3;i<n;i+=2)
	{
		sq=sqrtl(i)+1;
		for(j=3;j<sq;j+=2)
		{
			if(i%j==0) break;
		}
		if(j>=sq)
		{
			fprintf(out,",%I64d",i);	//		printf("\r%I64d",i);
			brk++; s++;
			if(brk==120) { fputc('\n',out); brk=0; }
		}
		for(k=(per*i)/n;pro<=k;pro++) printf("%cÄ",8);
	}
	for(;pro<=per;pro++) printf("%cÄ",8);
	fprintf(out,"};\n//total prime %I64d\n",s);
}
/*----Load Primes in a array untill index n by Sieve Algorithm(array_name, untill_n)----*/
/*------------- prime=0, non-prime=1 --------------*/
void seive_prim(__int64 n)
{
	__int64 i,j,brk=0,tot=0,pro=1,k;	bool prim[R]={1,1};

	n++;
	choice ? k=24,putchar('') : k=12,printf("%cÄ",8);
	const int per=(int)k;
	for(i=4;i<n;prim[i]=1,i+=2) 
	{
		for(k=(per*i)/n;pro<=k;pro++) printf("%cÄ",8);		
	}
	for(;pro<=per;pro++) printf("%cÄ",8);

	for(i=3,pro=0;i<n;i+=2)
	{	if(*(prim+i)==0)
			for(j=i+i;j<n;*(prim+j)=1,j+=i);
		for(k=(per*i)/n;pro<=k;pro++) printf("%cÄ",8);
	}
	
	for(;pro<=per;pro++) printf("%cÄ",8);
	
	fprintf(out,"bool prm[]={1");

	for(i=1,pro=0;i<n;i++)
	{
		brk++;
		if(prim[i]==0) tot++;
		fprintf(out,",%d",prim[i]);
		if(brk==400) {  fputc('\n',out); brk=0; }

		for(k=(per*i)/n;pro<k;pro++) printf("%cÄ",8);
	}
	for(;pro<per;pro++) printf("%cÄ",8);
	fprintf(out,"};\n//total prime %I64d.  0=Prime, 1=Composite.\n",tot);
}
/*------------------------------------------------------------------------*/
void data_type(__int64 n)
{
	if(n<128) fprintf(out,"char ");
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
		char marque[]="                              Programmed By TarIQ Newaz Shahriar              \
               It was tried to make the program bug free. If any bug is monitored, feel free to mail.                              ";
		puts("");
		marque_text(marque,30,90);
		
		spreding_string("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿",25,8);
		puts(""); sleep(50);
		printf("\t³ Porgrammed By Tareq Newaz Shahriar ³\n"); sleep(50);
		marging_string("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´",25,8);
		puts(""); sleep(50);
		printf("\t³   Email: protariqcs at hotmail.com ³\n"); sleep(50);
		printf("\t³          tariq.info at gmail.com   ³\n"); sleep(50);
		spreding_string("ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍµ",25,8);
		puts(""); sleep(50);					//		|							
		printf("\t³ May Allah bestow you Ilm & Hikmah. ³\n"); sleep(50);
		marging_string("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ",25,8);
		puts("");
	}	
}		
/*-------------requires sleep function----------------------*/
void marque_text(char marque[],short j,short speed)
{
	char ch;
	for(short i=0;marque[j];i++,j++)
	{
		sleep(speed);
		ch=marque[j]; marque[j]=0;
		printf("\t\t%s\r",marque+i);
		marque[j]=ch;
	}
}		
/*-------------Requires sleep function----------------------*/
void left_right_collide(char text[],short speed)
{
	char str[R], *s; short i,j;
	//k=80-j;
	strcpy(str,"                                                                                 ");
	s=str+81;
	for(i=0;text[i];i++) { *(s++)=text[i], *(s++)=' '; } *(--s)=0;
	s--; j=s-str;
	for(i=9;i<66;i++,s--)
	{
		sleep(speed);
		printf("\r\t%s",s);		
	}
	i=strlen(text)-1;
	j--; speed=(speed*2)+5;
	for(;i;i--,s--,j-=2)
	{
		str[j]=0;
		sleep(speed);
		printf("\r\t%s",s);
		//printf("\r Oil-come");
	}
	puts("\n");
}	 
/*-------------Requires sleep function----------------------*/
void cyclic_text(char text[],short speed)
{
	short i,j,len=strlen(text);
	char ch,*s,*t,str[R],spc[]="                                                                                 ";
	
	s=str+10;
	spc[80-len-15]=0;  //spc[80-len-15-1]='>';
	strcpy(str,"          ");
	for(i=0;text[i];i++) { *(s++)=text[i], *(s++)=' '; } *(--s)=0;
	s--;	
	//printf("%s%s",spc,text);
	for(i=0;i<len;i++,s--)
	{
		sleep(speed);
		printf("\r%s%s",spc,s);		
	}
	for(i=0,j=len+9;i<j;i++,s--)
	{
		ch=s[len]; s[len]=0;
		sleep(speed);
		printf("\r%s%s",spc,s);
		s[len]=ch;
	}
	t=str+(len*2)+10-2; s++;
	for(i=len-1;i>=0;i--,t--)
	{
		ch=s[i]; s[i]=0;
		sleep(speed);
		printf("\r%s%s%s",spc,t,s);
 		s[i]=ch;
	}
	j=(len*2)+10-3; t=str+j-len+1;
	speed+=10;
	for(i=len-1;i;i--,s--,t--,j-=2)
	{
		str[j]=0;
		sleep(speed);
	 	printf("\r%s%s",spc,t);
		//printf("\r Oil-come");
	}
	puts("\n");
}