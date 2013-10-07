#include <iostream>
#include "myList.h"

void remove_node(node*& p)
{
	node* ptemp = p;
	p = p->next;
	delete ptemp;
}

void append_list(node*& pDest, node* pSource)
{
	node** pp = &pDest;
	while ( *pp )
	{
		pp = &(*pp)->next;
	}
	while ( pSource )
	{
		*pp = new node;
		(*pp)->data = pSource->data;
		(*pp)->next = nullptr;
		pp = &(*pp)->next;

		pSource = pSource->next;
	}
}

void print_list(node* p)
{
	while ( p )
	{
		std::cout << p->data << "->";
		p = p->next;
	}
	std::cout << "NULL" << std::endl;
}

myList::myList(node::VALUE_TYPE* arr, int n) : head(nullptr)
{
	node** pp = &head;
	for ( int ii=0; ii<n; ++ii )
	{
		*pp = new node;
		(*pp)->data = arr[ii];
		(*pp)->next = nullptr;
		pp = &(*pp)->next;
	}
}

myList::~myList()
{
	node* p = head;
	if ( p )
	{
		std::cout << "List Remains :" << std::endl;
		while ( p )
		{
			std::cout << p->data << std::endl;

			remove_node(p);
		}
	}
}
