//Write a program that can convert the Distance (meter, centimeter) to meters measurement in float and vice versa. Make a class distance with two data members, meter and centimeter. You can add function members as per your requirement.



#include <iostream>
using namespace std;

class Distance {
private:
    int meter;
    int centimeter;

public:
    Distance(int m = 0, int cm = 0) {
        meter = m;
        centimeter = cm;
    }

    void display() {
        cout << meter << " meters " << centimeter << " centimeters" << endl;
    }

    float toMeters() {
        return meter + (float)centimeter / 100;
    }

    void fromMeters(float m) {
        meter = (int)m;
        centimeter = (m - meter) * 100;
    }

    int toCentimeters() {
        return meter * 100 + centimeter;
    }

    void fromCentimeters(int cm) {
        meter = cm / 100;
        centimeter = cm % 100;
    }
};

int main() {
    Distance d1(5, 75);

    cout << "Original distance: ";
    d1.display();

    float m = d1.toMeters();
    cout << "Distance in meters: " << m << endl;

    Distance d2;
    d2.fromMeters(6.25);
    cout << "Distance from meters: ";
   d2.display();

    int cm = d1.toCentimeters();
    cout << "Distance in centimeters: " << cm << endl;

    Distance d3;
    d3.fromCentimeters(625);
    cout << "Distance from centimeters: ";
    d3.display();

    return 0;
}