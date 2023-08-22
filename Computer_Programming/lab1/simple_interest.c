#include <stdio.h>

int main()
{
    float principle = 1000;
    float rate = 5.5;
    float time = 2.5;
    float interest = (principle * rate * time) / 100;
    printf("Simple Interest: Rs %f\n", interest);
    return 0;
}