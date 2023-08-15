#include <iostream>
using namespace std;

#define MAX_SIZE 1000

class CircularQueue {
private:
    int front;
    int rear;
    int arr[MAX_SIZE];
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Circular queue overflow\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Circular queue underflow\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
    int peek() {
        if (isEmpty()) {
            cout << "Circular queue is empty\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.enqueue(4);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    return 0;
}