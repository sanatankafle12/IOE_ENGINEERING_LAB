#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int exp;
    Node* next;
    Node(int co, int ex) {
        coeff = co;
        exp = ex;
        next = nullptr;
    }
};

class Polynomial {
private:
    Node* head;
public:
    Polynomial() {
        head = nullptr;
    }
    void addTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void printPolynomial() {
        if (head == nullptr) {
            cout << "Polynomial is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->exp == 0) {
                cout << temp->coeff;
            } else if (temp->exp == 1) {
                cout << temp->coeff << "x";
            } else {
                cout << temp->coeff << "x^" << temp->exp;
            }
            if (temp->next != nullptr && temp->next->coeff >= 0) {
                cout << "+ ";
            } else {
                cout << " ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    Polynomial operator+(Polynomial& other) {
        Polynomial result;
        Node* temp1 = head;
        Node* temp2 = other.head;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->exp == temp2->exp) {
                result.addTerm(temp1->coeff + temp2->coeff, temp1->exp);
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->exp > temp2->exp) {
                result.addTerm(temp1->coeff, temp1->exp);
                temp1 = temp1->next;
            } else {
                result.addTerm(temp2->coeff, temp2->exp);
                temp2 = temp2->next;
            }
        }
        while (temp1 != nullptr) {
            result.addTerm(temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        while (temp2 != nullptr) {
            result.addTerm(temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
        return result;
    }
};

int main() {
    Polynomial poly1;
    poly1.addTerm(3, 2);
    poly1.addTerm(2, 1);
    poly1.addTerm(5, 0);
    cout << "Polynomial 1: ";
    poly1.printPolynomial();

    Polynomial poly2;
    poly2.addTerm(4, 1);
    poly2.addTerm(1, 0);
    cout << "Polynomial 2: ";
    poly2.printPolynomial();

    Polynomial sum = poly1 + poly2;
    cout << "Sum: ";
    sum.printPolynomial();

    return 0;
}