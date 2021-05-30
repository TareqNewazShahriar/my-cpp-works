#include<stdio.h>
#include<stdlib.h>
/*--------------------------------------------*/
int n;
void selection_sort(char *ar);
/*--------------------------------------------*/
void main()
{
//freopen("F:\\Programming\\Problems Coding\\pACM Problems Coding\\in08.txt","r",stdin);
	int cs,csn=0;
	char ch, name[]="AJAJAJAJAJASASASASASABABABABABAKAKAKAKAKATUTUTUTUTUCUCUCUCUCULULULULULUDUDUDUDUDUMUMEMEMEMEVEVEVEVEVENENENENENEWEWEWEWEWEFEFEFOFOFOXOXOXOXOXOGOGOGOGOGOPOPOPOPOPOYOYOYOYIYIHIHIHIHIHIQIQIQIQIQIZIZIZIZIZIRIRIRIRIR";
//////////////////////////////////////////////////////////////
//	char vowel[]="AUEOI", conso[]="JSBKTCLDMVNWFXGPYHQZR";	//
//	int i,n; bool q=1;														//
//	for(i=0;i<211;i++)										//
//	{														//
//		if(q)												//
//		{	len++; q=0;										//
//			name[i]=vowel[cs];								//
//			if(len==21) len=0,cs++;							//
//		}													//
//		else												//
//		{	n++; q=1;										//
//			name[i]=conso[csn];								//
//			if(n==5) n=0,csn++;								//
//	}	}													//
//	puts(name);												//
//////////////////////////////////////////////////////////////

	for(scanf("%d",&cs);cs;cs--)
	{
		scanf("%d",&n);
		ch=name[n]; name[n]=0;
		selection_sort(name);
		n--; selection_sort(name+1);
		
		printf("Case %d: %s\n",++csn,name);
		name[n+1]=ch;
	}
}
/*-----------------------------------------------*/
/*-------------------Selection sort(int_array,element)--------------------*/
void selection_sort(char *ar)
{   int i,j, m=n-1, low,indx,tmp;
	for(i=0;i<m;i+=2)
	{   
		low=*(ar+i); indx=i;
		for(j=i+2;j<n;j+=2)
		{	
			if(*(ar+j)<low)
			{	low=(*(ar+j)); indx=j; }
		}
		tmp=ar[i]; ar[i]=ar[indx]; ar[indx]=tmp;
	}	
}		