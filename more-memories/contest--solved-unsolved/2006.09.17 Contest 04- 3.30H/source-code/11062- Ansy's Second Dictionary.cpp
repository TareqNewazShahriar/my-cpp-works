#include<stdio.h>
#include<set>
#include<string.h>
#include<string>
#include<iostream>
#define CONST 501
#define MAX 50
using namespace std;
/****************************Global Variables***************************/
int n
//typedef set<string> STRSET;
/*************************User Defined Functions************************/
/*---Find out the number of word in a line(STL_string_array, source_str)---*/
int string_evaluation(string dest[],char *src)
{
	char *s;

	while(*src)
		{
		if((*src>64&&*src<91)||(*src>96&&*src<123))
			{
			s=src;
			for(src++;(*src>64&&*src<91)||(*src>96&&*src<123);src++);
			dest[n].insert(dest[n].begin(),s,src);
			n++;
			}
		else src++;
		}
	return n;
}
/*****************************main Function*****************************/
void main()
	{
	freopen("11062.txt","r",stdin);
	int i;
	char tmp[MAX],q=1;
	string word;
	set<string> dic;
	dic.clear();
	while(scanf("%s",tmp)!=EOF)
		{
		word=tmp;
		while(word[word.length()-1]=='-')
			{
			word.erase(word.end()-1);
			scanf("%s",tmp);
			i=0;
			while(tmp[i])
				{
				for(;(tmp[i]>64&&tmp[i]<91)||(tmp[i]>96&&tmp[i]<123);i++);
				word+=tmp;
				}
			}
		
		}
	//n=dic.size();
	//set<string> :: iterator n;
	set<string> :: iterator i;

	for(i=dic.begin();i!=dic.end();i++) 
		{
		//word=*i;
		//cout<<dic[i].c_str()<<endl; /*
		printf("%s\n",(*i).c_str()); //*/
		}
	}