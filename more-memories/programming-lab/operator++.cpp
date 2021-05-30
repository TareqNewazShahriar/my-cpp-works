#include<iostream.h>

class Obj
{
	int x,y;
public:
	Obj()
	{	x=0; y=0; }
	Obj(int a,int b)
	{	x=a, y=b; }
	Obj operator++()
	{
		Obj temp;
		temp.x= x++;
		temp.y= y++;
		return temp;
	}
	void operator=(Obj a)
	{
		x=a.x;
		y=a.y;
	}
	void show()
	{
		cout<<"Values are : "<<x<<" & "<<y<<endl;
	}
};

void main()
{
	Obj q(0,0),p(99,59);
	p.show();
	q.show();
	
	q=p++;

	p.show();
	q.show();
}
