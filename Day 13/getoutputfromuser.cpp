// get output from user using stack

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> s;
    string input;

    cout << "Enter a string (type 'exit' to stop): ";
    while (true) {
        getline(cin, input);
        if (input == "exit") break;
        s.push(input);
    }

    cout << "\nYou entered:\n";
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}