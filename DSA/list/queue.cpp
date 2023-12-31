
#include <iostream>
using namespace std;
#define MAXSIZE 50

template <class T>
struct node {
    T info;
    int next;
};

template <class T>
class Queue {
    node<T> node[MAXSIZE];
    int avail, rear, front;

    int getNode() {
        if (avail == -1) {
            cout << "Overflow";
            exit(1);
        }
        int p = avail;
        avail = node[avail].next;
        return p;
    }

    void freeNode(int p) {
        node[p].next = avail;
        avail = p;
    }

    void initialOrdering() {
        for (int i = 0; i < MAXSIZE - 1; i++)
            node[i].next = i + 1;
        node[MAXSIZE - 1].next = -1;
    }

public:
    Queue() {
        initialOrdering();
        avail = 0;
        rear = front = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(T x) {
        int p = getNode();
        node[p].info = x;
        node[p].next = -1;
        if (rear == -1) 
            front = rear = p;
        else {
            node[rear].next = p;
            rear = p;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }
        int p = front; 
        front = node[p].next;

        T item = node[p].info;
        cout << "Deleted item = " << item << endl;
        if (front == -1) 
            rear = -1;
        freeNode(p);
    }

    void display() {
        cout << "Displaying elements in the queue: ";
        if (isEmpty()) {
            cout << "Empty queue\n";
            return;
        }
        int i = front;
        while (i != -1) {
            cout << node[i].info << ' ';
            i = node[i].next;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q;
    for (int i = 0; i < 7; i++)
        q.enqueue(i);
    q.display();
    for (int i = 0; i < 4; i++)
        q.dequeue();
    q.display();
}