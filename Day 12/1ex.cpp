#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluatePrefix(string exp) {
    stack<int> s;

    for( int i = exp.length() - 1; i >= 0; i--) {

        if (exp[i] == ' ')
        continue;

        if (isdigit(exp[i])) {
            s.push(exp[i] - '0');
        }
        else {
            int val1 = s.top(); s.pop();
            int val2 = s.top(); s.pop();

            switch (exp[i]) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.top();
}

int main() {
    string exp = "- + 7 3 * 2 5";
    cout << "Result =" << evaluatePrefix(exp);
    return 0;
}