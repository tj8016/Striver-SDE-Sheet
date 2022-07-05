#include <bits/stdc++.h> 
using namespace std;


class Node {
public:
	int data;
	Node* next;
    Node* random;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->random = NULL;
	}
};

Node* copyRandomList(Node* head) {
    Node* i = head;
    Node* front = head;
    
    while(i != NULL) {
        front = i->next;
        Node* copy = new Node(i->data);
        i->next = copy;
        copy->next = front;
        i = i->next->next;
    }
    
    i = head;
    while(i != NULL) {
        if(i->next != NULL) {
            if(i->random != NULL) {
                i->next->random = i->random->next;
            }
            else {
                i->next->random = i->random;
            }
        }
        if(i->next != NULL) {
            i = i->next->next;
        }
        else {
            i = i->next;
        }
    }
    
    Node* dummy = new Node(0);
    Node* temp = dummy;
    
    i = head;
    front = head;
    
    while(i != NULL) {
        front = i->next->next;
        temp->next = i->next;
        i->next = front;
        
        temp = temp->next;
        i = i->next;
    }
    
    temp->next = NULL;
    
    return dummy->next;
}

int main() {

    return 0;
}

