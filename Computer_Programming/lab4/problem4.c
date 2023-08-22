// Write a program to read a character and check whether the character is upper case or lowercase.

#include <stdio.h>

int main()
{
    char c;
    printf("Enter the character: ");
    scanf("%c",&c);
    if(c>=97 && c<=122)
    {
        printf("lowercase");
    }
    if(c>=65 && c<=90)
    {
        printf("Uppercase");
    }
    return 0;
}