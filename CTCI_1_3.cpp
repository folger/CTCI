// 1.3 Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer.
// NOTE: One or two additional variables are fine. An extra copy of the array is not.
// FOLLOW UP Write the test cases for this method.

#include "stdio.h"
#include "string.h"

/// O(n)
void RemoveDuplicate1(char* str)
{
	int test[8];
	memset(test, 0, sizeof(test));

	int len = strlen(str);
	int jj = 0;
	for ( int ii=0; ii<len; ++ii )
	{
		int group = str[ii] / 32;
		int bit = 1 << (str[ii] % 32);
		if ( test[group] & bit )
			continue;

		test[group] |= bit;
		if ( ii != jj )
			str[jj] = str[ii];
		++jj;
	}
	str[jj] = '\0';
}

/// O(n^2)
void RemoveDuplicate2(char* str)
{
	int len = strlen(str);
	int p = 0;
	for ( int ii=0; ii<len; ++ii )
	{
		if ( str[ii] != '\0' )
		{
			str[p++] = str[ii];
			for ( int jj=ii+1; jj<len; ++jj )
			{
				if ( str[jj] == str[ii] )
					str[jj] = '\0';
			}
		}
	}
	str[p] = '\0';
}

int main()
{
	char s[] = "Foolgggerr";
	RemoveDuplicate2(s);
	printf("%s\n", s);
	return 0;
}

