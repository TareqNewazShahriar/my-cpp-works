#include<stdio.h>
#include<queue>
#define SIZE 101

using namespace std;
typedef queue<int> QUE;
/****************************Global Variables***************************/
int n,loc;
/*************************User Defined Functions************************/
/*-------------------------------------------------------------*/
void input(QUE &que,QUE &pos,int x[])
	{
	int i,d;
	scanf("%d%d",&n,&loc);

	for(i=0;i<n;i++)
		{
		scanf("%d",&d);
		x[d]++;
		que.push(d);
		pos.push(i);
		}
	}
/*-------------------------------------------------------------*/
int print_the_job(QUE &que,QUE &pos,int x[])
	{
	int k=0,j, v;

	do
		{
		j=que.front()+1;
		for( ; j<10&&x[j]==0; j++);

		if(j==10) 
			{
			k++;
			x[que.front()]--; que.pop();
			v=pos.front(); pos.pop();
			}
		else
			{
			j=que.front(); que.pop(); que.push(j);
			j=pos.front(); pos.pop(); pos.push(j);
			v=200;
			}
		}while(v!=loc);
	return k;
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("inF.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for( ; t ; t--)
		{
		QUE que,pos;
		int x[10]={0};

		input(que,pos,x);
		//n=que.size();
		//n=pos.size();
		printf( "%d\n", print_the_job(que,pos,x) );
		}
	}