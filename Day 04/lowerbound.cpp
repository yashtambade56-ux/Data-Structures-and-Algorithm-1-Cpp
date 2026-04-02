#include <iostream>
using namespace std;

int upperBound(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int ans = n; // default if not found

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > key) { 
            ans = mid;
            high = mid - 1; 
        }
        else {
            low = mid + 1; 
        }
    }

    return ans;
}

int main(){
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;

    int index = upperBound(arr, n, key);
    if (index < n)
        cout << "Upper bound of " << key << " is at index: " << index;
    else
        cout << "Upper bound not found";

    return 0;
}