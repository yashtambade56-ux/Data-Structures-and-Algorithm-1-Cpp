//Searching in the rotated sorted array
#include <iostream>
using namespace std;

int searchRotatedSortedArray(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; 
        }

        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            if (key >= arr[low] && key < arr[mid]) {
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }
        // Right half is sorted
        else {
            if (key > arr[mid] && key <= arr[high]) {
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
    }

    return -1; 
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 0;

    int result = searchRotatedSortedArray(arr, n, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}