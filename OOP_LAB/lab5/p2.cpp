//Write a class to store x, y, and z coordinates of a point in three-dimensional space. Overload addition and subtraction operators for addition and subtraction of two coordinate objects. Implement the operator functions as non-member functions (friend operator functions).

#include <iostream>
using namespace std;

class Coordinate {
private:
    float x;
    float y;
    float z;

public:
    Coordinate(float a = 0, float b = 0, float c = 0) {
        x = a;
        y = b;
        z = c;
    }

    void display() {
        cout << "(" << x << "," << y << "," << z << ")" << endl;
    }

    friend Coordinate operator+(const Coordinate& c1, const Coordinate& c2);
    friend Coordinate operator-(const Coordinate& c1, const Coordinate& c2);
};

Coordinate operator+(const Coordinate& c1, const Coordinate& c2) {
    Coordinate result;
    result.x = c1.x + c2.x;
    result.y = c1.y + c2.y;
    result.z = c1.z + c2.z;
    return result;
}

Coordinate operator-(const Coordinate& c1, const Coordinate& c2) {
    Coordinate result;
    result.x = c1.x - c2.x;
    result.y = c1.y - c2.y;
    result.z = c1.z - c2.z;
    return result;
}

int main() {
   Coordinate c1(2, 3, 4);
    Coordinate c2(5, 6, 7);

    Coordinate c3 = c1 + c2;
    c3.display();

    Coordinate c4 = c2 - c1;
    c4.display();

    return 0;
}