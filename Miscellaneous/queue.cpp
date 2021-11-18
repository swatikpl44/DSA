#include <iostream>
using namespace std;
 
// A class to store a queue
class queue {
//	int *arr;
    int arr[100005];     
    int limit;   
    int front;   
    int rear;       
    int cnt;     
 
public:
    queue(int size) {
    //arr = new int[size];
    limit = size;
    front = 0;
    rear = -1;
    cnt = 0;
}
 
//~queue() {
//    delete[] arr;
//}
 
void pop()
{
    if (empty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Removing " << arr[front] << endl;
 
    front = (front + 1) % limit;
    cnt--;
}
 
void push(int x)
{
    if (full())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << x << endl;
 
    rear = (rear + 1) % limit;
    arr[rear] = x;
    cnt++;
}
 
// Utility function to return the front element of the queue
int peek()
{
    if (empty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
 
// Utility function to return the size of the queue
int size() {
    return cnt;
}
 
// Utility function to check if the queue is empty or not
bool empty() {
    return (size() == 0);
}
 
// Utility function to check if the queue is full or not
bool full() {
    return (size() == limit);
}
};
 

 
int main()
{
    // create a queue of capacity 5
    queue q(5);
 
    q.push(1);
    q.push(2);
    q.push(3);
 
    cout << "The front element is " << q.peek() << endl;
    q.pop();
 
    q.push(4);
 
    cout << "The queue size is " << q.size() << endl;
 
  	cout << "The front element is " << q.peek() << endl;
    q.pop();
    q.pop();
    q.pop();
 
    if (q.empty()) {
        cout << "The queue is empty\n";
    }
    else {
        cout << "The queue is not empty\n";
    }
 
    return 0;
}
