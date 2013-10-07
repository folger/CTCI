// 2.2 Implement an algorithm to find the nth to last element of a singly linked list.

#include <iostream>
#include "myList.h"

node* nth_last(node* p, int& n)
{
	if ( p->next )
	{
		node* pp = nth_last(p->next, n);
		if ( pp )
			return pp;
	}

	if ( n == 1 )
		return p;
	--n;
	return nullptr;
}

node* nth_last_element(node* head, int n)
{
	if ( nullptr == head || n < 1 )
		return nullptr;

	return nth_last(head, n);
}


int main()
{
	int data[] = {1,2,3,4,5,6,7,8,9};
	myList list(data, sizeof(data)/sizeof(data[0]));

	std::cout << nth_last_element(list.Head(), 2)->data << std::endl;

	return 0;
}

