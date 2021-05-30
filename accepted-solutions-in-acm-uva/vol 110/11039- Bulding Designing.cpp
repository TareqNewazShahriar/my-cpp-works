#include<stdio.h>
#include<algorithm>
#define R 500001

using namespace std;

/*-------------------------Global Variables-----------------------*/
int *freq, *lis;
class DATA
{
public:	int f;
		bool k;
}data[R];
/*--------------------- Function Prototypes-----------------------*/
bool compare( const DATA &a, const DATA &b )
{
	if(a.f>b.f) return true;
	return false;
}
/*--------------------------Input Function----------------------------*/
int input()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",data+i);
		if(data[i].f<0)
			{
			data[i].f=-data[i].f;
			data[i].k=0;
			}
		else data[i].k=1;
	}
	return n;
}	
/*---------------------------main Function-------------------------*/
void main()
	{
	//freopen("11039.txt","r",stdin);
	int cs,i,j,max,n;
	scanf("%d",&cs);
	for(;cs;cs--)
		{
		n=input();
		sort(data,data+n,compare);
		
		max=1; j=0;
		for(i=1;i<n;i++)
			{
			if(data[j].k!=data[i].k) { j=i; max++; }
			}
		/*
		while(i<n)
			{
			k=0;
			for(j=i+1;j<n&&data[j].k!=data[j-1].k;j++);
			if(max<(j-i)) max=j-i;
			i=j;
			}
		*/
		printf("%d\n",max);
		}
	}

/*--Just to display the L.I.Subsequence(sequence_length, starting_index)--*
void display(int n,int i)  // data freq must be global
{
	printf("%d\n%d\n",n+1,data[i].k);
	do	
	{	
		i=lis[i];
		printf("%d\n",data[i].k);
	}while(lis[i]);
	
}	
/*---Binary Search(array, total_element, searching_number)[opt]-----*
int binary_search(int n,int key)
{							// here total_element is "total_element-1".
	int begin=0,mid;
	while(begin<=n)
	{
		mid=(begin+n)/2;
		if(data[mid]==key)
		{
			while(data[mid-1]==key) mid--; //if there has several key value
			return mid;
		}
		else if(key>data[mid]) n=mid-1; // '>' if the data are in descending order 
		else begin=mid+1;
	}
	return begin;   // middle position where the key lies between
	//return (-1);
}	
*/