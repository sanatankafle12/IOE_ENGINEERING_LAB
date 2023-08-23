#include <stdio.h>
#include <ctype.h>

void convertCase(char *str) {
    while (*str != '\0') {
        if (isupper(*str)) {
            *str = tolower(*str);
        } else if (islower(*str)) {
            *str = toupper(*str);
        }
        
        str++;
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';
    
    convertCase(str);
    
    printf("Converted string: %s\n", str);
    
    return 0;
}