#include<stdio.h>
#define R 1000
/*---------------------------Global Variables--------------------------*/
/*--------------------------Function Prototypes------------------------*/
/*---Binary Search(array, total_element, searching_number)[opt]-----*/
int binary_search(int data[],int n,int key)
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
		else if(key<data[mid]) n=mid-1; // '>' if the data are in descending order 
		else begin=mid+1;
	}
	return begin;   // middle position where the key lies between
	//return (-1);
}	
/*----------------------------main Function----------------------------*/
void main()
{
freopen("in.txt","r",stdin);
	int k,m,lis[R],pos;
	scanf("%d",&m);
	lis[k=0]=m;
	while(scanf("%d",&m)!=-1)
	{
		if(m>lis[k])  lis[++k]=m;
		else if(m<lis[k])
		{
			pos=binary_search(lis,k,m);
			lis[pos]=m;
		}
	}
	k++;
	printf("%d\n-\n",k);
	for(m=0;m<k;m++) printf("%d\n",lis[m]);
}	