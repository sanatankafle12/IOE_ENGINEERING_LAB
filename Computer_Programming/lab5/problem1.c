//WAP to read an unsigned integer 
//and display from 1 to n and n to 1

#include <stdio.h>

int main()
{
    unsigned int n;
    printf("Enter the integer: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",i);
    }
    for(int i=n;i>=1;i--)
    {
        printf("%d\n",i);
    }
    return 0;
}