// Write a program to read an unsigned integer and check whether the number is odd or even.
//If it is even,cheek whether it is greater than 100 or not and display the appropriate message.
//If the number is odd, check whether it is divisible by 11 and not by 7 display the appropriate message

#include <stdio.h>

int main()
{
    unsigned int a;
    printf("Enter the number: ");
    scanf("%d",&a);
    if(a%2==0)
    {
        if(a>100)
        {
            printf("The number is even and greater than 100.");
        }
        else
        {
            printf("The number is even and less than 100.");
        }
    }
    else
    {
        if(a%11==0 && a%7!=0)
        {
            printf("The number is odd and divisible by 11 and not by 7");            
        }
        else
        {
            printf("The number is odd and not divisible by 11 or divisible it is divisble by 11 and by 7.");
        }
    }
    return 0;
}