#include<stdio.h>
#include<iostream.h>

#define R 100

class Mat
{
	int m,n,p, a[R][R], b[R][R], c[R][R];
public:
	void input();
	void multiply();
	void display();
};

void Mat::input()
{
	int i,j;
	
	cout<<"Enter dimension of A[MxN]:";
	cin>>m>>n;
	cout<<"Enter the value of A:";
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			cout<<"A["<<i+1<<","<<j+1<<"]:";
			cin>>a[i][j];
		}

	cout<<"Enter column of B:";
	cin>>p;
	cout<<"Enter the value of B:";
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
		{
			cout<<"B["<<i+1<<","<<j+1<<"]:";
			cin>>b[i][j];
		}
}

void Mat::display()
{	int i,j;

	cout<<"\nmatrix A:\n";
	for(i=0;i<m;i++)
	{	
		for(j=0;j<n;j++)
		{
			cout.width(3);
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	cout<<"matrix B:\n";
	for(i=0;i<m;i++)
	{	
		for(j=0;j<n;j++)
		{
			cout.width(3);
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n";
	cout<<"Resultant Matrix:\n";
	for(i=0;i<m;i++)
	{	
		for(j=0;j<p;j++)
		{
			cout.width(3);
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Mat::multiply()
{
	int i,j,k;

	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{	c[i][j]=0;
			for(k=0;k<n;k++)
			{
				c[i][j]=c[i][j]+ a[i][k]*b[k][j];
			}
		}
	}
}

void main()
{
	freopen("in.txt","r",stdin);

	Mat m;

	m.input();
	m.multiply();
	m.display();
}