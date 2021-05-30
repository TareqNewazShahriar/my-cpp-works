#include<stdio.h>
#include<math.h>	  
#define R 2000
void main()
{   int n[R],i,j,k,count,x;
    while(scanf("%d",&x)!=EOF)
    {   if(x==0) break;
	   for(i=1;i<2000;i++)
	   {   //int n[R]={1};
		  for(j=0;j<x;n[j]=0,j++);
		  for(j=1,count=0,k=0;count<x&&(j!=2||k!=0);j++)
		  {		if(j==x) { j=0; continue; }
				if(n[j]==0) k++;
				if(k==i) { n[j]=1; count++; k=0;}
		  }
			if(j==2&&count==x-1) break;
		}
		printf("%d\n",i);

		//for(i=1;i<x;i++) if(n[i]==0) { printf("%d\n",i+1); break; }
    }
}