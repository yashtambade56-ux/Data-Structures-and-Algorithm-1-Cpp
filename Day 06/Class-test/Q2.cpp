// Write a program to swap two numbers using a third variable.

#include <iostream>
using namespace std;

int main() {
    int num1, num2, temp;
    cout << "Enter 1st numbers: ";
    cin >> num1;
    cout << "Enter 2nd numbers: ";
    cin >> num2;
    

    temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "Swapped numbers: " << num1 << " " << num2 << endl;

    return 0;
}