#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <cstring>
using namespace std;
template <typename T>
class Stack {
private:
struct Node {
T data;
Node* next;
Node(T val) : data(val), next(nullptr) {}
};
Node* topNode;
public:
Stack() : topNode(nullptr) {}
~Stack() {
while (!isEmpty()) pop();
}
void push(T value) {
Node* newNode = new Node(value);
newNode->next = topNode;
topNode = newNode;
}
void pop() {
if (isEmpty()) return;
Node* temp = topNode;
topNode = topNode->next;
delete temp;
}
T top() {
if (isEmpty()) throw std::runtime_error("Stack is empty");
return topNode->data;
}
bool isEmpty() {
return topNode == nullptr;
}
};
bool isOperator(char c) {
return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int precedence(char c) {
if (c == '^') return 3;
if (c == '*' || c == '/') return 2;
if (c == '+' || c == '-') return 1;
return -1;
}
string infixToPostfix(string infix) {
Stack<char> st;
string result;
for (char c : infix) {
if (isalnum(c)) {
result += c;
}
else if (c == '(') {
st.push(c);
}
else if (c == ')') {
while (!st.isEmpty() && st.top() != '(') {
result += st.top();
st.pop();
}
if (!st.isEmpty()) st.pop();
}
else if (isOperator(c)) {
while (!st.isEmpty() && precedence(st.top()) >= precedence(c)) {
if (c == '^' && st.top() == '^') break;
result += st.top();
st.pop();
}
st.push(c);
}
}
while (!st.isEmpty()) {
result += st.top();
st.pop();
}
return result;
}
string infixToPrefix(string infix) {
reverse(infix.begin(), infix.end());
for (char &c : infix) {
if (c == '(') c = ')';
else if (c == ')') c = '(';
}
string postfix = infixToPostfix(infix);
reverse(postfix.begin(), postfix.end());
return postfix;
}
int main() {
string infix;
cout << "Enter an infix expression: ";
cin >> infix;
try {
string postfix = infixToPostfix(infix);
string prefix = infixToPrefix(infix);
cout << "Infix : " << infix << endl;
cout << "Postfix : " << postfix << endl;
cout << "Prefix : " << prefix << endl;
}
catch (std::exception &e) {
cout << "Error: " << e.what() << endl;
}
return 0;
}
