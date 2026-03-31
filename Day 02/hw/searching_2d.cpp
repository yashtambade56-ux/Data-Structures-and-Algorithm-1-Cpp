#include <iostream>
using namespace std;

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int key = 5;
    bool found = false;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(arr[i][j] == key) {
                cout << "Element found at (" << i << "," << j << ")";
                found = true;
                break;
            }
        }
    }

    if(!found) cout << "Element not found";

    return 0;
}