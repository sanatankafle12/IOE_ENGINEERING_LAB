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

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }
    bool isEmpty() {
        return head == nullptr;
    }
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
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
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }
        if (temp->next == head && i != pos - 1) {
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
        if (temp->next == head) {
            head = nullptr;
        } else {
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
        }
        delete temp;
    }
    void deleteFromEnd() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        if (temp->next == head) {
            head = nullptr;
        } else {
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node*toDelete = temp->next;
            temp->next = head;
            delete toDelete;
        }
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
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }
        if (temp->next == head && i != pos - 1) {
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
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
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