
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare_ascending(const char *a, const char *b)
{
	return strcmp(a,b);
}


int main()
{
	//freopen("in 10420.txt","r",stdin);

	const int S=30, R = 2000;
	int n, i, count;
	char countries[R][S], name[S];
	
	while(scanf("%d",&n)==1)
	{
		//i have to check it later. so why later?
		//check it now and save time
		if(n ==0) continue;

		// input countries
		for(i=0; i<n; i++)
		{
			scanf("%s %[^\n]", countries[i], name);
		}

		//sort countries
		qsort( (void *)countries,
				n,
				sizeof(countries[0]),
				( int (*)(const void *,const void *))compare_ascending );

		//check country names, count and output
		count=1;
		for(i=1; i<n; i++)
		{
			if(strcmp(countries[i-1],countries[i]) ==0)
				count++;
			else
			{
				printf("%s %d\n", countries[i-1], count);
				count =1;
			}
		}

		//the last country and count will not be outputted
		//in the loop above, though it was counted. so output
		//it separately. it will work when there has only 1 input
		printf("%s %d\n", countries[n-1], count);
	}
   return 0;
}
