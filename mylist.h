
#pragma once

struct node
{
	typedef int VALUE_TYPE;
	VALUE_TYPE data;
	node* next;
};

void remove_node(node*& p);
void append_list(node*& pDest, node* pSource);
void print_list(node* p);

class myList
{
public:
	myList(node::VALUE_TYPE* arr, int n);
	~myList();

	node* Head() const { return head; }

private:
	node* head;
};
