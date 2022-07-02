#include<iostream>
using namespace std;

class ListNode {

    //Data Member are below:
    public:
    int data;
    ListNode* next;

    //constructor
    ListNode(int data) {
        this->data  = data;
        this->next = NULL;
    }
};

// Iterative
ListNode* reverseList(ListNode* head) {

    //step 1
    ListNode* prev_p = NULL;
    ListNode* current_p = head;
    ListNode* next_p;
    
    //step 2
    while(current_p) {

        next_p = current_p->next;
        current_p->next = prev_p;
        
        prev_p = current_p;
        current_p = next_p;
    }

    head = prev_p; //step 3
    return head;
}

// Recursive
ListNode* reverseListRecursive(ListNode* &head) {

    if (head == NULL||head->next==NULL)
        return head;

    ListNode* nnode = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return nnode;
}

int main() {
    
    return 0;
}