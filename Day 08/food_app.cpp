#include <iostream>
using namespace std;

struct order {
    string id;
    int time;
    string priority;
};

// display orders
void display(order arr[], int n) {
    cout << "\nID\tTime\tPriority\n";
    for(int i = 0; i < n; i++){
        cout << arr[i].id << "\t" << arr[i].time << "\t" << arr[i].priority << endl;
    }
}

// insertion sort
void insertionsort(order arr[], int n) {
    for(int i = 1; i < n; i++) {
        order key = arr[i];

        int j = i - 1;
        while (j >= 0 && arr[j].time > key.time){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// priority value
int priorityvalue(string p){
    if(p == "high") return 3;
    if(p == "medium") return 2;
    return 1;
}

// selection sort
void selectionsort(order arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int max = i;
        for(int j = i + 1; j < n; j++) {
            if(priorityvalue(arr[j].priority) > priorityvalue(arr[max].priority)) {
                max = j;
            }
        }
        order temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

// bubble sort
void bubblesort(order arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j].time > arr[j + 1].time) {
                order temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    order orders[5];

    orders[0].id = "01";
    orders[0].time = 30;
    orders[0].priority = "medium";

    orders[1].id = "02";
    orders[1].time = 30;
    orders[1].priority = "high";

    orders[2].id = "03";
    orders[2].time = 20;
    orders[2].priority = "low";

    orders[3].id = "04";
    orders[3].time = 15;
    orders[3].priority = "high";

    int n = 4;

    cout << "original orders: ";
    display(orders, n);

    insertionsort(orders, n);
    cout << "\nAfter insertion sort(time): ";
    display(orders, n);

    orders[n].id = "05";
    orders[n].time = 18;
    orders[n].priority = "medium";
    n++;

    insertionsort(orders, n);
    cout << "\nAfter Adding New Order : ";
    display(orders, n);

    selectionsort(orders, n);
    cout << "\nAfter selection sort(priority): ";
    display(orders, n);

    orders[2].id = 12;

    bubblesort(orders, n);
    cout << "\nAfter bubble sort (Update): ";
    display(orders, n);

    


    return 0;
}