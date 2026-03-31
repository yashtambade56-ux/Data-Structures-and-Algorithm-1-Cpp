#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key) {
    int start = 0, end = n - 1, ans = -1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int lastOccurrence(int arr[], int n, int key) {
    int start = 0, end = n - 1, ans = -1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 2;

    cout << "First Occurrence: " << firstOccurrence(arr, n, key) << endl;
    cout << "Last Occurrence: " << lastOccurrence(arr, n, key) << endl;

    return 0;
}