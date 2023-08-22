//Wap to read a char and string using printf and scanf

#include <stdio.h>
#include <string.h>

int main()
{
    char c,str[100];
    printf("Enter a character and a string.");
    scanf("%c %s",&c,&str);
    printf("%c %s",c,str);
    return 0;
}