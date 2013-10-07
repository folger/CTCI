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
	while ( pSource )
	{
		node* pNew = new node;
		*pNew = *pSource;
		pNew->next = nullptr;
		if ( *pp == nullptr )
		{
			*pp = pNew;
		}

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
	node* tail = nullptr;
	for ( int ii=0; ii<n; ++ii )
	{
		node* p = new node;
		p->data = arr[ii];
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
