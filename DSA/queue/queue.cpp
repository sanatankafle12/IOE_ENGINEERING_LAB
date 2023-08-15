#include <iostream>
using namespace std;

#define MAX_SIZE 1000

class Queue {
private:
    int front;
    int rear;
    int arr[MAX_SIZE];
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue overflow\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        arr[rear] = val;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    return 0;
}