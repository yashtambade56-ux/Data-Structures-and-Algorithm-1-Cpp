// linear search in string (pattern matching - basic) with user input

#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string p;
    cout << "Enter a pattern: ";
    cin >> p;

    int n = s.length();
    int m = p.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == m) {
        cout << "Pattern found at index " << i - j << endl;
    } else {
        cout << "Pattern not found" << endl;
    }
    return 0;
}