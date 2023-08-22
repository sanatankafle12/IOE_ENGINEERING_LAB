//Write a progr.am that asks an arithmetic operator and two operands and performs the corresponding operation on the operands.

#include <stdio.h>

int main()
{
    char c;
    float a,b;
    printf("Enter the operator and two operands: ");
    scanf("%c %f %f",&c,&a,&b);
    switch (c)
    {
    case '+':
        printf("%.2f",(a+b));
        break;
    case '-':
        printf("%.2f",(a-b));
        break;
    case '*':
        printf("%.2f",(a*b));
        break;
    case '/':
        printf("%.2f",(a/b));
        break;
    default:
        printf("Enter valid operator. ");
        break;
    }
    return 0;
}