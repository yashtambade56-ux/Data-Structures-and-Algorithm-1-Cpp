#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[100];

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }

    for(int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int arr[5] = {38, 27, 43, 3, 9};
    int n = 5;

    cout << "Original array: ";
    disply(arr, 5);

    mergeSort(arr, 0, 4);

    cout << "Sorted array: ";
    disply(arr, 5);

    return 0;
}