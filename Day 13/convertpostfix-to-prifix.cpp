#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPrefix(string infix) {
    stack<char> st;
    string result = "";

    reverse(infix.begin(), infix.end());

    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    for (char c : infix) {

        if (isalnum(c)) {
            result += c;
        }

        else if (c == '(') {
            st.push(c);
        }

        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while (!st.empty() &&
                   precedence(st.top()) > precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string infix = "(A+B)*(C+D)";
    cout << "Prefix: " << infixToPrefix(infix);
    return 0;
}