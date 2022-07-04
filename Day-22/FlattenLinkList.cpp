#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

Node* mergesort(Node* l1, Node*l2) {
    Node* dummy = new Node(0);
    Node* temp = dummy;
    
    while(l1 != NULL && l2 != NULL) {
        if(l1->data < l2->data) {
            temp->child = l1;
            l1 = l1->child;
        }
        else {
            temp->child = l2;
            l2 = l2->child;
        }
        temp = temp->child;
    }
    
    if(l1) {
        temp->child = l1;
    }
    else {
        temp->child = l2;
    }
    
    temp->next = NULL;
    return dummy->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    // Base cash
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursive call
    head->next = flattenLinkedList(head->next);
    
    // mergesort
    return mergesort(head, head->next);
}
