//Write a simple program that converts the temperature in Celsius scale to Fahrenheit scale and vice versa using the basic concept of class and object. Make separate classes for Celsius and Fahrenheit which will have the private members that hold the temperature value and make conversion functions in each class for conversion from one to another. For example, you need to have a function toFahrenheit() in class Celsius that converts to Fahrenheit scale and returns the value.

#include <iostream>
using namespace std;

class Celsius {
private:
    double temperature;

public:
    Celsius(double temp) {
        temperature = temp;
    }

    double toFahrenheit() {
        return temperature * 9.0 / 5.0 + 32.0;
    }
};

class Fahrenheit {
private:
    double temperature;

public:
    Fahrenheit(double temp) {
        temperature = temp;
    }

    double toCelsius() {
        return (temperature - 32.0) * 5.0 / 9.0;
    }
};

int main() {
    double tempCelsius, tempFahrenheit;
    cout << "Enter temperature in Celsius: ";
    cin >> tempCelsius;

    Celsius celsius(tempCelsius);
    tempFahrenheit = celsius.toFahrenheit();
    cout << tempCelsius << " degrees Celsius is " << tempFahrenheit << " degrees Fahrenheit." << endl;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> tempFahrenheit;

    Fahrenheit fahrenheit(tempFahrenheit);
    tempCelsius = fahrenheit.toCelsius();
    cout << tempFahrenheit << " degrees Fahrenheit is " << tempCelsius << " degrees Celsius." << endl;

    return 0;
}