#include<stdio.h>

#define OPTION 6
#define _SIZE  20
/********************Global Vriables********************/
/*****************Functions Prototype*******************/
int presentation(int n,char options[OPTION][_SIZE]);
/********************Main Function**********************/
void main()
{
}

void main()
{
	char options[OPTION][_SIZE]={"Add","Delete","Insert","Total","Exit"}

}


/*-------Presenting, animating menu options in a line---------------
-------(INT number_of_options, STRING options_2D_string)------------*/
int presentation(int n,char options[OPTION][_SIZE])
{
	char a,c, spc[5]="    "; int i;

// Counting total space for menu
	for(i=0, a=0;a<n;a++) i+=strlen(options[a]);
	i=80-(i+(n*2));

	if(i>=n*3) spc[3]=0;
	else spc[1]=0;

// Animating the menu
	c=0;
	do
	{	printf("\r%s",spc);
		for(i=0;i<n;i++)	// printing the options
		{
			printf("%s[",spc);
			if(i==c) putchar(' ');
			printf("]%s",options[i]);
		}
		printf("\r%s",spc);	// placing the cursor to
		for(i=0;i<=c;i++)	// the active option
		{
			printf("%s[",spc);
			if(i==c) break;
			printf("]%s",options[i]);
		}
		a=move_cursor(c);
	}while(a!=10);
	printf("û\n");
	
	return c;  // return the value of chosen option
}
