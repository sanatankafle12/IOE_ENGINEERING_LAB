//Write a program with classes to represent a circle, rectangle, and triangle. Each class should have data members to represent the actual objects and member functions to read and display objects, find perimeter and area of the objects, and other useful functions. Use the classes to create objects in your program.

#include <iostream>
#include <cmath>
using namespace std;

#define M_PI 3.14

class Circle {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double getRadius() {
        return radius;
    }

    double getArea() {
        return M_PI * radius * radius;
    }

    double getPerimeter() {
        return 2 * M_PI * radius;
    }

    void display() {
        cout << "Circle with radius " << radius << endl;
    }
};

class Rectangle {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double getLength() {
        return length;
    }

    double getWidth() {
        return width;
    }

    double getArea() {
        return length * width;
    }

    double getPerimeter() {
        return 2 * (length + width);
    }

    void display() {
        cout << "Rectangle with length " << length << " and width " << width << endl;
    }
};

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) {
        side1= s1;
        side2 = s2;
        side3 = s3;
    }

    double getSide1() {
        return side1;
    }

    double getSide2() {
        return side2;
    }

    double getSide3() {
        return side3;
    }

    double getArea() {
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double getPerimeter() {
        return side1 + side2 + side3;
    }

    void display() {
        cout << "Triangle with sides " << side1 << ", " << side2 << ", and " << side3 << endl;
    }
};

int main() {
    Circle c(5.0);
    c.display();
    cout << "Area: " << c.getArea() << endl;
    cout << "Perimeter: " << c.getPerimeter() << endl;

    Rectangle r(3.0, 4.0);
    r.display();
    cout << "Area: " << r.getArea() << endl;
    cout << "Perimeter: " << r.getPerimeter() << endl;

    Triangle t(3.0, 4.0, 5.0);
    t.display();
    cout << "Area: " << t.getArea() << endl;
    cout << "Perimeter: " << t.getPerimeter() << endl;

    return 0;
}