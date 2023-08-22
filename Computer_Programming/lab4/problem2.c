//Write a program to read an integer fonn the user and check whether it is positive, zero or negative 
//and display the appropriate message on the screen.

#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    if(num == 0)
    {
        printf("It is 0.");
    }
    else if (num>0)
    {
        printf("It is positive.");        
    }
    else
    {
        printf("It is negative.");
    }
    printf("\n");
    return 0;
}