#include<stdio.h>
#define SIZE 1000
typedef int Type;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
/*-The str_infix will be changed into str_postfix. In postfix, the operand-*/
/*---will be signed as 'P'. The operand value will store in operand array--*/
int infix_to_postfix(char infix[],char postfix[],Type operand[])
	{
	Type n, p=0,k=0,s=0;
	char *i=infix, stk[SIZE]="(";
	
	while(*i)
		{
		if(*i>47&&*i<58)
			{
			for(n=(*i)-48,i++; *i>47&&*i<58 ; n=(n*10)+(*i-48),i++);
			postfix[p++]='P'; operand[k++]=n;
			}
		else
			{
			if(*i=='(') stk[++s]='(';
			else if(*i==')')
				{ for( ; stk[s]!='('; postfix[p++]=stk[s--]); s--; }
			else if(*i=='+'||*i=='-')
				{ for( ; stk[s]!='('; postfix[p++]=stk[s--]); stk[++s]=*i; }
			else{ for( ; stk[s]=='/'||stk[s]=='*'; postfix[p++]=stk[s--]); stk[++s]=*i; }
			i++;
			}
		}
	for( ;s; postfix[p++]=stk[s--]);
	postfix[p]=0;
	return k;
	}
/*-INCOMPLETE-Evaluate the postfix notation(str postfix, operands_array)--*/
int evaluate_postfix(char postfix[],int poerand[])
	{
	int p=-1;
	char *i=postfix;
	for( ;*i;i++)
		{
		while(*i=='P') i++, p++;
		if(*i=='-') { *(i-2)=operand[p]-operand[p-1]; strcpy(i-1,i+1); }
		else if(*i=='+') { *(i-2)=*i + *i; strcpy(i-1,i+1); }
		else if(*i=='*') { *(i-2)=*i * *i; strcpy(i-1,i+1); }
		else { *(i-2)=*i / *i; strcpy(i-1,i+1); }
		}
	}
/*****************************main Function*****************************/
void main()
	{
	freopen("in.txt","r",stdin);
	Type i=0,operand[SIZE];
	char infix[SIZE],postfix[SIZE];

	while(gets(infix))
		{
		infix_to_postfix(infix,postfix,operand);
		puts(postfix);
		}
	}