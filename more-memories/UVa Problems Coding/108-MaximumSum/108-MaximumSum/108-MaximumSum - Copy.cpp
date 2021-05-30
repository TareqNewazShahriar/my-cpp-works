#include "stdafx.h"
//#include<stdio.h>

#define T char
#define N 101
#define S 1
/*---------------globals--------------*/
// * 'row_sum[][]' is not for any check or main logic, just for storing single row data
T nums[N][N], sums[N][N], row_sum[N][N];

/*---------------functions--------------*/
void input(int n)
{
	T i, j;
	for (i = 1; i < n; i++)
		for (j = 1; j < n; j++)
			scanf("%d", &nums[i][j]);
}

int find_max_rectangle(int n)
{
	T max, current_cell, top_sum, current_row_sum, a, b, i, j;

	max = nums[1][1];
	for (a = 1; a < n; a++)
	{
		for (b = 1; b < n; b++)	// i, j is top-left point of current rectangle
		{	
			for (j = a; j < n; j++) // column. increase the width of rectengle
			{
				i = a;
				row_sum[i][j-1] = 0;
				sums[i-1][j] = 0;
				for (; i < n; i++) // row. increase the height of the rectangle
				{
					row_sum[i][j] = row_sum[i][j - 1] + nums[i][j];
					sums[i][j] = sums[i - 1][j] + row_sum[i][j];
					
					if (sums[i][j]>max)
						sums[i][j] = max;
				}
			}

		}
	}
	return max;
}

/*---------------Main--------------*/
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	int n, max;
	while (scanf("%d", &n) != EOF)
	{
		input(n);
		max = find_max_rectangle(n);
		printf("%d\n", max);
	}

	return 0;
}
