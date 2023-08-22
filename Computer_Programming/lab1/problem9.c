/*Write a program to read name and age of a person and display them*/

#include <stdio.h>

int main()
{
    int age;
    char name[20];
    printf("Enter your age and name: ");
    scanf("%d %s",&age,&name);
    printf("%s is %d years old.",name,age);
    return 0;
}