#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* Head = NULL;

void insertBeginning(int X) {
    Node* newNode = new Node();
    newNode->data = X;
    newNode->next = Head;
    Head = newNode;
}

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

void display() {
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->data << "-";
        temp = temp->next;
    }
    cout << "Null\n";
}

int main() {
    insertBeginning(30);
    insertBeginning(20);
    insertBeginning(10);
    insertEnd(40);

    display();

}


