#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {  
        data = val;
        next = NULL;
    }
};

Node* last = NULL;

void display() {
    if (last == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = last->next;
    cout << "Circular link list: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << "{back to start}\n";  
}

void insertAtBeginning(int val) {
    Node* newNode = new Node(val);

    if (last == NULL) {
        last = newNode;
        last->next = last;  
    } else {
        newNode->next = last->next;  
        last->next = newNode;        
    }
}

void insertAtEnd(int val) {
    Node* newNode = new Node(val);

    if (last == NULL) {
        last = newNode;
        last->next = last;  
    } else {
        newNode->next = last->next;  
        last->next = newNode;        
        last = newNode;              
    }
}

int main() {
    int n, val;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input!\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter value for element " << (i + 1) << ": ";
        cin >> val;
        insertAtEnd(val);  
    }

    display();

    return 0;
}
