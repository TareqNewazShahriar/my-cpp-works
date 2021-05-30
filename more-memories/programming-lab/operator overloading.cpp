#include<stdio.h>
#include<iostream>

using namespace std;

class CompleX
{
protected:
	float real, image;
public:
	CompleX() {		}
	CompleX(float r, float i)
	{	real=r; image=i;	}
	void show()
	{
		cout<<"Real = "<<real<<", Imaginary = "<<image<<"\n";
	}
	CompleX operator+(CompleX x)
	{
		CompleX temp;

		temp.real=real+x.real;
		temp.image=image+x.image;
		
		return temp;
	}
	void operator++()
	{
		real*=real;
		image*=image;
		//return *this;
	}
	void operator=(CompleX t)
	{
		real=t.real;
		image=t.image;
		//return *this;
	}
};

void main()
{
	CompleX a(4,8),b(2,9), c(0,0);
	
	a.show(); b.show();
	c.show();

	c=a+b;
	c.show();

	c 
		++;
	c.show();
	
	a=
		++c;
	c.show();
	a.show();
}