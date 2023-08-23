#include <stdio.h>

int findLowest(int num1, int num2, int num3) {
    int lowest = (num1 < num2) ? num1 : num2;
    lowest = (lowest < num3) ? lowest : num3;
    return lowest;
}

int findHighest(int num1, int num2, int num3) {
    int highest = (num1 > num2) ? num1 : num2;
    highest = (highest > num3) ? highest : num3;
    return highest;
}

int main() {
    int num1, num2, num3;
    
    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    int lowest = findLowest(num1, num2, num3);
    int highest = findHighest(num1, num2, num3);
    
    printf("Lowest number: %d\n", lowest);
    printf("Highest number: %d\n", highest);
    
    return 0;
}