#include<stdio.h>
#define R 14

void load_jos(long *josp);

void main()
{	//long i,j, y, count;
	long x,josp[R]={0,2,7,5,30};
	load_jos(josp);//printf("\n");	
	while(scanf("%ld",&x)!=EOF)
	{	if(x==0) break;
		printf("%ld\n",josp[x]);
		/*else if(x==1) printf("2\n");
		else if(x==2) printf("7\n");
		else if(x==3) printf("5\n");
		else	  //*/
		//e
	}//w
}//m

void load_jos(long *jos)
{	int j,i, y,x,count;
	for(x=5;x<14;x++)
	{	y=x*2;
		for(j=169;j<9999999;j++)
		{	count=y; i=j%count;
			while(count>x)
			{	if(i==0) i=j%--count;// count--;
				else if(i>x) i=(j-count+i)%--count;// count--;
				else break;
			}//w
			if(count==x) { *(jos+x)=j; break; }
		}//2 f
	}//1 f
}//lo			