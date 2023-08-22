/*Write a program to convert the given Centigrade measure to Fahrenheit using relation U F=l.8C+32*/

#include <stdio.h>

int main()
{
    float C,F;
    printf("Enter the celcius measurement: ");
    scanf("%f",&C);
    F = 1.8 * C + 32;
    printf("The fahrenheit measurement is: %.2f",F);
    return 0;
}