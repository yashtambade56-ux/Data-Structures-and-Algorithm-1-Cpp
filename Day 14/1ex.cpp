#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;
void enqueue(int value) {
    if(rear == SIZE - 1) {
        cout << "Queue Overflow";
    } else {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = value;
    }
}

void dequeue() {
    if(front == -1 || front > rear) {
        cout << "Queue Underflow";
    } else {
        cout << "Dequeued: " << queue[front] << endl;
        front++;
    }
}

void display() {
    if(front == -1) {
        cout << "Queue is empty";
    } else {
        cout << "Queue elements: ";
        for(int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    
    dequeue();
    dequeue();
    display();

    return 0;
}