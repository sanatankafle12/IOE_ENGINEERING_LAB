// Write a program to find the position of the character 'C' in the sentence "idea without execution is worthless" using pointer and string.

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char sentence[] = "idea without execution is worthless";
    char *ptr = sentence;
    int position = 0;
    
    while (*ptr != '\0') {
        if (*ptr == 'c') {
            cout << "The position of 'C' in the sentence is: " << position << endl;
            break;
        }
        ptr++;
        position++;
    }
    
    if (*ptr == '\0') {
        cout << "The character 'C' was not found in the sentence." << endl;
    }
    
    return 0;
}