#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

// Insert at beginning
void insertBeginning(Node* &Head, int X) {
    Node* newNode = new Node();
    newNode->data = X;
    newNode->prev = NULL;
    newNode->next = Head;

    if (Head != NULL)
        Head->prev = newNode;

    Head = newNode;
}

// Insert at end
void insertEnd(Node* &Head, int X) {
    Node* newNode = new Node();
    newNode->data = X;
    newNode->next = NULL;

    if (Head == NULL) {
        newNode->prev = NULL;
        Head = newNode;
        return;
    }

    Node* temp = Head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Display list
void display(Node* Head) {
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* Head = NULL;

    insertBeginning(Head, 10);
    insertBeginning(Head, 20);
    insertBeginning(Head, 30);

    insertEnd(Head, 5);

    cout << "Doubly Linked List: ";
    display(Head);

    return 0;
}