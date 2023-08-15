//Write a program to compare two objects of a class that contains an integer value as its data member. Make overloading functions to overload equality(==), less than(<), greater than(>), not equal (!=), greater than or equal to (>=), and less than or equal to(<=) operators using member operator functions.

#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) {
        value = v;
    }

    void display() {
        cout << "Value: " << value << endl;
    }

    bool operator==(const MyClass& other) const {
        return value == other.value;
    }

    bool operator<(const MyClass& other) const {
        return value < other.value;
    }

    bool operator>(const MyClass& other) const {
        return value > other.value;
    }

    bool operator!=(const MyClass& other) const {
        return !(*this == other);
    }

    bool operator>=(const MyClass& other) const {
        return (*this > other) || (*this == other);
    }

    bool operator<=(const MyClass& other) const {
        return (*this < other) || (*this == other);
    }
};

int main() {
    MyClass obj1(5);
    MyClass obj2(10);

    obj1.display();
    obj2.display();

    if (obj1 == obj2) {
        cout << "obj1 == obj2" << endl;
    } else {
        cout << "obj1 != obj2" << endl;
    }

    if (obj1 < obj2) {
        cout << "obj1 < obj2" << endl;
    } else {
        cout << "obj1 >= obj2" << endl;
    }

    if (obj1 > obj2) {
        cout << "obj1 > obj2" << endl;
    } else {
        cout << "obj1 <= obj2" << endl;
    }

    if (obj1 != obj2) {
        cout << "obj1 != obj2" << endl;
    } else {
        cout << "obj1 == obj2" << endl;
    }

    if (obj1 <= obj2) {
        cout << "obj1 <= obj2" << endl;
    } else {
        cout << "obj1 > obj2" << endl;
    }

    if (obj1 >= obj2) {
        cout << "obj1 >= obj2" << endl;
    } else {
        cout << "obj1 < obj2" << endl;
    }

    return 0;
}