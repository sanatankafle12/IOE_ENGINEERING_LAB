#include <stdio.h>

#define MAX_SIZE 100

void countCharacterFrequency(char *str, int *frequency) {
    int i = 0;
    
    // Initialize frequency array to 0
    for (i = 0; i < 26; i++) {
        frequency[i] = 0;
    }
    
    // Iterate over each character in the string
    while (*str != '\0') {
        // Check if the current character is an alphabet
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
            // Convert the character to lowercase
            char ch = tolower(*str);
            
            // Increment the frequency of the character
            frequency[ch - 'a']++;
        }
        
        // Move to the next character
        str++;
    }
}

int main() {
    char str[MAX_SIZE];
    int frequency[26] = {0};  // Assuming only lowercase alphabets
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';
    
    countCharacterFrequency(str, frequency);
    
    // Display the frequency of each character
    printf("Character Frequency:\n");
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0) {
            printf("%c: %d\n", 'a' + i, frequency[i]);
        }
    }
    
    return 0;
}