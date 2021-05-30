#include<iostream.h>
#include<conio.h>

int count=0;

class alpha
{
	public:
	alpha()
	{
		count++;
		cout<<"\n No of objects created "<<count;
	}
	~alpha()
	{
		cout<<"\n No of objects destroyed "<<count;
		count--;
	}
};

main()
{
	cout<<"\n\n Enter Main \n";
	alpha A1,A2,A3,A4;

	{
			cout<<"\n\n Enter block 1";
			alpha A5;
	}
	{
		cout<<"\n\n Enter block 2\n";
		alpha A6;
	}
	cout<<"\n\n Re-Enter Main \n";
	getch();
}
