#include <stdio.h>

int countWords(char *str) {
    int count = 0;
    int isWord = 0;
    
    // Iterate over each character in the string
    while (*str != '\0') {
        // Check if the current character is a whitespace
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            isWord = 0;
        }
        // Check if the current character is the start of a word
        else if (isWord == 0) {
            isWord = 1;
            count++;
        }
        
        // Move to the next character
        str++;
    }
    
    return count;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';
    
    int wordCount = countWords(str);
    
    printf("Number of words: %d\n", wordCount);
    
    return 0;
}