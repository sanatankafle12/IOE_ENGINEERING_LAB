//If a person's age is greater than 65, be gets the seniority allowance. 
//Write a program to read the age of a person and display the appropriate message.

#include <stdio.h>

int main()
{
    int age;
    printf("Enter your age: ");
    scanf("%d",&age);
    if(age>65)
    {
        printf("You are eligible for the allowance");
    }
    else
    {
        printf("You are not quite of the age");
    }
    return 0;
}
