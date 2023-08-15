//Create a class with a data member to hold a "serial number" for each object created from the class. That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members. Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the use of static member function.

#include <iostream>
using namespace std;

class SerialNumber {
private:
    int serial;
    static int nextSerial;

public:
    SerialNumber() {
        serial = nextSerial++;
    }

    void display() {
        cout << "Serial Number: " << serial << endl;
    }

    static int getNextSerial() {
        return nextSerial;
    }
};

int SerialNumber::nextSerial = 1;

int main() {
    SerialNumber s1, s2, s3;

    s1.display();
    s2.display();
    s3.display();

    cout << "Next available serial number: " << SerialNumber::getNextSerial() << endl;

    return 0;
}