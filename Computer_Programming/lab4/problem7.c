// WAP to evaluate the following function f(x) given by 
//  0 if x<=0
//  x(x-10)(x-15) if 0<=x<=10
// (x-10)(x-15)(x-20) if 10<x<=15
// (x-15)(x-20)(x-30) if 15<x<=20
// (x-20)(x-30)(x-40) if 20<x<=30
// 0 for all other cases

#include <stdio.h>
#include <math.h>

int main()
{
    int x ;
    printf("Enter the value of x: ");
    scanf("%d",&x);
    if(x==0)
    {
        printf("0");
    }
    else if(0<x && x<=10)
    {
        printf("%d",x*(x-10)*(x-15));
    }
    else if(10<x && x<=15)
    {
        int temp = (x-10)*(x-15)*(x-20);
        printf("%d",temp);
    }
    else if(15<x && x<=20)
    {
        printf("%d",(x-15)*(x-20)*(x-30));
    }
    else if(20<x && x<=30)
    {
        printf("%d",(x-20)*(x-30)*(x-40));
    }
    else
    {
        printf("0");
    }
    return 0;
}