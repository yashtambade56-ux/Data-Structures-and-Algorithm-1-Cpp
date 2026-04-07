// sloth student marks and name with bubble sort

#include <iostream>
using namespace std;

void bubbleSort(string name[], int marks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (marks[j] > marks[j + 1]) {
                // swap marks
                int tempMarks = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = tempMarks;

                // swap names
                string tempName = name[j];
                name[j] = name[j + 1];
                name[j + 1] = tempName;
            }
        }
    }
}

int main() {
    string name[] = {"Rohan", "Raj", "Riya", "Ravi"};
    int marks[] = {78, 92, 65, 85};

    int n = sizeof(marks) / sizeof(marks[0]);

    bubbleSort(name, marks, n);

    cout << "Sorted Students by Marks:\n";
    for (int i = 0; i < n; i++) {
        cout << name[i] << " - " << marks[i] << endl;
    }

    return 0;
}