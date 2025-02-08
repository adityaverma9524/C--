#include <iostream>
using namespace std;

class Node{ 
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* takeInput() {
    int data;
    cin >> data; // Read first element

    Node* head = NULL;
    Node* tail = NULL;

    while(data != -1) { // -1 to terminate input 
        Node* newNode = new Node(data); // create new node

        if(head == NULL) { // if list is empty
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode; // append at end
            tail = newNode; // update tail
        }
        cin >> data;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}