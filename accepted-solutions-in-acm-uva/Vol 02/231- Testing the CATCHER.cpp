#include<stdio.h>
#define R 10000
/*----------------Functions-----------------*/
int binary_search(int data[],int n,int key);
/*--------------main Function---------------*/
void main()
{
//freopen("in.txt","r",stdin);
	int cs=0,pos,k,m,mis[R],q=0;
	//char str[100];
	scanf("%d",&m);  
	/*
	scanf("%d%[ ]",&m,str);
	scanf("%[\n]",str);
	scanf("%d%[ ]%[\n]",&m,str,str);
	str[1]=='\n';
	*/
	while(m!=-1)
	{
		//if(q) putchar(10); q=1;
		mis[k=0]=m;
		scanf("%d",&m);
		while(m!=-1)
		{
			if(m>mis[k])
			{
				pos=binary_search(mis,k,m);
				mis[pos]=m;
			}
			else //if(m!=mis[k])
			{
				//pos=binary_search(mis,k,m);
				mis[++k]=m;
			}

			scanf("%d",&m);
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n",++cs,k+1);
		
		scanf("%d",&m);
	}
}
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
		else if(key>data[mid]) n=mid-1; // '>' if the data are in descending order 
		else begin=mid+1;
	}
	return begin;   // middle position where the key lies between
	//return (-1);
}	