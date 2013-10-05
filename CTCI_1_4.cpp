// 1.4 Write a method to decide if two strings are anagrams or not.

#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
using std::string;

bool isAnagram1(string s1, string s2)
{
	if ( s1.empty() && s2.empty() )
		return false;

	int len = s1.length();
	if ( len != s2.length() )
		return false;

	std::sort(&s1[0], &s1[0] + len);
	std::sort(&s2[0], &s2[0] + len);

	return s1 == s2;
}

bool isAnagram2(string s1, string s2)
{
	if ( s1.empty() && s2.empty() )
		return false;

	int len = s1.length();
	if ( len != s2.length() )
		return false;

	int count[256];
	memset(count, 0, sizeof(count));

	for ( int ii=0; ii<len; ++ii )
	{
		++count[(int)s1[ii]];
		--count[(int)s2[ii]];
	}

	return std::accumulate(count, count + 256, 0) == 0;
}

int main()
{
	printf("%d\n", isAnagram2("abc", "cba"));
	printf("%d\n", isAnagram1("abcd", "ecbad"));

	return 0;
}



