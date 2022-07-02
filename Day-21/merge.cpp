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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* temp = new ListNode(0);
    ListNode* p = temp;
        
    while(list1 != NULL && list2 != NULL) {
        if(list1->data < list2->data) {
            p->next = list1;
            list1 = list1->next;
        }
        else {
            p->next = list2;
            list2 = list2->next;
        }
        p=p->next;
    }
    
    p->next = (list2 == NULL)? list1:list2;
    // if(l2 != NULL){
    //     p->next = l2;
    // }
    // if(l1 != NULL){
    //     p->next = l1;
    // }
    return temp->next;
}

int main() {
    
    return 0;
}