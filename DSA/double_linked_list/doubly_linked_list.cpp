#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }
    bool isEmpty() {
        return head == nullptr;
    }
    void addFront(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    void addBack(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void removeFront() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    void removeBack() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }
    void printForward() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void printBackward() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.addFront(1);
    list.addFront(2);
    list.addBack(3);
    list.addBack(4);
    list.printForward(); 
    list.printBackward();
    list.removeFront();
    list.removeBack();
    list.printForward(); 
    list.printBackward(); 
    list.removeFront();
    list.removeBack();
    list.printForward();
    list.printBackward(); 
    return 0;
}