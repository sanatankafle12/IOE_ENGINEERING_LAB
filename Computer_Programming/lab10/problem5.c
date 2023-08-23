#include <stdio.h>
#include <string.h>

void sortStringAlphabetically(char *str) {
    int length = strlen(str);
    int i, j;
    char temp;
    
    // Bubble sort to sort the characters in ascending order
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';
    
    sortStringAlphabetically(str);
    
    printf("Alphabetically sorted string: %s\n", str);
    
    return 0;
}