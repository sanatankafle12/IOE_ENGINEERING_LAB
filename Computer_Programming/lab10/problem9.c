#include <stdio.h>
#include <string.h>

#define MAX_ATTEMPTS 3
#define MAX_ANSWER_SIZE 100

int main() {
    char correctAnswer[] = "KP Sharma Oli";
    char answer[MAX_ANSWER_SIZE];
    int attempts = 0;
    
    printf("Who is the prime minister of Nepal?\n");
    
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your answer: ");
        fgets(answer, sizeof(answer), stdin);
        
        answer[strcspn(answer, "\n")] = '\0';
        
        if (strcmp(answer, correctAnswer) == 0) {
            printf("Good!\n");
            return 0;
        } else {
            printf("Try again.\n");
            attempts++;
        }
    }
    
    printf("The correct answer is: %s\n", correctAnswer);
    
    return 0;
}