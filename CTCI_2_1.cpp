// 2.1 Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP How would you solve this problem if a temporary buffer is not allowed?

#include <set>
#include <iostream>

struct node
{
	typedef int VALUE_TYPE;
	VALUE_TYPE data;
	node* next;
};

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
			node* ptemp = *pp;
			*pp = (*pp)->next;
			delete ptemp;
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
				node* ptemp = *pp;
				*pp = (*pp)->next;
				delete ptemp;
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
	int data[] = {10, 10, 10};

	node* head = nullptr;
	node* tail = nullptr;
	for ( auto d : data )
	{
		node* p = new node;
		p->data = d;
		p->next = nullptr;
		if ( tail == nullptr )
		{
			head = tail = p;
		}
		else
		{
			tail->next = p;
			tail = p;
		}
	}

	removeduplicate1(nullptr);
	removeduplicate2(head);

	node* p = head;
	while ( p )
	{
		std::cout << p->data << std::endl;

		node* ptemp = p;
		p = p->next;
		delete ptemp;
	}

	return 0;
}
