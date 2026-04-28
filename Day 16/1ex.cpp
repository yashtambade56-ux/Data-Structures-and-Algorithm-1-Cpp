#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* Head = NULL;

// Insert at end
void insertEnd(int X) {
    Node* newNode = new Node();
    newNode->data = X;
    newNode->next = NULL;

    if (Head == NULL) {
        Head = newNode;
        return;
    }

    Node* temp = Head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Delete from beginning
void deleteBegin() {
    if (Head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = Head;
    Head = Head->next;
    delete temp;
}

// Delete from end
void deleteEnd() {
    if (Head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // Only one node
    if (Head->next == NULL) {
        delete Head;
        Head = NULL;
        return;
    }

    Node* temp = Head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Display list
void display() {
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    cout << "List after insertion\n";
    display();

    deleteBegin();
    cout << "List after deleting from beginning\n";
    display();

    deleteEnd();
    cout << "List after deleting from end\n";
    display();

    return 0;
}