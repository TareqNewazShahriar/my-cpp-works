#include<stdio.h>
#include<string.h>
#define R 100
#define T 5
/*---------------------------Global Variables--------------------------*/
int n,v,u;
long val[R];
char num[R][T][T]={
{"000","0.0","0.0","0.0","000"},{".0.",".0.",".0.",".0.",".0."},{"000","..0","000","0..","000"},
{"000","..0","000","..0","000"},{"0.0","0.0","000","..0","..0"},{"000","0..","000","..0","000"},
{"0..","0..","000","0.0","000"},{"000","..0","..0","..0","..0"},{"000","0.0","000","0.0","000"},
{"000","0.0","000","..0","..0"},{".0.",".0.","000",".0.",".0."},{"...","...","000","...","..."},
{"0.0","0.0",".0.","0.0","0.0"},{".0.","...","000","...",".0."}
}, ins[R][T][T], w[R], op[R], str[1000];
/*--------------------------Function Prototypes------------------------*/
void scoreboard_to_number_equivalent();
long solve_algebraic_expression();
void display_scoreboard(long n);
int input();
int string_evaluation(char dest[R][T][T],char *src);
/*----------------------------main Function----------------------------*/
void main()
{
//freopen("10875.txt","r",stdin);
//freopen("10875out.txt","w",stdout);
	bool q=0;
	n=input();
	while(n)
	{
		if(q) putchar(10); q=1;

		scoreboard_to_number_equivalent();
		solve_algebraic_expression();
		display_scoreboard(val[0]);
		
		n=input();
	}
}
long solve_algebraic_expression()
{
	int i,j;
	while(u)
	{
		for(i=0;i<u;i++)
		{
			if(op[i]==12) { val[i]*=val[i+1];  break; }
			else if(op[i]==13) 
			{
				val[i]/=val[i+1];
				break; 
			}
		}
		if(i==u)
		{
			i--;
			if(op[i]==10) val[i]+=val[i+1];
			else if(op[i]==11) val[i]-=val[i+1];
		}
		else
		{
			for(j=i+2; j<v; val[j-1]=val[j], j++);
			for(i++;i<u; op[i-1]=op[i], i++);
		}
		v--; u--;
	}
	return val[0];
}
void display_scoreboard(long n)
{
	int i=-1,j,k;
	char digit[R],q=0;
	if(n<0) { q=1; n=-n; }
	
	do
	{	digit[++i]=n%10;
		n/=10;
	}while(n>=1);
	
	for(k=0;k<5;k++)
	{
		if(q) printf("%s ",num[11][k]);
		for(j=i;j;j--)
			printf("%s ",num[digit[j]][k]);
		puts(num[digit[0]][k]);
	}
}
void scoreboard_to_number_equivalent()
{
	int i,j,k,q;
	u=v=q=0; 
	for(i=0;i<n;i++)
	{	
		for(j=0;j<14;j++)
		{
			for(k=0;k<5;k++)
				if(strcmp(num[j][k],ins[i][k])!=0) break;
			if(k==5)
			{
				if(j<10)
				{	
					if(q) val[v-1]=(val[v-1]*10)+j;
					else val[v++]=j;
					q=1;
				}
				else { q=0; op[u++]=j; }
				break;
			}
		}
	}
}
int input()
{
	int i,j,k;
	
	i=w[0]=0;
	gets(str);
	i=string_evaluation(ins,str);
	/*
	while(w[0]!='\n')
	{
		scanf("%s%[ ]",ins[i][0],w);
		scanf("%[\n]",w);
		i++;
	}
	*/
	for(k=1;k<5;k++)
	{
		for(j=0;j<i;j++)
			scanf("%s",ins[j][k]);
	}
	if(i==1)
	{
		for(k=0;k<5;k++)
			if(strcmp(num[0][k],ins[0][k])!=0) break;
		if(k==5) return 0;
	}
	gets(str);
	gets(str); //to take the new lines
	return i;
}
/*-Find out the number of strings in a line(3D_dest_str, source_str)-*/
int string_evaluation(char dest[R][T][T],char *src)
{
	int k,count=0;
	char *i=src;

	while(*i)
	{
		if((*i)!=' '&&(*i)!='\t')
		{
			for(k=0;(*i)!=' '&&(*i)!='\t'&&(*i);i++)
				dest[count][0][k++]=*i;
			count++;
		}
		else i++;
	}
	return count;
}