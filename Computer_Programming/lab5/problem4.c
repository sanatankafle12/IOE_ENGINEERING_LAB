//WAP to read an integer and compute its factorial. 
//Display if factorial not possible

#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    printf("Enter the num: ");
    scanf("%d",&num);
    for(int i=1;i<=(num/2);i++)
    {
        if(num%i==0)
        {
            printf("%d\n",i);
        }
    }
    printf("%d",num);
    return 0;
}