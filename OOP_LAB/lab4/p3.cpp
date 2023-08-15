//Write a class that can store Department ID and Department Name with constructors to initialize its members. Write destructor member in the same class and display the message "Object n goes out of the scope". Your program should be made such that it should show the order of constructor and destructor invocation.

#include <iostream>
using namespace std;

class Department {
private:
    int deptId;
    string deptName;

public:
    Department(int id = 0, string name = "") {
        deptId = id;
        deptName = name;
        cout << "Constructor invoked for department " << deptId << endl;
    }

    ~Department() {
        cout << "Destructor invoked for department " << deptId << ". Object goes out of the scope." << endl;
    }

    void display() {
        cout << "Department ID: " << deptId << endl;
        cout << "Department Name: " << deptName << endl;
    }
};

int main() {
    Department d1(1001, "Engineering");
    d1.display();

    {
        Department d2(1002, "Marketing");
        d2.display();
    }

    return 0;
}