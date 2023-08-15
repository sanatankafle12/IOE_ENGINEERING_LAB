#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    bool isEmpty() {
        return head == nullptr;
    }
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val) {
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
    }
    void insertAtPosition(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        int i = 0;
        while (i < pos - 1 && temp != nullptr) {
            temp = temp->next;
            i++;
        }
       if (temp == nullptr) {
            cout << "Invalid position\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void deleteFromBeginning() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteFromEnd() {
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
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void deleteFromPosition(int pos) {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        if (pos < 0) {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 0) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        int i = 0;
        while (i < pos - 1 && temp->next != nullptr) {
            temp = temp->next;
            i++;
        }
        if (temp->next == nullptr) {
            cout << "Invalid position\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    void printList() {
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
};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtBeginning(0);
    list.insertAtPosition(4, 3);
    list.printList();
    list.deleteFromBeginning();
    list.deleteFromPosition(2);
    list.deleteFromEnd();
    list.printList();
    list.deleteFromEnd();
    list.deleteFromEnd();
    list.deleteFromEnd();
    list.printList();
    return 0;
}