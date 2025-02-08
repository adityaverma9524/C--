#include "LinkedList.h"

Node* merge(Node* head1, Node* head2) {
    if(!head1) return head2;
    if(!head2) return head1;

    Node* result;
    if(head1->data < head2->data) {
        result = head1;
        result->next = merge(head1->next, head2);
    } else {
        result = head2;
        result->next = merge(head1, head2->next);
    }
    return result;
}

void split(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if(!head || !head->next) return;

    Node* front;
    Node* back;
    split(head, &front, &back);

    mergeSort(&front);
    mergeSort(&back);

    *headRef = merge(front, back);
}

int main() {
    cout << "Enter elements(-1 to stop): ";
    Node* head = takeInput();

    cout << "Linked List: ";
    print(head);

    mergeSort(&head);
    cout << "Sorted Linked List: ";
    print(head);
}