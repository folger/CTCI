// 1.6 Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
// write a method to rotate the image by 90 degrees. Can you do this in place?

#include <iostream>

template <int N>
static void rotate90(int a[][N])
{
	for ( int ii=0; ii<N-1; ++ii )
	{
		for ( int jj=ii+1; jj<N; ++jj )
		{
			std::swap(a[ii][jj], a[jj][ii]);
		}
	}

	for ( int ii=0; ii<N/2; ++ii )
	{
		for ( int jj=0; jj<N; ++jj )
		{
			std::swap(a[ii][jj], a[N-ii-1][jj]);
		}
	}
}

int main()
{
	int a[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

	rotate90(a);

	int N = sizeof(a[0]) / sizeof(a[0][0]);
	for ( int ii=0; ii<N; ++ii )
	{
		for ( int jj=0; jj<N; ++jj )
		{
			std::cout << a[ii][jj] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
