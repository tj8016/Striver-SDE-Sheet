#include<iostream>
using namespace std;
class ListNode {

    //Data Member are below:
    public:
    int val;
    ListNode* next;

    //constructor
    ListNode(int data) {
        this->val  = data;
        this->next = NULL;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    
    int carry=0;
    while(l1 != NULL || l2 != NULL || carry != 0) {
        int sum = 0;
        if(l1!=NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2!=NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        sum += carry;
        carry = sum/10;
        
        ListNode *node = new ListNode(sum%10);
        temp->next = node;
        temp = temp->next;
    }
    temp->next = NULL;
    return dummy->next;
}

int main() {
    
    return 0;
}