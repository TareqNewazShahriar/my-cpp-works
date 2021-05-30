#include<stdio.h>
//#include<conio.h>
#define R 1000
void main()
{
long N,sum,mod; int cs=0,csn;  //char flag[R];
//freopen("in3.txt","r",stdin);
//freopen("out3.doc","a",stdout);
scanf("%d",&csn);
while(cs<csn)
{	scanf("%ld",&N); 
	//N=n; printf("%ld\t",n);
	printf("Case #%d: %ld is ",++cs,N);
	char flag[R]="";
	//if(N<R) flag[N]=1;
	
	if(N==0) puts("an Unhappy number.");
	else{
	while(N!=1)
	{	
		sum=0;
		while(N)
		{	
			mod=N%10;
			sum+=mod*mod; 
			N/=10;
		}
		N=sum; //if(N>700) { printf("\n%ld @",N); getch(); }
		if(flag[N]) break;
		else flag[N]=1;
	}
	if(N==1)	puts("a Happy number.");
	else		puts("an Unhappy number.");
	}
}
}