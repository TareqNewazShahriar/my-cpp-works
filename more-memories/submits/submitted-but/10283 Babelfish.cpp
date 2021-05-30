#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
#define R 11
#define MAX 100001
/***********************************************/
char find[R];
int n,pos;
struct MAKE
	{	
	char eng[R],syn[R]; 
	} dic[MAX];
/***********************************************/
void _quicksort_(MAKE data[], int n);
int binary_search(MAKE ar[],int n,char s[]);

int _compare(const void *a, const void *b)
{
	MAKE *x=(MAKE *)a, *y=(MAKE *)b; 
	return strcmp(x->syn,y->syn);
}
/***********************************************/
void main()
{
//freopen("10282.txt","r",stdin);
n=0; find[1]=0;
do
{	scanf("%s%s%[\n]",dic[n].eng,dic[n].syn,find);
	n++;
}while(find[1]!=10);
//qsort(dic,n,sizeof(dic[0]),_compare);
_quicksort_(dic,n-1);
while(scanf("%s",find)!=EOF)
{
	pos=binary_search(dic,n,find);
	if(pos!=-1)
		puts(dic[pos].eng);
	else puts("eh");
}}		
/*------Binary Search(array, total_element, searching_number)--------*/
int binary_search(MAKE ar[],int n,char s[])
{   int i=n/2,ini=0;
	if(strcmp(ar[0].syn,s)==0) return 0;  else if(strcmp(ar[n-1].syn,s)==0) return (n-1);
	while(n-ini>1)
	{	if(strcmp(ar[i].syn,s)==0)
			return i;
		else
		{	if(strcmp(ar[i].syn,s)<0) { ini=i; i=(i+n)/2; }
			else { n=i; i=(ini+i)/2; }
		}
	}
	return -1;//useless
}		
/*--Quick sort Standard pivot algorithm ( data_array, elements-1 )--*/
void _quicksort_(MAKE data[], int n)
{	
	int i=0,j=1; char pivot[11]; MAKE tmp;
	
	strcpy(pivot,data[j].syn);
	
	while(j<=n)
	{	
		if(strcmp(data[j].syn,pivot)<=0)
		{	tmp=data[j]; data[j]=data[i]; data[i++]=tmp; }
		j++;
	}
	//if(i==n) return; else
	tmp=data[j]; data[j]=data[i]; data[i++]=tmp;
	
	/* Sorting first half */
	if(i>3) _quicksort_(data, i-1);
	else if(i==3)
	{	
		if(strcmp(data[0].syn,data[1].syn)>0)
			{ tmp=data[0]; data[0]=data[1]; data[1]=tmp; }
		if(strcmp(data[1].syn,data[2].syn)>0)
		{	
			tmp=data[1]; data[1]=data[2]; data[2]=tmp;
			if(strcmp(data[0].syn,data[1].syn)>0)
			{	tmp=data[0]; data[0]=data[1]; data[1]=tmp; }
	}	}
	else if(i==2&&strcmp(data[0].syn,data[1].syn)>0)
	{	tmp=data[0]; data[0]=data[1]; data[1]=tmp; }
	
	/* Sorting second half */
	if(j=n-i>3) _quicksort_(data, n-i);
	else if(j==3)
	{	
		MAKE *item=&data[n-i];
		
		if(strcmp(item[0].syn,item[1].syn)>0)
		{	tmp=item[1]; item[1]=item[0]; item[0]=tmp; }
		if(strcmp(item[1].syn,item[2].syn)>0)
		{	
			{	tmp=item[1]; item[1]=item[2]; item[2]=tmp; }
			if(strcmp(item[0].syn,item[1].syn)>0)
			{	tmp=item[1]; item[1]=item[0]; item[0]=tmp; }
	}	}
	else if(j==2)
	{	
		MAKE *item=&data[n-i];
		
		if(strcmp(item[0].syn,item[1].syn)>0)
		{	tmp=item[1]; item[1]=item[0]; item[0]=tmp; }
	}
}//_quicksort_