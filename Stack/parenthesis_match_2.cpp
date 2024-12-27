#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& expression) {
    stack<char> s;

    for (char c : expression) {

        if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalanced(expression)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }

    return 0;
}
