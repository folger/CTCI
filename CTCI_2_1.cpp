// 2.1 Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP How would you solve this problem if a temporary buffer is not allowed?

#include <set>
#include <iostream>
#include "myList.h"

static void removeduplicate1(node* head)
{
	std::set<node::VALUE_TYPE> has;

	node** pp = &head;
	while ( *pp )
	{
		if ( has.find((*pp)->data) == has.end() )
		{
			has.insert((*pp)->data);
			pp = &(*pp)->next;
		}
		else
		{
			remove_node(*pp);
		}
	}
}

static void removeduplicate2(node* head)
{
	node* pcurr = head;
	while ( pcurr )
	{
		node** pp = &pcurr->next;
		while ( *pp )
		{
			if ( (*pp)->data == pcurr->data )
			{
				remove_node(*pp);
			}
			else
			{
				pp = &(*pp)->next;
			}
		}
		pcurr = pcurr->next;
	}
}

int main()
{
	int data[] = {10, 20, 20, 30, 40, 10, 50};

	myList list(data, sizeof(data)/sizeof(data[0]));

	removeduplicate1(list.Head());
	removeduplicate2(nullptr);

	return 0;
}
