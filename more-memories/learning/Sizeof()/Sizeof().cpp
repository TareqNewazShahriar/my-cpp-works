// By --------- Alauddin -----------
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<BigInt_Al.h>

/*===========================MAIN=============================*/
#define Size 1000
void main()
	{
	int i;
	char bignum[1010]="";
	BigInt N;

	for(i=0;i<1000;i++)
		bignum[i]='9';

	cout<<"sizeof(BigInt_Al)= "<<sizeof(BigInt)<<"\n";
	N.digits=bignum;
	cout<<"sizeof(BigInt N.1000digit)= "<<sizeof(N)<<"\n";
	puts(N.digits.c_str());
	encode(N);
	cout<<"sizeof(Enconded N)= "<<sizeof(N)<<"\n";
	decode(N);
	cout<<"sizeof(Decoded N)= "<<sizeof(N)<<"\n";
	puts(N.digits.c_str());

	cout<<"\n"<<"sizeof(__int64)  = "<<sizeof(__int64)<<"\n";
	cout<<"sizeof( int )    = "<<sizeof(int)<<"\n";
	cout<<"sizeof( long )   = "<<sizeof(long)<<"\n";
	cout<<"sizeof( short )  = "<<sizeof(short)<<"\n";
	cout<<"sizeof( char )   = "<<sizeof(char)<<"\n";
	cout<<"sizeof(clock_t)  = "<<sizeof(clock_t)<<"\n";
	}
