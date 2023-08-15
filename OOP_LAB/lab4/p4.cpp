//Assume that one constructor initializes data member say num_vehicle, hour, and rate. There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).

#include <iostream>
using namespace std;

class ParkingCharge {
private:
    int num_vehicle;
    float hour;
    float rate;

public:
    ParkingCharge(int n = 0, float h = 0, float r = 0) {
        num_vehicle = n;
        hour = h;
        rate = r;
    }

    ParkingCharge(const ParkingCharge& p) {
        num_vehicle = p.num_vehicle;
        hour = p.hour;
        rate = p.rate;
    }

    float calculate() {
        float charge = num_vehicle * hour * rate;
        if (num_vehicle > 10) {
            charge *= 0.9;
        }
        return charge;
    }

    void display() {
        cout << "Number of vehicles: " << num_vehicle << endl;
        cout << "Hours parked: " << hour << endl;
        cout << "Rate per hour: " << rate << endl;
        cout << "Total charge: " << calculate() << endl;
    }
};

int main() {
    ParkingCharge p1(5, 2.5, 3.5);

    ParkingCharge p2(p1);
    p2.display();

    return 0;
}