/*    Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.

A. Make a particular member function of one class as a friend function of another class for addition.

B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.

C. Also write a small program to demonstrate that all the member functions of one class are the friend functions of another class if the former class is made friend to the latter.

Make least possible classes to demonstrate all the above in a single program without conflict.*/

#include <iostream>
using namespace std;

class Vector;

class Point {
private:
    float x;
    float y;

public:
    Point(float a = 0, float b = 0) {
        x = a;
        y = b;
    }

    void display() {
        cout << "(" << x << "," << y << ")" << endl;
    }

    friend Point add(const Point& p, const Vector& v);
    friend Vector subtract(const Point& p1, const Point& p2);
    friend Vector multiply(const Vector& v, float scalar);
    friend Vector divide(const Vector& v, float scalar);
};

class Vector {
private:
    float x;
    float y;

public:
    Vector(float a = 0, float b = 0) {
        x = a;
        y = b;
    }

    void display() {
        cout << "[" << x << "," << y << "]" << endl;
    }

    friend Point add(const Point& p, const Vector& v);
    friend Vector subtract(const Point& p1, const Point& p2);
    friend Vector multiply(const Vector& v, float scalar);
    friend Vector divide(const Vector& v, float scalar);
};

// friend function to add a vector to a point
Point add(const Point& p, const Vector& v) {
    Point result;
    result.x = p.x + v.x;
    result.y = p.y + v.y;
    return result;
}

Vector subtract(const Point& p1, const Point& p2) {
    Vector result;
    result.x = p1.x - p2.x;
    result.y = p1.y - p2.y;
    return result;
}

Vector multiply(const Vector& v, float scalar) {
    Vector result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    return result;
}

Vector divide(const Vector& v, float scalar) {
    Vector result;
    result.x = v.x / scalar;
    result.y = v.y / scalar;
    return result;
}

int main() {
    Point p1(2, 3);
    Vector v1(4, 5);

    Point p2 = add(p1, v1);
    p2.display();

    Point p3(6, 7);
    Vector v2 = subtract(p2, p3);
    v2.display();

    Vector v3 = multiply(v2, 2);
    v3.display();

    Vector v4 = divide(v3, 3);
    v4.display();

    return 0;
}