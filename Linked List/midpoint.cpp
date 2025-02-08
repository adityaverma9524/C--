#include "LinkedList.h"

Node* findMidPoint(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    cout << "Enter elements(-1 to stop): ";
    Node* head = takeInput();

    cout << "Linked List: ";
    print(head);

    cout << "Mid point of Linked List: ";
    Node* midpoint = findMidPoint(head);
    if(midpoint != NULL) {
        cout << midpoint->data << endl;
    }    
}