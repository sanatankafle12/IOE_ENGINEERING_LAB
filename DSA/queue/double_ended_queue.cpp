#include <iostream>
using namespace std;

#define MAX_SIZE 1000

class Deque {
private:
    int front;
    int rear;
    int arr[MAX_SIZE];
public:
    Deque() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }
    void insertFront(int val) {
        if (isFull()) {
            cout << "Deque overflow\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        arr[front] = val;
    }
    void insertRear(int val) {
        if (isFull()) {
            cout << "Deque overflow\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = val;
    }
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque underflow\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque underflow\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[front];
    }
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Deque dq;
    dq.insertFront(1);
    dq.insertFront(2);
    dq.insertRear(3);
    dq.insertRear(4);
    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl;
    dq.deleteFront();
    dq.deleteRear();
    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl;
    dq.deleteFront();
    dq.deleteRear();
    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl;
    dq.deleteFront();
    cout << dq.getFront() << endl;
    return 0;
}