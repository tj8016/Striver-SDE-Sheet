#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;
        ListNode(int val) {
            data = val;
            next = NULL;
        }
};

//utility function to insert node at the end of the linked list
void insertNode(ListNode* &head,int val) {
    ListNode* newNode = new ListNode(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    ListNode* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

bool isPalindrome(ListNode* head) {
    
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prv = NULL;
    ListNode* temp = NULL;
    //finding mid ans pushing value in a stack
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        temp = slow->next;
        slow->next = prv;
        prv = slow;
        slow = temp;
    }
    
    slow = (fast ? slow -> next : slow); //if odd or even
    
    while(slow != NULL) {
        if(prv->data != slow->data) return false;
        
        prv = prv->next;
        slow = slow->next;
    }
    
    return true;
}

int main() {
    // creation of both lists 
    ListNode* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,3);
    insertNode(head,1);

    cout << isPalindrome(head) << endl;
    return 0;
}