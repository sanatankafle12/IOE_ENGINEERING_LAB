#include <iostream>
#include <math.h>
using namespace std;

#define SIZE 100

template <class T>
class Stack {
    T stack[SIZE];
    int top;

public:
    Stack() : top(-1) {}
    void push(T x) {
        if (top >= SIZE - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++top] = x;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return stack[top--];
    }

    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top >= (SIZE - 1));
    }
    T tos() {
        return stack[top];
    }

    void display() {
        for (int i = 0; i <= top; i++)
            cout << stack[i] << "\t";
        cout << endl;
    }
};


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int precedence(char c) {
    return (c == '^') ? 3 : (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : -1;
}
string toPostFix(const string &exp) {
    Stack<char> s;
    string postfix;
    for (int i = 0; i < exp.length(); i++) {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <='9'))
            postfix += exp[i];
        else if (exp[i] == '(' || exp[i] == '^')
            s.push(exp[i]);
        else if (exp[i] == ')') {
            while (s.tos() != '(')
                postfix += s.pop();
            s.pop();    // pop '('
        } else if (isOperator(exp[i])) {
            if (s.isEmpty())
                s.push(exp[i]);
            else if (precedence(exp[i]) <= precedence(s.tos())) {
                while (precedence(exp[i]) <= precedence(s.tos()) && !s.isEmpty()) {
                    postfix += s.pop();
                }
                s.push(exp[i]); 
            } else  
                s.push(exp[i]);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    return postfix;
}

string reverseString(const string &exp) {
    string reverse;
    Stack<char> stack;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(')
            stack.push(')');
        else if (exp[i] == ')')
            stack.push('(');
        else
            stack.push(exp[i]);
    }
    while (!stack.isEmpty()) {
        reverse += stack.pop();
    }
    return reverse;
}

string toPreFix(const string &exp) {
    string prefix = reverseString(exp);
    prefix = toPostFix(prefix);
    prefix = reverseString(prefix);
    return prefix;
}

void evaluatePostfix(const string &exp) {
    Stack<int> s;
    int operand1, operand2;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] >= '0' && exp[i] <= '9')
            s.push(exp[i] - '0');
        else if (isOperator(exp[i])) {
            operand2 = s.pop();
            operand1 = s.pop();
            switch (exp[i]) {
            case '^':
                s.push(pow(operand1, operand2));
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;

            default:
                break;
            }
        }
    }
    cout << "The result of the postfix expression " << exp << " = " << s.tos() << endl;
}

char pairOf(char c) {
    return (c == ')') ? '(' : ((c == '}') ? '{' : '[');
}
void checkParenthesis(string exp) {
    Stack<char> s;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            s.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (s.tos() == pairOf(exp[i]))
                s.pop();
            else {
                cout << exp << " = Parenthesis not balanced";
                return;
            }
        }
    }
    if (s.isEmpty())
        cout << exp << " = Balanced parenthesis";
    else
        cout << exp << " = Parenthesis not balanced";
}

int main() {
    cout << "Infix expression = (a+(b*c)"
         << "\t";
    cout << "Postfix = " << toPostFix("(a+(b*c)") << endl;
    cout << "Infix expression = (A - B/C)"
         << "\t\t";
    cout << "Prefix = " << toPreFix("(A - B/C)") << endl;
    evaluatePostfix("34+5*");
    checkParenthesis("[a+{(g)}*h]");
}