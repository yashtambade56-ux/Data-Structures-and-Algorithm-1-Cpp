#include <iostream>
using namespace std;

void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    string fruits[] = {"Mango", "Apple", "Banana", "Orange","Blueberry","Blackberry"};
    int n = sizeof(fruits) / sizeof(fruits[0]);

    bubbleSort(fruits, n);

    cout << "Sorted fruits: \n";
    for (int i = 0; i < n; i++) {
        cout << fruits[i] << " ";
    }

    return 0;
}