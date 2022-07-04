#include<iostream>
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

int getLength(ListNode* head) {
    ListNode* temp = head;
    int length = 0;
    while(temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    int length = getLength(head);
    
    ListNode* prv = dummy;
    ListNode* curr;
    ListNode* nxt;
    while(length >= k) {
        curr = prv->next;
        nxt = curr->next;
        
        for(int i=1; i<k; i++) {
            curr->next = nxt->next;
            nxt->next = prv->next;
            prv->next = nxt;
            nxt = curr->next;
        }
        prv = curr;
        length -= k;
    }
    return dummy->next;
}

//utility function to print linked list created
void printList(ListNode* head) {
    while(head->next != NULL) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}

int main() {
    ListNode* head = NULL;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);

    ListNode* newHead = reverseKGroup(head, 2);

    printList(newHead);
    
    return 0;
}