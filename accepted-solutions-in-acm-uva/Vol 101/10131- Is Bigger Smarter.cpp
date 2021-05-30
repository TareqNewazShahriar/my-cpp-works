#include<stdio.h>
#include<algorithm>
#define R 1001

using namespace std;

/*-------------------------Global Variables-----------------------*/
int *freq, *lis;
class DATA
{
public:	int x,y,k;
}data[R];
/*--------------------- Function Prototypes-----------------------*/
bool compare( const DATA &a, const DATA &b )
{
	if(a.y==b.y) 
	{
		if(a.x<b.x) return true;
		return false;
	}
	if(a.y>b.y) return true;
	return false;
}
/*--------------------------Input Function----------------------------*/
int input()
{
	int n=0;
	while(scanf("%d%d",&data[n].x,&data[n].y)!=EOF)
	{
		data[n].k=n+1;
		n++;
	}
	return n;
}	
/*--Just to display the L.I.Subsequence(sequence_length, starting_index)--*/
void display(int n,int i)  // data freq must be global
{
	printf("%d\n%d\n",n+1,data[i].k);
	do	
	{	
		i=lis[i];
		printf("%d\n",data[i].k);
	}while(lis[i]);
	
}	
/*--------------DP Longest Increasing Subsequence--------------*/
/*--(data_array, LIS_freq_array, element, LIS_starting_index)--*/
int dp_lis(int n,int &index) //data freq assumed as global
{
	int i,j,u,v, maxlen=0;
	index=n-1;
	for(i=n-2;i>=0;i--)
		{
		u=data[i].x;
		v=data[i].y;		
		for(j=i+1;j<n;j++)
			{
			if(u<data[j].x&&v>data[j].y&&freq[i]<freq[j]+1)//to take last equal LIS "freq[i]<=freq[j]+1"
				{
				lis[i]=j;
				freq[i]=freq[j]+1;
				}
			}
		if(freq[i]>maxlen)
			{
			maxlen=freq[i]; index=i;
			//m=n-maxlen;
			}
		}
	return maxlen;
}	
/*---------------------------main Function-------------------------*/
void main()
{
//freopen("in.txt","r",stdin);
	
	int n,index;

	int p[R]={0}, l[R]={0};  
	freq=p; lis=l;
		
	n=input();
	
	sort(data,data+n,compare);
		
	n=dp_lis(n,index);
	display(n,index);
}	