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
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete from beginning
void deleteBeginning(Node* &Head) {
    if (Head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = Head;
    Head = Head->next;

    if (Head != NULL)
        Head->prev = NULL;

    delete temp;
}

// Delete from end
void deleteEnd(Node* &Head) {
    if (Head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (Head->next == NULL) {
        delete Head;
        Head = NULL;
        return;
    }

    Node* temp = Head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    delete temp;
}

// Delete specific value
void deleteValue(Node* &Head, int key) {
    if (Head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = Head;

    // If head is the node to delete
    if (temp->data == key) {
        deleteBeginning(Head);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    // If last node
    if (temp->next == NULL) {
        deleteEnd(Head);
        return;
    }

    // Middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}

// Display list
void display(Node* Head) {
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* Head = NULL;

    insertBeginning(Head, 10);
    insertBeginning(Head, 20);
    insertBeginning(Head, 30);
    insertEnd(Head, 5);

    cout << "Original List:\n";
    display(Head);

    deleteBeginning(Head);
    cout << "After deleting beginning:\n";
    display(Head);

    deleteEnd(Head);
    cout << "After deleting end:\n";
    display(Head);

    deleteValue(Head, 10);
    cout << "After deleting value 10:\n";
    display(Head);

    return 0;
}