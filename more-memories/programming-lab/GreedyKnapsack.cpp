#include<iostream.h>
#include<stdio.h>
#define R 50

class KnapsacK
{
	int m,n, p[R],w[R];
	float r,pw[R],x[R];
public:
	void input();
	void PriceWeight();
	void process();
	void output();
	friend void SelectionSort(KnapsacK &);
};

void KnapsacK::input()
{
	int i;
	cout<<"input capacity of the Knapsack :";
	cin>>m;
	cout<<"how many item want to input :";
	cin>>n;
	
	cout<<"enter weights :";
	for(i=0;i<n;i++)
		cin>>w[i];
	
	cout<<"enter prices :";
	for(i=0;i<n;i++)
		cin>>p[i];
}
void KnapsacK::PriceWeight()
{
	int i;
	for(i=0;i<n;i++)
		pw[i]=(float)p[i]/(float)w[i];
}
void SelectionSort(KnapsacK &s)
{
	int i,j,k;
	float t;

	for(i=0; i<s.n; i++)
	{	k=i;
		for(j=i+1;j<s.n;j++)
		{
			if(s.pw[k]<s.pw[j])
				k=j;
		}
		t=s.pw[i]; s.pw[i]=s.pw[k]; s.pw[k]=t;
		t=s.w[i]; s.w[i]=s.w[k]; s.w[k]=t;
		t=s.p[i]; s.p[i]=s.p[k]; s.p[k]=t;
	}
}///////////////////

void KnapsacK::process()
{
	int i,t;

	t=m;
	r=0.0;
	
	for(i=0;i<n;i++,x[i]=0.0);

	for(i=0;i<n;i++)
	{
		if(t<w[i]) break;

		t-=w[i]; x[i]=1.0;
		r+=p[i];
	}
	if(i<n)
	{
		x[i]=t / (float)w[i];
		r+=x[i] * (float)p[i];
	}
}

void KnapsacK::output()
{
	cout.precision(3);
	cout<<"\n\nTotal profit gained "<<r<<".\n\n";
}

void main()
{
	freopen("input - Greedy Knapsack.txt","r",stdin);

	KnapsacK k;
	k.input();
	k.PriceWeight();
	SelectionSort(k);
	k.process();
	k.output();
}