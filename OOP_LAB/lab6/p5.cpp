//Write a base class that asks the user to enter a complex number and make a derived class that adds the complex number of its own with the base. Finally, make a third class that is a friend of derived and calculate the difference of the base complex number and its own complex number.


#include <iostream>
using namespace std;

class Complex {
protected:
    float real;
    float imag;

public:
    Complex() {
        cout << "Enter real and imaginary parts of complex number: ";
        cin >> real >> imag;
    }

    void display() {
        cout << "Complex number: " << real << " + " << imag << "i" << endl;
    }
};

class DerivedComplex : public Complex {
private:
    float addReal;
    float addImag;

public:
    DerivedComplex() {
        cout << "Enter real and imaginary parts of complex number to add: ";
        cin >> addReal >> addImag;
        real += addReal;
        imag += addImag;
    }

    void display() {
        cout << "Complex number to add: " << addReal << " + " << addImag << "i" << endl;
        Complex::display();
    }

    friend class FriendComplex;
};

class FriendComplex {
public:
    void diff(Complex& c, DerivedComplex& dc) {
        float diffReal = c.real - dc.real;
        float diffImag = c.imag - dc.imag;
        cout << "Difference of the complex numbers: " << diffReal << " + " << diffImag << "i" << endl;
    }
};

int main() {
    DerivedComplex dc;
    dc.display();

    Complex c;
    c.display();

    FriendComplex fc;
    fc.diff(c, dc);

    return 0;
}