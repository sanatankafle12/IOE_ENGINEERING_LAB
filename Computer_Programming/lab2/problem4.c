/*  Write a program to read number of girls and boys in your class and display the ratio of
girls to boys */

#include <stdio.h>

int main()
{
    int boys, girls, ratio,i,girl,boy;
    printf("Enter girls and boys Numbers respectively: ");
    scanf("%d %d",&girls,&boys);
    int range = girls;
    for(i=1;i<=range;i++)
    {
        if(girls%i == 0 && boys%i == 0)
        {
            girl = girls/i;
            boy = boys/i;
        }
    }

    printf("The ratio is %d / %d ",girl,boy);
    return 0;
}