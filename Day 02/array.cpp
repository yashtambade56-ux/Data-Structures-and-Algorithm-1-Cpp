#include <iostream>
using namespace std;
int main() {

    int a[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;

    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            cout << "Element found at index " << i << endl;
            return 0;
        }
    }

    cout << "Element not found" << endl;
    return 0;
}