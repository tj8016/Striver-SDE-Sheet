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


ListNode* middleNode(ListNode* head) {
    ListNode* p1=head;
    ListNode* p2=head;
    
    if(head == NULL) {
        return NULL;
    }
    
    while(p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    return p1;
}

int main() {
    
    return 0;
}