//Write a program to set a structure to hold a date (mm,dd and yy), assign values to the members of the structure and print out the values in the format 11/28/2004 by function. Pass the structure to the function.

#include <iostream>
using namespace std;

struct Date {
   int month;
   int day;
   int year;
};

void displayDate(Date d) {
   cout << d.month << "/" << d.day << "/" << d.year << endl;
}

int main() {
   Date myDate = {11, 28, 2004};

   displayDate(myDate);

   return 0;
}