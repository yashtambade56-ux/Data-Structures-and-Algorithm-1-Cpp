// 
#include<iostream>
using namespace std;

#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

void enqueue(int value){
    if((rear + 1) % SIZE == front){
        cout<<"Queue Overflow\n";
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        q[rear] = value;
    }
    else{
        rear = (rear + 1) % SIZE;
        q[rear] = value;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        cout<<"Queue Underflow\n";
    }
    else if(front == rear){
        cout<<"Deleted: "<<q[front]<<endl;
        front = rear = -1;
    }
    else{
        cout<<"Deleted: "<<q[front]<<endl;
        front = (front + 1) % SIZE;
    }

}

void display(){
    if(front == -1 && rear == -1){
        cout<<"Queue is Empty\n";
    }
    else{
        int i = front;
        while(true){
            cout<<q[i]<<" ";
            if(i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout<<endl;
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);

    display();

    dequeue();
    dequeue();

    display();


    display();

    return 0;
}