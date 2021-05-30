#include<stdio.h>
#define R 1000

int data[R],*pre,k, q=0;

/*---------------------------- Function----------------------------*/
int input()
{
	int n;  char str[10]="";
	
	for(n=0; scanf("%d%[\n]",data+n,str)!=EOF&&str[1]!=10; n++);

	while(str[2]==10) // str[2]=='\n'
	{
		printf("Max hits: 0\n\n");
		input();
	}
	if(str[1]==10) return n+1;
	return n;
}	
/*---------Just display the L.I.Sequence(sequence_length, starting_index)----------*/
void display(int k,int i)
{
	int x;
	printf("Max hits: %d\n%d\n",k+1,data[i]);
	k--;
	x=data[i];
	for(i++;k>=0;i++)
	{
		if(x<data[i]&&pre[i]==k)
		{
			printf("%d\n",data[i]);
			x=data[i];
			k--;
		}
	}
}	
/*---------------------------- Function----------------------------*/
int DP_LIS(int n,int &index)
{
	int i,j,x, maxlen=0;
	
	for(i=n-1;i>-1;i--)
	{
		x=data[i];
		for(j=i+1;j<n;j++)
		{
			if(x<data[j]&&pre[i]<=pre[j]+1) //to take subsequent equal LIS "pre[i]<=pre[j]+1"
				pre[i]=pre[j]+1;
		}
		if(pre[i]>=maxlen)
		{
			maxlen=pre[i]; index=i;
			//m=n-maxlen;
	}	}
	return maxlen;
}	
/*---------------------------main Function-------------------------*/
void main()
{
//freopen("in.txt","r",stdin);
	
	int cs,n,index;
	
	scanf("%d",&cs);
	for(;cs;cs--)
	{
		int p[R]={0};  pre=p;
		if(q) putchar(10);		q=1;
		n=input();
		n=DP_LIS(n,index);
		display(n,index);
	}
}	