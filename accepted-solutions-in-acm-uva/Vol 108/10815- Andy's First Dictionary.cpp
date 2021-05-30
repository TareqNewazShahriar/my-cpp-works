#include<stdio.h>
#include<string>
#include<map>
#define SIZE 205
#define MAX 5001
using namespace std;
/****************************Global Variables***************************/
string word;
typedef map<string,bool> MAP;
MAP dic;
/*************************User Defined Functions************************/
/*--------------------- Function Prototypes-----------------------*/
bool compare( const string &a, const string &b )
{
	if(a<b) return true;
	return false;
}
/*---------------------------------------------------------------------*/
void display_words()
	{
	MAP::iterator i;
	for(i=dic.begin();i!=dic.end();i++)
		puts((*i).first.c_str());
		//cout<<(*i).first<<endl;
		//printf("%s\n",(*i).first.c_str());
		
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("in.txt","r",stdin);
	int i;
	char str[SIZE],*src,*s,tmp;
	while(gets(str))
		{
		src=str;
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
				word.assign(s,src);
				dic[word]=1;
				}
			else src++;
			}
		}
	display_words();
	}