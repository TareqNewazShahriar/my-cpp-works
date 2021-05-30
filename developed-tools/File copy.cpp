#include<stdio.h>
#include<string.h>
#include<iostream.h>

/*----------------------------------*/
#define R 10000

/*----------------------------------*/
int i=1,page=100;	
char name[3]="1", line[R];
FILE *inf, *outf;
bool flag=1;

/*----------------------------------*/
void main()
{
while(i)
{
	char  num[10], 
		*extra = "100:", 
		in[200]="http://acm.uva.es/problemset/problemstat.php?p=:";
	
	printf("The number of Problem : "); scanf("%s",num);
	
	strcat(in,num); _itoa(page,extra+4,10); strcat(in,extra); page+=100;
	
	i=surf_the_net();
	if(i)
		printf("The file is found at page %d.\n",);
	else puts("The file wasn't found.");
	
	printf("Repeat? 1 / 0 : "); 
	scanf("%d",&i);
}
}	


/*----------------------------------*/
short surf_the_net()
{
	itr=1;
	inf=fopen(in,"r");
	while(itr<12)
	{
		while(fgets(line,R,inf))
		{
			adrs=strstr(line,"user=60013");
			if(adrs)
			{	
				rewind(adrs);
				char *out="F:\\Web\\Acm Related\\Author's Files\\One Problem Statistics\\";
				char nums[15]; strcpy(nums,num);
				
				strcat(nums,".html"); 
				strcat(out,nums);
				
				outf=fopen(out,"w");
				
				while(fgets(line,R,outf))
					fputs(line,outf);
				
				return itr;
			}
		}
	}
	return itr;
}		