//You are given a task to develop a system to read at least 100 integer numbers and
//continue until the user enters No. Your system must have capacity to calculate the sum and
//average of numbers divisible by 9 by not 6
//and display a suitable message if no such number is read". 


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char c;
    int count = 0,n=0;
    float average=0.0,sum=0.0;
    while(count!=100)
    {
        printf("Do you want to continue?? Else type n to exit.\n");
        scanf("%c",&c);
        if( c =='n')
        {
            printf("Avegare = %f Sum = %f\n",average,sum);
            break;
        }
        if(count%9==0 && count%6 != 0)
        {
            sum+=count;
            n+=1;
            average = sum/n;
        }
        count+=1;
    }
    return 0;
}