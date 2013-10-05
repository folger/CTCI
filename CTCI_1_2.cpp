// 1.2 Write code to reverse a C-Style String.
// (C-String means that “abcd” is represented as five characters, including the null character.)

#include "stdio.h"
#include "string.h"
#include <algorithm>

const char* reverse_str(char* str)
{
	int len = strlen(str);
	for ( int ii=0; ii<len/2; ++ii )
	{
		char cc = str[ii];
		str[ii] = str[len-ii-1];
		str[len-ii-1] = cc;
	}
	// std::reverse(str, str+len);
	return str;
}

int main()
{
	char s[] = "Foolger";
	printf("reverse_str(): %s\n", reverse_str(s));
	return 0;
}
