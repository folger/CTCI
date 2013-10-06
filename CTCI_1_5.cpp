// 1.5 Write a method to replace all spaces in a string with '%20'

#include "stdio.h"
#include "string.h"

static int CountSpaces(const char* str)
{
	int count = 0;
	int len = strlen(str);
	for ( int ii=0; ii<len; ++ii )
	{
		if ( str[ii] == ' ' )
			++count;
	}
	return count;
}

static void ReplaceSpaces(char* str)
{
	int len = strlen(str);
	int pos = len + 2 * CountSpaces(str);

	str[pos--] = '\0';
	for ( int ii=len-1; ii>=0; --ii )
	{
		if ( str[ii] == ' ' )
		{
			str[pos-2] = '%';
			str[pos-1] = '2';
			str[pos] = '0';
			pos -= 3;
		}
		else
		{
			str[pos] = str[ii];
			--pos;
		}
	}
}

int main()
{
	char s[100] = "F o lg er";
	ReplaceSpaces(s);
	printf("%s\n", s);
	return 0;
}

