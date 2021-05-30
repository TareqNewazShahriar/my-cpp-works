#include<time.h>
#include<stdio.h>

void main()
	{
	clock_t start=clock(), finish; // declaring two clock_t type variable
	char begining[30], ending[30];
	
	//printf("%d",CLOCKS_PER_SEC);
	
	_strtime(begining);	
	
	for(int i=0;i<50001;i++)
		printf("\r%d",i);
	printf("\n\n");
	
	finish = clock();
	_strtime(ending); 
	
  /** write in console **/
	printf("\n %s \n %s\n",begining,ending);
	printf("\n Begin: %ld\n End: %ld\n",long(start),long(finish));

	printf("\n Duration: %ld millisecond\n",(long)(finish - start));
	printf(" Duration: %.3lf seconds\n\n", (double)(finish - start) / CLOCKS_PER_SEC);

  /** write in file **/
	freopen("run-time.txt","w",stdout);

	printf("\n %s \n %s\n",begining,ending);
	printf("\n Begin: %ld\n End: %ld\n",long(start),long(finish));

	printf("\n Duration: %ld millisecond\n",(long)(finish - start));
	printf(" Duration: %.3lf seconds\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
	}