/*
	1. make first row and column empty to avoid outOfIndex checking
	2. assign 0 (zero) to every .(dot) 
	3. if '*' found, +1 all surrounding cells
	4. before output, assign null to the proper position of each row.
	5. do not print extra newline after last output; it will be considered as WA
*/

//#include "stdafx.h" /*
#include <stdio.h> //*/

#define S 102

void input(int x, char field[S][S])
{
	for (int i = 1; i <= x; i++)
	{
		gets(field[i]+1);
	}
}

void makeDotZero(int x, int y, char field[S   ][S])
{
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y; j++)
		{
			if(field[i][j]!='*')
				field[i][j] = '0';
		}
	}
}

void output( int count, int x, int y, char field[S][S])
{
	printf("Field #%d:\n", count);
	for (int i = 1; i <= x; i++)
	{
		field[i][y+1] = 0;
		puts(field[i]+1);
	}
}

void minesweeper(int x, int y, char field[S][S])
{
	int i,j;
	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			if(field[i][j]=='*')
			{
				if(field[i+1][j] != '*')	// 1 right
					field[i+1][j]++;
				if(field[i+1][j-1] != '*')	// 2 bottom-right
					field[i+1][j-1]++;
				if(field[i][j-1] != '*')	// 3 bottom
					field[i][j-1]++;
				if(field[i-1][j-1] != '*')	// 4 bottom-left
					field[i-1][j-1]++;
				if(field[i-1][j] != '*')	// 5 left
					field[i-1][j]++;
				if(field[i-1][j+1] != '*')	// 6 top-left
					field[i-1][j+1]++;
				if(field[i][j+1] != '*')	// 7 top
					field[i][j+1]++;
				if(field[i+1][j+1] != '*')	// 8 top-right
					field[i+1][j+1]++;
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int x,y, count;
	char newLine[S];
	bool q = false;

	scanf("%d%d", &x, &y);
	gets(newLine);
	count=1;
	while (x!=0 && y!=0)
	{
		// print new line between output, if there has next input
		if(q==true)
			puts("");
		q=true;

		char field[S][S] = {{0}};

		input(x,field);
		makeDotZero(x,y,field);
		minesweeper(x,y,field);
		output(count, x, y, field);
		

		scanf("%d%d", &x, &y);
		gets(newLine);
		count++;
	}
	return 0;
}
