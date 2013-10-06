// 1.8 Assume you have a method isSubstring which checks if one word is a substring of another.
// Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring
// (i.e., “waterbottle” is a rotation of “erbottlewat”).


#include <iostream>
#include <string>
using std::string;

static bool isSubstring(const string& s1, const string& s2)
{
	return s1.find(s2) != string::npos;
}

static bool isRotation(const string& s1, const string& s2)
{
	if ( s1.length() != s2.length() )
		return false;

	return isSubstring(s1 + s1, s2);
}

int main()
{
	string s1 = "apple";
    string s2 = "pleap";
    std::cout<<isRotation(s1, s2)<<std::endl;
    return 0;
}

