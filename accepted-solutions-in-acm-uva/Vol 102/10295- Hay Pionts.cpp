#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
/*-------------------------------------------*/
using namespace std;
typedef map<string,double> Map;
/*-------------------------------------------*/
void main()
{
//freopen("in08.txt","r",stdin);
	Map salary;
	string exps; 
	long i,m,n;
	double amt;
	char exp[20];
	
	scanf("%ld%ld",&m,&n);
	for(i=m;i;i--)
	{
		scanf("%s%lf",exp,&amt); /*
		cin>>exp>>amt;   //*/
		salary[exp]=amt;
	}
	
	for(;n;n--)
	{	
		scanf("%s",exp); /*
		cin>>exp;		 //*/
		amt=salary[exp];
		while(*exp!='.')
		{
			scanf("%s",exp);  /*
			cin>>exp;			//*/
			amt+=salary[exp];
		}
		printf("%.0lf\n",amt);
	}
}	