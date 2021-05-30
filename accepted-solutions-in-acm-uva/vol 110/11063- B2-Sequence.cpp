#include<stdio.h>
#define R 101
#define SIZE 20001
/*---------------------------Global Variables--------------------------*/
int data[R],n;
/*++++++++++++++++++++++++User Defined Functions+++++++++++++++++++++++*/
bool input_n_process()
	{
	int i,j,v;
	bool pair[SIZE]={0};
	scanf("%d",data);
	if(*data<1) { for(i=1;i<n;i++) scanf("%d",data+i); return 0; }
	else
		{
		pair[data[0]+data[0]]=1;
		for(i=1;i<n;i++)
			{
			scanf("%d",data+i); 
			if(data[i]>data[i-1])
				{
				for(j=0;j<=i;j++)
					{
					v=data[i]+data[j];
					if(pair[v]==0) pair[v]=1;
					else { for(i++;i<n;i++) scanf("%d",data+i); return 0; }
					}
				}
			else { for(i++;i<n;i++) scanf("%d",data+i); return 0; }
			}
		}
	return 1;
	}
/*---Binary Search(array, total_element, searching_number)[ascending]-----*/
bool binary_search(int n,int key)
{
	int begin=0,mid;
	while(begin<n)
	{
		mid=(begin+n)/2;
		if(data[mid]==key)
		{
			//while(data[mid-1]==key) mid--; //if there has several key value
			return 1;
		}
		else if(key<data[mid]) n=mid; //##  /* '>' if the data are in descending order   */
		else begin=mid+1;				  /*## '<=' if want to take the subsequent value */
	}
	return 0;
}	
/*----------------------------main Function----------------------------*/
void main()
	{
	//freopen("11063.txt","r",stdin);
	int cs=0;
	while(scanf("%d",&n)!=EOF)
		{
		if(input_n_process()) printf("Case #%d: It is a B2-Sequence.\n\n",++cs);
		else printf("Case #%d: It is not a B2-Sequence.\n\n",++cs);
		}
	/*
	for(i=0;i<n;i++)   // Check a sequence of positive integers 1 <= B1 < B2 < B3 ...
		{			   // such that all pairwise sums Bi + Bj,
		h=data[i]/2;   // where i < j, are not equal to any other value of the sequence.
		for(j=i-1;j>=0&&h<=data[j];j--)
			{
			if(binary_search(j,data[i]-data[j]))
				{	n=-1; break; }
			}
		}
	*/
	}