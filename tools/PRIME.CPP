#include<stdio.h>
#include<conio.h>
#include<math.h>
#define R 10000
#define T 30774
/*---------------------------------------------*/
FILE *out;
/*---------------------------------------------*/
void sto_prim(unsigned long n);
void seive_prim(unsigned long n);
void data_type(unsigned long n);
char presentation();
char press();
char move_cursor(char &c);
/*---------------------------------------------*/
void main()
{
	int choice;  unsigned long element;
	char path[200];

	choice=presentation();
	printf("Last number: ");
	scanf("%lu",&element);

	if(choice==0||choice==2) sto_prim(element);
	if(choice==1||choice==2) seive_prim(element);

	fclose(out);
}

/*---------------Load Primes in a array(*ar,untill_num)-----------------*/
/*----------If out of n then i<n, else if up to n then s<n-----------*/
void sto_prim(unsigned long n)
{
	unsigned long s=2,sq, i,j, brk=0;
	n++;
	data_type(n);
	fprintf(out,"prime[]={2,3");

	for(i=5;i<n;i+=2)
	{
		sq=sqrt(i)+1;
		for(j=3;j<sq;j+=2)
		{
			if(i%j==0) break;
		}
		if(j>=sq)
		{
			fprintf(out,",%lu",i);
			brk++; s++;
			if(brk==80) { fputc('\n',out); brk=0; }
		}
	}
	fprintf(out,"};\n//total %lu prime\n",s);
}
/*----Load Primes in a array untill index n by Sieve Algorithm(array_name, untill_n)----*/
//------------- prime=0, non-prime=1 --------------
void seive_prim(unsigned long n)
{	
	unsigned long i,j,brk=0,tot=0;
	char prim[R]={1,1};
	n++;
	for(i=4;i<n;prim[i]=1,i+=2);
	for(i=3;i<n;i+=2)
	{
		if(*(prim+i)==0)
			for(j=i+i;j<n;*(prim+j)=1,j+=i);
	}
	fprintf(out,"bool prm[]={1");
	for(i=1;i<n;i++)
	{
		brk++;
		fprintf(out,",%d",prim[i]);
		if(prim[i]==0) tot++;
		if(brk==150) {  fputc(10,out); brk=0; }
	}
	fprintf(out,"};\n//total %lu prime\n",tot);
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
char presentation()
{
	char a,c=2;
	clrscr();
	_setcursortype(_NOCURSOR);
	printf("            ษออออออออออออออออออออออออออป\n");
	printf("            บ Prime Generating Program บ\n");
	printf("            ศออออออออออออออออออออออออออผ\n\n\n");

	do
	{    putchar('\r');
		if(c==0)
		{
			textcolor(LIGHTRED); cprintf("\t[๛]");
			textcolor(WHITE); cprintf("P");
			printf("rimes   [ ]");
			textcolor(WHITE); cprintf("S");
			printf("eive Prime   [ ]");
			textcolor(WHITE); cprintf("B");
			printf("oth");
		}
		else if(c==1)
		{
			printf("\t[ ]");
			textcolor(WHITE); cprintf("P");
			printf("rimes   ");
			textcolor(LIGHTRED); cprintf("[๛]");
			textcolor(WHITE); cprintf("S");
			printf("eive Prime   [ ]");
			textcolor(WHITE); cprintf("B");
			printf("oth");
		}
		else
		{
			printf("\t[ ]");
			textcolor(WHITE); cprintf("P");
			printf("rimes   [ ]");
			textcolor(WHITE); cprintf("S");
			printf("eive Prime   ");
			textcolor(LIGHTRED); cprintf("[๛]");
			textcolor(WHITE); cprintf("B");
			printf("oth");
		}
		a=move_cursor(c);
	}while(a!=10);
	return c;
}
/*--------------------------------------------*/
char move_cursor(char &c)
{
	char a;
	do
	{
		a=press();
		if(a=='p'||a=='P') c=0;
		else if(a=='s'||a=='S') c=1;
		else if(a=='B'||a=='b') c=2;
		else if(a==' '||a=='\r'||a=='\n') return 10;
		else if(a!='\t'&&a!='K') c=5;
		else if(c==0)
		{
			if(a=='\t') c=1;
			else if(a=='K') c=2;
		}
		else if(c==1)
		{
			if(a=='\t') c=2;
			else if(a=='K') c=0;
		}
		else
		{
			if(a=='\t') c=0;
			else if(a=='K') c=1;
		}
	}while(c==5);
	return c;
}
/*---------------------------------------------*/
char press()
{
	char a,b;
	a=getch();
	if(a==0)
	{
		b=getch();
		if(b=='H'||b=='M') a='\t';
		else if(b=='K'||b=='P'||b==15) a='K';
	}
	return a;
}