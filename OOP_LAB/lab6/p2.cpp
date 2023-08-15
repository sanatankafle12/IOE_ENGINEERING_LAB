//Write two classes to store distances in meter-centimeter and feet-inch systems respectively. Write conversions functions so that the program can convert objects of both types.

#include <iostream>
using namespace std;

class DistanceMC {
private:
    int meter;
    int centimeter;

public:
    DistanceMC(int m = 0, int cm = 0) {
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
    
    DistanceFI toDistanceFI() {
        float totalInches = (meter * 100 + centimeter) / 2.54;
        int feet = totalInches / 12;
        int inches = totalInches - feet * 12;
        return DistanceFI(feet, inches);
    }
};

class DistanceFI {
private:
    int feet;
    int inches;

public:
    DistanceFI(int f = 0, int i = 0) {
        feet = f;
        inches = i;
    }

    void display() {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    float toFeet() {
        return feet + (float)inches / 12;
    }

    void fromFeet(float f) {
        feet = (int)f;
        inches = (f - feet) * 12;
    }

    int toInches() {
        return feet * 12 + inches;
    }

    void fromInches(int i) {
        feet = i / 12;
        inches = i % 12;
    }
    
    DistanceMC toDistanceMC() {
        float totalCentimeters = feet * 30.48 + inches * 2.54;
        int meter = totalCentimeters / 100;
        int centimeter = totalCentimeters - meter * 100;
        return DistanceMC(meter, centimeter);
    }
};

int main() {
    DistanceMC d1(5, 75);

    cout << "Original distance in meter-centimeter system: ";
    d1.display();

    DistanceFI d2 = d1.toDistanceFI();
    cout << "Distance in feet-inch system: ";
    d2.display();

    DistanceMC d3 = d2.toDistanceMC();
   cout << "Distance in meter-centimeter system after conversion: ";
    d3.display();

    return 0;
}