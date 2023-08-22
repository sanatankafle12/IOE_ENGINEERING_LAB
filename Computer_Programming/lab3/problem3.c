//WAP to read a string using gets() and puts()

#include <conio.h>
#include <stdio.h>
#include <strings.h>

int main()
{
    char str[100];
    printf("Enter the string: ");
    gets(str);
    puts(str);
    return 0;
}