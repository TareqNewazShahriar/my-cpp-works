#include<stdio.h>
#include <map>
#include<string>

using namespace std ;

typedef map<string,string> BabelFish;

void main()
{
//freopen("D:\\Programming\\Problems Coding\\pACM Problems Coding\\in01.txt","r",stdin);
	char word[11]={0},*ch=word+1,eng[11],syn[11];

	BabelFish dic;
	string w;
	
	while(*ch==0)
	{
		scanf("%s%s%[\n]",eng,syn,word);
		dic[syn]=eng;
	}
	
	while(scanf("%s",syn)==1)
	{
		w=dic[syn];
		if(w.empty()==0) puts(w.c_str());
		else puts("eh");
	}
}	