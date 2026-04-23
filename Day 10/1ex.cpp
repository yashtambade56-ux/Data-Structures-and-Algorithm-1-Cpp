#include <iostream>
using namespace std;

#define max 5

class Stack {
    int arr[max];
    int top;

public:
    Stack(){
        top = -1;
    }

    void push(int x) {
        if (top == max - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack\n";
    }

    void pop(){
        if (top == -1) {
            cout << "Stack underflow\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }

    void display(){
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();


    s.pop();
    s.display();
    s.peek();


    return 0;

}