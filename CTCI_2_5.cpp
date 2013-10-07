// 2.5 Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
// DEFINITION Circular linked list:
// A (corrupt) linked list in which a node’s next pointer points to an earlier node,
// so as to make a loop in the linked list. EXAMPLE input: A –> B –> C –> D –> E –> C (the same C as earlier) output: C

#include <iostream>
#include "myList.h"

node* loopstart(node *head){
    if(head==NULL) return NULL;
    node *fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) break;
    }
    if(!fast || !fast->next) return NULL;
    slow = head;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

int main()
{
    int a[] = {
        9, 2, 1, 3, 5 
    };
    myList list(a, sizeof(a)/sizeof(a[0]));

    node *c = list.Head();

    c->next->next->next->next = c->next->next;

    node* p = loopstart(c);
    std::cout << p->data << std::endl;

    return 0; /// will has error when try to free list in ~myList, never mind
}
