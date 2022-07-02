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

int getlength(ListNode* head) {
    int count = 0;
    ListNode* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL || n ==0)return head;

    int length = getlength(head); 
    ListNode* prv;
    ListNode* curr = head;
    
    int count = length-n;
    
    if(count == 0) {
        return head->next;
    }
    
    while(count--) {
        prv = curr;
        curr = curr->next;
    }
    prv->next = curr->next;
    
    delete curr;
    
    return head;
    
}

int main() {
    
    return 0;
}