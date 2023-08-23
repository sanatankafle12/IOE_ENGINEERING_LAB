#include <stdio.h>
#include <string.h>

int isPalindrome(char *str) {
    int length = strlen(str);
    int i, j;
    
    // Compare characters from both ends of the string
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;  // Not a palindrome
        }
    }
    
    return 1;  // Palindrome
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';
    
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}