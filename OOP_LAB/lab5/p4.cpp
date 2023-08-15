//Write a class Date that overloads prefix and postfix operators to increase the Date object by one day, while causing appropriate increments to the month and year (use the appropriate condition for leap year). The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.


#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d = 1, int m = 1, int y = 1970) {
        day = d;
        month = m;
        year = y;
    }

    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }

    Date& operator++() {
        int daysInMonth;
        if (month == 2) {
            if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
        } else if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
            daysInMonth = 30;
        } else {
            daysInMonth = 31;
        }

        if (day < daysInMonth) {
            day++;
        } else {
            day = 1;
            if (month < 12){
                month++;
            } else {
                month = 1;
                year++;
            }
        }

        return *this;
    }

    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }
};

int main() {
    Date d1(28, 2, 2020);

    cout << "Original date: ";
    d1.display();

    ++d1;
    cout << "Date after prefix increment: ";
    d1.display();

    d1++;
    cout << "Date after postfix increment: ";
    d1.display();

    return 0;
}