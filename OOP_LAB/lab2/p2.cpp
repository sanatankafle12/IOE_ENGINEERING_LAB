//Write a program using the function overloading that converts feet to inches. Use function with no argument, one argument and two arguments. Decide yourself the types of arguments. Use pass by reference in any one of the function above.

#include <iostream>
using namespace std;

int convertToInches() {
    int feet;
    cout << "Enter the number of feet: ";
    cin >> feet;
    return feet * 12;
}

int convertToInches(int feet) {
    return feet * 12;
}

void convertToInches(int feet, int& inches) {
    inches = feet * 12;
}

int main() {
    int inches = 0;
    inches = convertToInches();
    cout << "Inches: " << inches << endl;
    inches = convertToInches(5);
    cout << "Inches: " << inches << endl;
    convertToInches(10, inches);
    cout << "Inches: " << inches << endl;

    return 0;
}