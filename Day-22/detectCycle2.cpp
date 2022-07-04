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

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            break;
        }
    }
    if(fast == NULL || fast->next == NULL) {
        return NULL;
    }
    
    fast = head;
    while(fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow;
}


void createCycle(ListNode* &head,int pos) {
    ListNode* ptr = head;
    ListNode* temp = head;
    int cnt = 0;
    while(temp->next != NULL) {
        if(cnt != pos) {
            ++cnt;
            ptr = ptr->next;
        } 
        temp = temp->next;
    }
    temp->next = ptr;
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
    
    createCycle(head,2);
    
    ListNode* nodeRecieve = detectCycle(head);
    if(nodeRecieve == NULL) cout<<"No cycle";
    else {
        ListNode* temp = head;
        int pos = 0;
        while(temp!=nodeRecieve) {
            ++pos;
            temp = temp->next;
        }
        cout<<"Tail connects at pos "<<pos<<endl;
    }
    return 0;
}