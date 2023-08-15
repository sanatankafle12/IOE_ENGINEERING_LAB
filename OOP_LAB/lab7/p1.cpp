//Write a program to create a class shape with functions to find the area of the shapes and display the names of the shapes and other essential components of the class. Create derived classes circle, rectangle, and trapezoid each having overriding functions area() and display(). Write a suitable program to illustrate virtual functions and virtual destructors.

#include <iostream>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(string _name) : name(_name) {}

    virtual float area() = 0;

    virtual void display() {
        cout << "Shape name: " << name << endl;
    }
    
    virtual ~Shape() {
        cout << "Shape destructor called" << endl;
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float _radius) : Shape("Circle"), radius(_radius) {}

    float area() {
        return 3.14 * radius * radius;
    }

    void display() {
        Shape::display();
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
    }

    ~Circle() {
        cout << "Circle destructor called" << endl;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle(float _length, float _width) : Shape("Rectangle"), length(_length), width(_width) {}

    float area() {
        return length * width;
    }

    void display() {
        Shape::display();
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << area() << endl;
    }

    ~Rectangle() {
        cout << "Rectangle destructor called" << endl;
    }
};

class Trapezoid : public Shape {
private:
    float base1;
    float base2;
    float height;

public:
    Trapezoid(float _base1, float _base2, float _height) : Shape("Trapezoid"), base1(_base1), base2(_base2), height(_height) {}

    float area() {
        return (base1 + base2) * height / 2;
    }

    void display() {
        Shape::display();
        cout << "Base 1: " << base1 << endl;
        cout << "Base 2: " << base2 << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << area() << endl;
    }

    ~Trapezoid() {
        cout << "Trapezoid destructor called" << endl;
    }
};

int main() {
    Shape* s1 = new Circle(5.0);
    s1->display();
    delete s1;
}