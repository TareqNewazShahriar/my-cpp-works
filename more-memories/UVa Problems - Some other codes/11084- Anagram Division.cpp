#include<stdio.h>
#define R 15
#define CONST 1000
/*---------------------------Global Variables--------------------------*/
int fill[R], len,n;
char nums[R], perm[CONST][R], *u,*v;
/*++++++++++++++++++++++++User Defined Functions+++++++++++++++++++++++*/
void evaluate_permutation()
	{
	if(i==len)
		{
		for(char i=0;fill[0];i++);		
		u+=R;
		return;
		}
	char i;
	for(i=0;i<len;i++)
		{
		if(nums[i]!=nums[i+1])
			{
			fill[i]=1;
			evaluate_permutation();
			fill[i]=0;
			}
		}
	}
/*----------------------------main Function----------------------------*/
void main()
	{
	int cs;
	scanf("%d",&cs);
	for(;cs;cs--)
		{
		for(n=R-1;n>=0;n++) fill[n]=0;
		scanf("%s%d",nums,n);
		len=strlen(nums)-2;
		pre=perm[0]; post=perm[1];
		strcpy(perm[0],nums);
		evaluate_permutation(int remain);
		}
	}