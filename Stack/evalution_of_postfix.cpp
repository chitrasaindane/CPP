#include <iostream>
#include <stack>
#include <string>
#include <cmath> 
using namespace std;

int performOperation(int operand1, int operand2, char op) {
    switch(op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': return pow(operand1, operand2);  
        default: return 0;
    }
}

int evaluatePostfix(string postfix) {
    stack<int> stk;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            stk.push(c - '0');  // Convert char to int and push
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            int operand2 = stk.top(); stk.pop();
            int operand1 = stk.top(); stk.pop();
            int result = performOperation(operand1, operand2, c);
            stk.push(result);
        }
    }

    return stk.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}


















