//WAP to display sum of even numbers from 1 to n

#include <stdio.h>

int main()
{
    int num,sum=0;
    printf("Enter num: ");
    scanf("%d",&num);
    for(int i = 1;i<=num;i++)
    {
        if(i%2==0)
        {
            sum+=i;   
        }
    }
    printf("%d",sum);
    return 0;
}