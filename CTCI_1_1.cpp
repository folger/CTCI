// 1.1 Implement an algorithm to determine if a string has all unique characters.
// What if you can not use additional data structures?

#include "stdio.h"
#include "string.h"

bool IsUnique(const char* str)
{
	int test[8];
	memset(test, 0, sizeof(test));
	int len = strlen(str);
	for ( int ii=0; ii<len; ++ii )
	{
		int group = str[ii] / 32;
		int bit = 1 << (str[ii] % 32);
		if ( test[group] & bit )
			return false;

		test[group] |= bit;
	}

	return true;
}

int main()
{
	const char* s = "Folger";
	printf("IsUnique(%s): %d\n", s, IsUnique(s));
	return 0;
}

