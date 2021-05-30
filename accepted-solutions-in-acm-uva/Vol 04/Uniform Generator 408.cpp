#include<stdio.h>
void main()
{
	//freopen("in4.txt","r",stdin);
	long step,mod,i,seed;

	while(scanf("%ld%ld",&step,&mod)!=EOF)
	{	
		
		for(i=0,seed=0;seed=(seed+step)%mod;i++);
			//if(i==mod) {printf("err %d %d ",step,mod);break; }
		
		if(i==mod-1) printf("%10ld%10ld    Good Choice\n\n",step,mod);
		else         printf("%10ld%10ld    Bad Choice\n\n",step,mod);
	}
}