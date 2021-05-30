#include<iostream.h>
#include<stdio.h>
#define R 10

class DP_Assembly_line
{
private:
	int entry1,entry2, s1[R],s2[R], trans1[R],trans2[R], exit1,exit2,
		path1[R],path2[R], line[3][R];
public:
	int k,n;
	void input_data();
	void Assembly_line_Scheduling();
	void show_quick_path(int,int);
};

void DP_Assembly_line::input_data()
{
	int i;
	
	cout<<"entry number of station: ";
	cin>>n;
	
	cout<<"Station 1 ::\n";
	cout<<"Entry & Exit time: ";
	cin>>entry1>>exit1;
	cout<<"The time sequences: ";
	for(i=1;i<=n;i++)
		cin>>s1[i];
	cout<<"Transfer time sequences: ";
	for(i=1;i<n;i++)
		cin>>trans1[i];
	

	cout<<"Station 2 ::\n";
	cout<<"Entry & Exit time: ";
	cin>>entry2>>exit2;
	cout<<"The time sequences: ";
	for(i=1;i<=n;i++)
		cin>>s2[i];
	cout<<"Transfer time sequences: ";
	for(i=1;i<n;i++)
		cin>>trans2[i];
}

void DP_Assembly_line::Assembly_line_Scheduling()
{
	int j;

	path1[1]=entry1+s1[1];
	path2[1]=entry2+s2[1];
	for(j=2;j<=n;j++)
	{
		if(path1[j-1]+s1[j] <= path2[j-1]+trans2[j-1]+s1[j])
		{	path1[j]=path1[j-1]+s1[j];
			line[1][j]=1;
		}
		else 
		{	path1[j]=path2[j-1]+trans2[j-1]+s1[j];
			line[1][j]=2;
		}

		if(path2[j-1]+s2[j] <= path1[j-1]+trans1[j-1]+s2[j])
		{	path2[j]=path2[j-1]+s2[j];
			line[2][j]=2;
		}
		else 
		{	path2[j]=path1[j-1]+trans1[j-1]+s2[j];
			line[2][j]=1;
		}
	}// for - j
	if(path1[n]+exit1 <= path2[n]+exit2)
	{	path1[n+1]=path1[n]+exit1;
		line[1][n+1]=k=1;
	}
	else
	{	path2[n+1]=path2[n]+exit2;
		line[2][n+1]=k=2;
	}
}

void DP_Assembly_line::show_quick_path(int k,int j)
{
	int i=k;
	
	//--Iteration--
	/*
	cout<<"\n\n";
	cout<<"Station "<<j<<", Line "<<i<<".\n";
	for(;j>=2;j--)
	{
		i=line[i][j];
		cout<<"Station "<<j-1<<", Line "<<i<<".\n";
	}
	/*/
	
	//--Recurstion--
	i=line[i][j];
	
	if(j!=2) show_quick_path(i,j-1);

	cout<<"Station "<<j-1<<" Line "<<i<<"\n";
}

void main()
{
	freopen("DP - Assembly-line Scheduling.txt","r",stdin);

	DP_Assembly_line schedule;

	schedule.input_data();
	schedule.Assembly_line_Scheduling();
	cout<<"\n\n";
	schedule.show_quick_path(schedule.k, schedule.n+1);
}