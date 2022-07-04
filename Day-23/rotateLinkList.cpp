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

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode* curr = head;
    ListNode* prv = NULL;
    ListNode* last = head;
    int count = 1;
    while(last->next != NULL) {
        count++;
        last = last->next;
    }
    
    k = (k%count);
    
    if(k == 0) return head;
    
    int n = count-k;
    for(int i=0; i<n; i++) {
        prv = curr;
        curr = curr->next;
    }
    
    last->next = head;
    head = curr;
    prv->next = NULL;
    
    return head;
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
    insertNode(head,3);
    insertNode(head,6);
    insertNode(head,10);
    
    ListNode* head1 = rotateRight(head, 3);

    printList(head1);
    return 0;
}