// find minimum number in an array of 5 numbers

#include <iostream>
using namespace std;

int main() {
    int arr[5];

    // Taking input
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    // Assume first element is minimum
    int min = arr[0];

    // Traversal + Comparison
    for (int i = 1; i < 5; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // result
    cout << "Minimum number is: " << min;

    return 0;
}