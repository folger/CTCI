// 2.3 Implement an algorithm to delete a node in the middle of a single linked list,
// given only access to that node.
// EXAMPLE Input: the node ‘c’ from the linked list a->b->c->d->e
// Result: nothing is returned, but the new linked list looks like a->b->d->e

#include "myList.h"

static void remove_node_2(node* p)
{
	if ( p == nullptr || p->next == nullptr )
		return; /// ignore these two cases

	node* ptemp  = p->next;
	*p = *p->next;
	delete ptemp;
}


int main()
{
	int data[] = {1,2,3,4,5,6,7,8,9};
	myList list(data, sizeof(data)/sizeof(data[0]));

	node* p = list.Head()->next->next;

	remove_node_2(p);

	return 0;
}

