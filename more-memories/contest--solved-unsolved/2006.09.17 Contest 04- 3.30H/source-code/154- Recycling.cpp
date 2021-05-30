#include<stdio.h>
#include<string>
#include<map>
#define SIZE 100
#define MAX 5
/****************************Global Variables***************************/
int n;

using namespace std;
string bin[SIZE][MAX];

typedef map<string,bool> MAP;
MAP city[SIZE];
/*************************User Defined Functions************************/
int input()
	{
	int i,j;
	char end[SIZE]="",str[SIZE];
	
	for(i=0;1;i++)
		{
		scanf("%[e]",end);
		if(*end=='e') { gets(end); return i; }
		for(j=0;j<5;j++)
			{
			scanf("%[rPoGySgAb/N]%[, \n]",str,end);
			city[i][str]=1;
			}
		}
	return i;
	}
/*------Find that which city would cause the least impact to change-----*/
int find_optimal_change()
	{
	int i,j,opt=0,var,index;
	string tmp;
	for(i=0;i<n;i++)
		{
		var=0;
		for(j=0;j<n;j++)
			{
			if(i==j) continue;

			MAP::iterator k,x;
			x=city[j].end();
			for(k=city[j].begin();k!=x;k++)
				{
				tmp=(*k).first;
				if(city[i][tmp]) var++;
				}
			}
		if(var>opt) { opt=var; index=i; }
		}
	return index;
	}
/*****************************main Function*****************************/
void main()
	{
	freopen("154.txt","r",stdin);
	for(n=0;n<SIZE;n++) city[n].clear();
	n=input();
	while(n)
		{		
		printf("%d\n",find_optimal_change()+1);
		for(n=0;n<SIZE;n++) city[n].clear();
		n=input();
		}
	}