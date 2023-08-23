#include <stdio.h>
#include <string.h>

void reverseWord(char *str, int start, int end) {
    if (start >= end) {
        return;  // Base case: start index meets or exceeds end index
    }
    
    // Swap characters at start and end indices
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    // Recursive call with updated start and end indices
    reverseWord(str, start + 1, end - 1);
}

int main() {
    char str[100];
    
    printf("Enter a word: ");
    scanf("%s", str);
    
    int length = strlen(str);
    
    reverseWord(str, 0, length - 1);
    
    printf("Reversed word: %s\n", str);
    
    return 0;
}