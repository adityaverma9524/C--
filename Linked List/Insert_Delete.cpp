 #include "LinkedList.h"

Node* insertNode(Node* head, int pos, int data) {
    Node* newNode = new Node(data);

    if(pos == 0) {
        newNode->next = head;
        head = newNode;
        return newNode;
    }

    Node* temp = head;
    int count = 0;
    while(temp != NULL && count < pos-1) {
        temp = temp -> next;
        count++;
    }

    if(temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node* deleteNode(Node* head, int pos) {
    if(head == NULL) {
        return NULL;
    }

    if(pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    int count = 0;
    while(temp->next != NULL && count < pos-1) {
        temp = temp->next;
        count++;
    }

    if(temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
    return head;
}

int main() {
    cout << "Enter elements(-1 to stop): ";
    Node* head = takeInput();

    cout << "Linked List: ";
    print(head);

    int pos, data;
    cout << "Enter index to insert node: ";
    cin >> pos;
    cout << "Enter data: ";
    cin >> data;
    head = insertNode(head, pos, data);

    cout << "Linked List: ";
    print(head);

    cout << "Enter index of node to be deleted: ";
    cin >> pos;
    head = deleteNode(head, pos);

    cout << "Linked List: ";
    print(head);
}