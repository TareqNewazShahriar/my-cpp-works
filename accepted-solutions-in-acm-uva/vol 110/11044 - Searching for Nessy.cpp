//11044 - Searching for Nessy.cpp
//#include "stdafx.h" /*
#include<stdio.h>	//*/
#include<math.h>

int main()
{
	//freopen("in.txt", "r", stdin);
	long n, u,v;
	scanf("%ld",&n);
	for(; n>0; n--)
	{
		scanf("%ld %ld", &u, &v);
		
		//since the 4 sides do not need to consider so
		//the grid became a (R-2)X(C-2) grid.
		u -= 2;
		v -= 2;
		
		//since a sonar beams can monitor 3x3 grids,
		//so devide the division of row and colmun  are the asnwerl
		u = ceil( u/3.0 );
		v = ceil( v/3.0 );
		printf("%ld\n", u*v);
		
		//printf("%ld\n", ((ceil((u-2)/3.0)) * (ceil((v-2)/3.0))) );
	}
	
	return 0;
}

