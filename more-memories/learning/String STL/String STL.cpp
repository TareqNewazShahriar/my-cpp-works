#include<iostream>
#include<string>
#define SIZE 1000

using namespace std;
/****************************Global Variables***************************/
/*************************User Defined Functions************************/
void display(string str[1])
	{
	cout << "Size_0 = " << str[0].size() << "\n";
	cout << "Size_1 = " << str[1].size() << "\n";
	cout << "Size_2 = " << str[2].size() << "\n";

	cout << "Length_0 = " << str[0].length() << "\n";
	cout << "Length_1 = " << str[1].length() << "\n";
	cout << "Length_2 = " << str[2].length() << "\n";
	
	cout << "Capacity_0 = " << str[0].capacity() << endl;
	cout << "Capacity_1 = " << str[1].capacity() << endl;
	cout << "Capacity_2 = " << str[2].capacity() << endl;

	cout << "Maximum Size = " << str[0].max_size() << endl;
	cout << "Empty : " << (str[0].empty() ? "Yes":"No") << "\n\n";
	}
/*****************************main Function*****************************/
void main()
	{
	string str[10];
	
	cout<<"Initial status :\n";
	display(str);

	str[0]="";
	str[1]="Soudi Arabia";
	str[2]="Bangadesh";
	cout<<"Enter string(s)\nStaus now- \n";
	display(str);

	str[2].resize(0);
	cout << "After Resizing : \n";
	display(str);
	}