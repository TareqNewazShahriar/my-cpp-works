#include<stdio.h>

#define T int
#define N 101

/*---------------globals--------------*/
// * 'row_sum[][]' is not for any check or main logic, just for storing single row data
T sums[N][N], row_sum[N][N];
char nums[N][N];

/*---------------functions--------------*/
void input(T n)
{
	T i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &nums[i][j]);
}

int find_max_rectangle(T n)
{
	T max, top_sum, a, b, i, j;

	max = nums[1][1];
	for (a = 1; a <= n; a++)
	{
		for (b = 1; b <= n; b++)	// i, j is top-left point of current rectangle
		{	
			for (j = b, i=a-1; j <= n; j++) row_sum[i][j] = 0; // blank the all row_sum that going to be evaluated in next i,j loops
			for (i = a; i <= n; i++) // increase the height of rectengle
			{	
				sums[i][b-1] = 0;
				for (j = b; j <= n; j++) // increase the width of the rectangle
				{
					row_sum[i][j] = row_sum[i-1][j] + nums[i][j];
					sums[i][j] = sums[i][j-1] + row_sum[i][j];
					
					if (sums[i][j]>max)
						max = sums[i][j];
				}
			}
		}
	}
	return max;
}

/*---------------Main--------------*/
int main()
{
	freopen("in.txt", "r", stdin);      freopen("out.txt", "w", stdout);
	
	T n, max;
	while (scanf("%d", &n) != EOF)
	{
		input(n);
		max = find_max_rectangle(n);
		printf("%d\n", max);
	}
	return 0;
}
