#include<stdio.h>
#include<string>
#include<algorithm>
#define SIZE 100000
#define MAX 5000
using namespace std;
/****************************Global Variables***************************/
int n=-1;
string word[SIZE];
/*************************User Defined Functions************************/
/*--------------------- Function Prototypes-----------------------*/
bool compare( const string &a, const string &b ) 
{
	if(a<b) return true;
	return false;
}
/*---Find out the number of word in a line(STL_string_array, source_str)---*/
void count_string(char *src)
	{
	while(*src)
		{
		if((*src>64&&*src<91)||(*src>96&&*src<123))
			{
			s=src;
			if(*src<91) (*src)+=32;
			for(src++;(*src>64&&*src<91)||(*src>96&&*src<123);src++)
				{
				if(*src<91) (*src)+=32;
				}
			word[++n].assign(s,src);
			}
		else src++;
		}
	}
/*---------------------------------------------------------------------*/
void display_words()
	{
	int i;
	n++;
	puts(word[0].c_str());
	for(i=1;i!=n;i++)
		if(word[i]!=word[i-1])
			puts(word[i].c_str());

		//cout<<(*i).first<<endl;
		//printf("%s\n",(*i).first.c_str);
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("in.txt","r",stdin);
	char str[SIZE],*s,*src,ch;
	while(gets(str))
		{
		src=str;
		if(ch=='-'&&)
			{
			s=src;
			word[n].erase(word[n].length()-1);
			for(src++;(*src>64&&*src<91)||(*src>96&&*src<123);src++)
				{
				if(*src<91) (*src)+=32;
				}
			word[n].append((s,src);
			}
		while(*src)
			{
			if((*src>64&&*src<91)||(*src>96&&*src<123))
				{
				s=src;
				if(*src<91) (*src)+=32;
				for(src++;(*src>64&&*src<91)||(*src>96&&*src<123)||src=='-';src++)
					{
					if(*src<91) (*src)+=32;
					}
				word[++n].assign(s,src);
				}
			else src++;
			}
		ch=*(src-1);
		}
	sort(word,word+n);
	display_words();
	}