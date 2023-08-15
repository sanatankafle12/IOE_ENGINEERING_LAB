/*Assume that an object represents an employee report that contains information like employee id, total bonus, total overtime in a particular year. Use an array of objects to represent n employees' reports. Write a program that displays the report. Use setpara() member function to set report attributes by passing the arguments and member function displayreport() to show the report according to the parameter passed. Display the report in the following format.

An employee with ... ... ... has received Rs ... ... ...as a bonus

and

had worked ... ... ... hours as overtime in the year ... ... ... */

#include <iostream>
using namespace std;

class EmployeeReport {
private:
    int employeeId;
    double totalBonus;
    double totalOvertime;
    int year;

public:
    void setParams(int id, double bonus, double overtime, int yr) {
        employeeId = id;
        totalBonus = bonus;
        totalOvertime = overtime;
        year = yr;
    }

    void displayReport() {
        cout << "An employee with ID " << employeeId << " has received Rs " << totalBonus << " as a bonus and had worked "
             << totalOvertime << " hours as overtime in the year " << year << "." << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of employee reports: ";
    cin >> n;

    EmployeeReport reports[n];

    for (int i = 0; i < n; i++) {
        int id, yr;
        double bonus, overtime;
        cout << "Enter the employee ID, total bonus, total overtime, and year for report " << (i+1) << ": ";
        cin >> id >> bonus >> overtime >> yr;
        reports[i].setParams(id, bonus, overtime, yr);
    }

    for (int i = 0; i < n; i++) {
        reports[i].displayReport();
    }

    return 0;
}