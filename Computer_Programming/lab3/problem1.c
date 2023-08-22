//write a program to read character using  getche()/getchar() and display using putch()/putchar)  

#include <conio.h>
#include <stdio.h>

int main()
{
    char c;
    printf("Enter a character:  ");
    c = getche();
    printf("\n");
    putch(c);
    return 0;
}