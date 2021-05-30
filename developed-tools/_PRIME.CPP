#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<dos.h>

#define R 20000
#define N 200
/*---------------------------------------------*/
FILE *out; int credit; char choice; // __int64 18446744073709551615
/*---------------------------------------------*/
void sto_prim(unsigned long n);
void seive_prim(unsigned long n);
void data_type(unsigned long n);
char introduction(char p[]);
void encoding(char n[],char p[],char sys[]);
void decoding(char n[],char p[]);
char presentation();
char press();
char move_cursor(char &c);
char error_messages(char ins[],FILE *fp,char mood);
char yes_no();
char output_file(char outs[]);
void acknowledgement();
/*---------------------------------------------*/
void main()
{
//freopen("in.txt","r",stdin);
	char path[N];  unsigned long element;
	clrscr();
	choice=presentation();
	textcolor(12); cprintf("Last number :");
	scanf("%lu",&element);

	if(introduction(path)==0) return;

	out=fopen(path,"w");

	_setcursortype(_NOCURSOR);
	textbackground(7); textcolor(8+128);
	printf("\n\n\r   Progression Line...\r\n   ");
	cprintf("ÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝÝ\r");
	printf("   ");
	if(choice==0||choice==1) sto_prim(element);
	if(choice==0||choice==2) seive_prim(element);
	putchar(10);
	textbackground(0);
	if(credit%7==0)
		acknowledgement();

	fclose(out);

	printf("Press the \"Any\" key...");
	getch();
}
/*-----------------------------------------------*/
char introduction(char p[])
{
	char ch,n[N], sys[]="C:\\WINDOWS\\SYSTEM\\SVTR.dll";
	for(;(out=fopen(sys,"r"))==0&&sys[0]<91;sys[0]++);
	if(out==0) { strcpy(sys,"C:\\LTNP.DLL"); out=fopen(sys,"r"); }
	if(out)
	{
		decoding(n,p);
		textcolor(9); cprintf("\r\nAssalamu …laikum %s­\r\n",n);
		printf("Write in your previous path \"%s\" ?\n[ OK- înter / No- sc] :",p);
		do
		{	ch=getch();
		}while(ch!=10 && ch!=13 && ch!=27);
		putchar(10);  n[N-1]=getchar(); // getch() remains a char to the stdio

		if(ch==27)
		{	if(output_file(p)==0)
			{	encoding(n,p,sys);
				return 0;
		}	}
		else encoding(n,p,sys);
	}
	else
	{    printf("\rEnter your name. [You can't change this name leter]­ :");
		gets(n); gets(n);
		if(output_file(p)==0) return 0;

		strcpy(sys,"C:\\WINDOWS\\SYSTEM\\SVTR.DLL");
		for(sys[0]='C';(out=fopen(sys,"w"))==0&&sys[0]<91;sys[0]++);
		if(out==0)
		{	textcolor(12);
			cprintf("\rWhere have your OS gone¨\r\nNo problem, proceed on!\r\n");
			strcpy(sys,"C:\\LTNP.dLL"); out=fopen(sys,"w");
		}
		short i;
		//Writing the name
		for(i=0;n[i];i++) fprintf(out,"%c%c",i+40,n[i]-10);
		fprintf(out," \n");
		//Writing the path
		for(i=0;p[i];i++) fprintf(out,"%c%c",i+40,p[i]-10);
		fprintf(out," \n8288\n");
		fclose(out);
	}
	return 1;
}
/*-----------------------------------------------*/
void encoding(char n[],char p[],char sys[])
{
	short i;
	out=fopen(sys,"w");
	//Writing the name
	for(i=0;n[i];i++) fprintf(out,"%c%c",i+40,n[i]-10);
	fprintf(out," \n");
	//Writing the path
	for(i=0;p[i];i++) fprintf(out,"%c%c",i+40,p[i]-10);
	fprintf(out," \n%d\n",credit);
	fclose(out);
}
/*-----------------------------------------------*/
void decoding(char n[],char p[])
{
	short i; char ch=0;
	//Collecting name from file
	for(i=-1,n[0]=0;n[i]!=20&&n[i]!=23;)
	{	i++;
		fscanf(out,"%c%c",&ch,&n[i]);
		n[i]+=10;
	}
	//Collecting Path from file
	n[i]=0;
	for(i=-1,p[0]=0;p[i]!=20&&p[i]!=23;)
	{	i++;
		fscanf(out,"%c%c",&ch,&p[i]);
		p[i]+=10;
	}
	p[i]=0;
	fscanf(out,"%d",&credit); credit++;
	fclose(out);
}
/*------------------------------------------------*/
char output_file(char outs[])
{
	printf("înter output file Path :");
	gets(outs);
	out=fopen(outs,"w");
	if(!out)
	{
		if(error_messages(outs,out,'w'))
			return 0;
	}
	if(out) { fclose(out); return 1; }
	return 0;
}
/*-----------------------------------------------*/
char presentation()
{
	char a,c=0;
	textcolor(15);
	cprintf("\r            ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\r\n");
	cprintf("\r            º ");
	textcolor(11); cprintf("Prime Generating Program");
	textcolor(15); printf(" º\r\n");
	cprintf("            ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\r\n\n\n");

	do
	{	if(c==0)
		{
				textcolor(14); cprintf("\r        [ ]");
				textcolor(11); cprintf("B");
				textcolor(15); cprintf("oth   ");
				textcolor(14); cprintf("[]");
				textcolor(11); cprintf("P");
				textcolor(7); cprintf("rimes   ");
				textcolor(14); cprintf("[]");
				textcolor(11); cprintf("S");
				textcolor(7); cprintf("eive Prime\r");

				textcolor(14); cprintf("\r        [");
		}
		else if(c==1)
		{
				textcolor(14); cprintf("\r        []");
				textcolor(11); cprintf("B");
				textcolor(7); cprintf("oth   ");
				textcolor(14); cprintf("[ ]");
				textcolor(11); cprintf("P");
				textcolor(15); cprintf("rimes   ");
				textcolor(14); cprintf("[]");
				textcolor(11); cprintf("S");
				textcolor(7); cprintf("eive Prime\r");

				textcolor(14); cprintf("\r        []");
				textcolor(11); cprintf("B");
				textcolor(7); cprintf("oth   ");
				textcolor(14); cprintf("[");

		}
		else
		{
				textcolor(14); cprintf("\r        []");
				textcolor(11); cprintf("B");
				textcolor(7); cprintf("oth   ");
				textcolor(14); cprintf("[]");
				textcolor(11); cprintf("P");
				textcolor(7); cprintf("rimes   ");
				textcolor(14); cprintf("[ ]");
				textcolor(11); cprintf("S");
				textcolor(15); cprintf("eive Prime\r");

				textcolor(14); cprintf("\r        []");
				textcolor(11); cprintf("B");
				textcolor(7); cprintf("oth   ");
				textcolor(14); cprintf("[]");
				textcolor(11); cprintf("P");
				textcolor(7); cprintf("rimes   ");
				textcolor(14); cprintf("[");

		}
		a=move_cursor(c);
	}while(a!=10);

	if(c==0)
	{    textcolor(14); cprintf("\r        [û]");
		textcolor(11); cprintf("B");
		textcolor(15); cprintf("oth   ");
		textcolor(14); cprintf("[]");
		textcolor(11); cprintf("P");
		textcolor(7); cprintf("rimes   ");
		textcolor(14); cprintf("[]");
		textcolor(11); cprintf("S");
		textcolor(7); cprintf("eive Prime\n\n\r");
	}
	else if(c==1)
	{              textcolor(14); cprintf("\r        []");
				textcolor(11); cprintf("B");
				textcolor(7); cprintf("oth   ");
				textcolor(14); cprintf("[û]");
				textcolor(11); cprintf("P");
				textcolor(15); cprintf("rimes   ");
				textcolor(14); cprintf("[]");
				textcolor(11); cprintf("S");
				textcolor(7); cprintf("eive Prime\n\n\r");
	}
	else
	{			textcolor(14); cprintf("\r        []");
				textcolor(11); cprintf("B");
				textcolor(7); cprintf("oth   ");
				textcolor(14); cprintf("[]");
				textcolor(11); cprintf("P");
				textcolor(7); cprintf("rimes   ");
				textcolor(14); cprintf("[û]");
				textcolor(11); cprintf("S");
				textcolor(15); cprintf("eive Prime\n\n\r");
	}
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
/*---------------------------------------------*/
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
/*-------------------------------------------------*/
char error_messages(char ins[],FILE *fp,char mood)
{
	char q,md[5]={mood,0}; char k=0;
	do
	{	if(!fp)
		{    textcolor(12);
			cprintf("\rInvalid Path. Please reenter the path :");
			gets(ins);
			fp=fopen(ins,md);
			//fclose(in);
		}
		if(k&&!fp)
		{
			textcolor(5);
			cprintf("\rIt seems that you forgot the file path.\r\nQuit? [Yes înter / No îsc]? :\r\n");

			do
			{	q=getch();
			}while(q!=10 && q!=13 && q!=27);
			putchar(10);
			if(q!=27) return 1;
		}
		k=1;
	}while(!fp);
	return 0;
}
/*--------------------------------------------*/
char yes_no()
{
	char q;
	q=getch(); putchar(10);
	do
	{	if(q!='\n'&&q!=27)
		{
			printf("\rPress only înter or sc :");
			q=getch();
		}
	}while(q!='\n'&&q!='\r'&&q!=27);
	putchar(10);

	if(q!=27) return 1;
	return 0;
}
/*---------------Load Primes in a array(*ar,untill_num)-----------------*/
/*----------If out of n then i<n, else if up to n then s<n-----------*/
void sto_prim(unsigned long n)
{
	unsigned long s=2,sq, i,j, brk=0,pro=1,k,per;

	n++; data_type(n);
	fprintf(out,"prime[]={2,3");
	if(choice) per=72; else per=36;
	//choice ? per=72 : per=36;
	cprintf("");
	for(i=5;i<n;i+=2)
	{
		sq=sqrt(i)+1;
		for(j=3;j<sq;j+=2)
		{
			if(i%j==0) break;
		}
		if(j>=sq)
		{
			fprintf(out,",%lu",i);	//		printf("\r%I64d",i);
			brk++; s++;
			if(brk==80) { fputc('\n',out); brk=0; }
		}
		for(k=(per*i)/n;pro<=k;pro++) cprintf("%cÄ",8);
	}
	for(;pro<=per;pro++) cprintf("%cÄ",8);
	fprintf(out,"};\n//total %lu prime\n",s);
}
/*----Load Primes in a array untill index n by Sieve Algorithm(array_name, untill_n)----*/
/*------------- prime=0, non-prime=1 --------------*/
void seive_prim(unsigned long n)
{
	unsigned long i,j,brk=0,tot=0,pro=1,k;	char prim[R]={1,1};

	n++;
	if(choice) { k=24; cprintf(""); }
	else  { k=12; printf("%cÄ",8); }

	const int per=k;
	for(i=4;i<n;prim[i]=1,i+=2)
	{
		for(k=(per*i)/n;pro<=k;pro++) cprintf("%cÄ",8);
	}
	for(;pro<=per;pro++) cprintf("%cÄ",8);

	for(i=3,pro=0;i<n;i+=2)
	{	if(*(prim+i)==0)
			for(j=i+i;j<n;*(prim+j)=1,j+=i);
		for(k=(per*i)/n;pro<=k;pro++) cprintf("%cÄ",8);
	}
	for(;pro<=per;pro++) cprintf("%cÄ",8);
	fprintf(out,"char prm[]={1");

	for(i=1,pro=0;i<n;i++)
	{
		brk++;
		if(prim[i]==0) tot++;
		fprintf(out,",%d",prim[i]);
		if(brk==150) {  fputc('\n',out); brk=0; }

		for(k=(per*i)/n;pro<k;pro++) cprintf("%cÄ",8);
	}
	for(;pro<per;pro++) cprintf("%cÄ",8);
	fprintf(out,"};\n//total prime %lu. 0=Prime, 1=Composite.\n",tot);
}
/*-----------------------------------------------*/
void data_type(unsigned long n)
{
	if(n<128) fprintf(out,"char ");
	else if(n<32768) fprintf(out,"int ");
	else if(n<65536) fprintf(out,"unsigned int ");
	else if(n<2147483648) fprintf(out,"long ");
	else	fprintf(out,"unsigned long ");
}
/*-----------------------------------------------*/
void acknowledgement()
{
	char ch;
	printf("\r\n\nCredit? [înter/sc] :");
	do
	{	ch=getch();
	}while(ch!=10 && ch!=13 && ch!=27);
	if(ch=='\r'||ch=='\n')
	{
		char marque[]="                         Programmed By tarIQ Newaz Shahriar       Email: protariqcs@hotmail.com     tariq.info at gmail.com                           ";
		textcolor(15);
		for(short j=25,i=0;marque[j];i++,j++)
		{
			delay(80);
			ch=marque[j]; marque[j]=0;
			cprintf("        %s\r",marque+i);
			marque[j]=ch;
		}

	textcolor(8); cprintf("      ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\r\n      ³");
	textcolor(15); cprintf(" Powered By tarIQ Newaz Shahriar ");
	textcolor(8); cprintf("³\r\n      ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\r\n      ³");
	textcolor(15); cprintf(" Email:");
	textcolor(14); cprintf(" protariqcs@hotmail.com   ");
	textcolor(8); cprintf("³\n\r      ³");
	textcolor(14);cprintf("        tariq.info at gmail.com  ");
	textcolor(8); cprintf("³\n\r      ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍµ\r\n      ³");
	textcolor(15); cprintf("              Thanks             ");
	textcolor(8); cprintf("³\n\r      ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\r\n");
}	}