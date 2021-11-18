#include <iostream>
using namespace std;
 
class stack {
    int arr[100005];
    int top;
    int limit;
 
public:
    // Constructor to initialize the stack
stack(int size) {
    limit = size;
    top = -1;
}
 
// Destructor to free memory allocated to the stack
//stack::~stack() {
//    delete[] arr;
//}
 
// Utility function to add an element `x` to the stack
void push(int x)
{
    if (full())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << x << endl;
    arr[++top] = x;
}
 
// Utility function to pop a top element from the stack
int pop()
{
    // check for stack underflow
    if (empty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Removing " << peek() << endl;
 
    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}
 
// Utility function to return the top element of the stack
int peek()
{
    if (!empty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// Utility function to return the size of the stack
int size() {
    return top + 1;
}
 
// Utility function to check if the stack is empty or not
bool empty() {
    return top == -1;               // or return size() == 0;
}
 
// Utility function to check if the stack is full or not
bool full() {
    return top == limit - 1;     // or return size() == capacity;
}

};
 
int main()
{
    stack pt(5);
 
    pt.push(1);
    pt.push(2);
 
    pt.pop();
    pt.pop();
 
    pt.push(3);
 
    cout << "The top element is " << pt.peek() << endl;
    cout << "The stack size is " << pt.size() << endl;
 
    pt.pop();
 
    if (pt.empty()) {
        cout << "The stack is empty\n";
    }
    else {
        cout << "The stack is not empty\n";
    }
 
    return 0;
}
