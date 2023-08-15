//Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.

#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    Time add(Time t2) {
        Time result;
        result.second = second + t2.second;
        result.minute = minute + t2.minute + result.second / 60;
        result.second %= 60;
        result.hour = hour + t2.hour + result.minute / 60;
        result.minute %= 60;
        return result;
    }

    void display12Hour() {
        string ampm = "AM";
        int h = hour;
        if (h >= 12) {
            ampm = "PM";
            h -= 12;
        }
        if (h == 0) {
            h = 12;
        }
        cout << h << ":" << minute << ":" << second << " " << ampm << endl;
    }

    void display24Hour() {
        cout << hour << ":" << minute<< ":" << second << endl;
    }
};

int main() {
    Time t1;
    cout << "Time 1 in 12-hour format: ";
    t1.display12Hour();
    cout << "Time 1 in 24-hour format: ";
    t1.display24Hour();

    Time t2(10, 30, 45);
    cout << "Time 2 in 12-hour format: ";
    t2.display12Hour();
    cout << "Time 2 in 24-hour format: ";
    t2.display24Hour();

    Time t3 = t1.add(t2);
    cout << "Time 3 in 12-hour format: ";
    t3.display12Hour();
    cout << "Time 3 in 24-hour format: ";
    t3.display24Hour();

    return 0;
}