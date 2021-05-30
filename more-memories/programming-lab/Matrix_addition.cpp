#include<iostream>
//#include<stdio.h>
#define M 2

using namespace std;

class matrix
{
	int i,j, a[M][M],b[M][M],c[M][M];
public:
	void input_matrix(int x[M][M]);
	void output_matrix(int x[M][M],int n);
	void matrix_addition(int a[M][M],int b[M][M]);
};

void matrix :: input_matrix(int x[M][M])
{
	cout<<"Input "<<M<<"X"<<M<<" Matrix:\n";
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			cout<<"  Row "<<i<<", Column "<<j<<":";
			cin>>x[i][j];
		}
	}
}

void matrix::matrix_addition(int a[M][M],int b[M][M])
{

	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			cout<<a[i][j]+b[i][j];
		}
	}
}

void matrix::output_matrix(int x[M][M],int n)
{
	cout<<"Displaying Matrix "<<n<<" :";
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			cout<<setw(5)<<x[i][j];
		}
		cout<<"\n";
	}
}