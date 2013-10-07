// 2.4 You have two numbers represented by a linked list, where each node contains a single digit.
// The digits are stored in reverse order, such that the 1’s digit is at the head of the list.
// Write a function that adds the two numbers and returns the sum as a linked list.
// EXAMPLE Input: (3 –> 1 –> 5) + (5 –> 9 –> 2) Output: 8 –> 0 –> 8

#include "myList.h"

node* sum_list(node* l1, node* l2)
{
	node* p = nullptr;
	if ( l1 )
	{
		append_list(p, l1);
		if ( l2 )
		{
			int nn = 0;
			node* ptemp = p;
			while ( ptemp || l2 )
			{
				int sum = ptemp->data + (l2 ? l2->data : 0) + nn;
				ptemp->data = sum % 10;
				nn = sum / 10;

				if ( ptemp->next == nullptr && l2 && l2->next != nullptr )
				{
					node* pnew = new node;
					pnew->data = 0;
					pnew->next = nullptr;
					ptemp->next = pnew;
				}

				ptemp = ptemp->next;
				if ( l2 )
					l2 = l2->next;
			}
		}
	}
	else if ( l2 )
	{
		append_list(p, l2);
	}

	return p;
}

int main()
{
	int a[] = {3,1};
	myList list1(a, sizeof(a)/sizeof(a[0]));

	int b[] = {5,9,2};
	myList list2(b, sizeof(b)/sizeof(b[0]));

	print_list(sum_list(list1.Head(), list2.Head())); /// return node* not release， never mind

	return 0;
}
