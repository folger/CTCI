// 1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.

#include "memory.h"

void set_zeros(int** a, int m, int n)
{
	bool row[m], col[n];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));

	for ( int ii=0; ii<m; ++ii )
	{
		for ( int jj=0; jj<n; ++jj )
		{
			if ( a[ii][jj] == 0 )
			{
				row[ii] = col[jj] = true;
			}
		}
	}

	for ( int ii=0; ii<m; ++ii )
	{
		for ( int jj=0; jj<n; ++jj )
		{
			if ( row[ii] || col[jj] )
			{
				a[ii][jj] = 0;
			}
		}
	}	
}

int main()
{
	return 0;
}
