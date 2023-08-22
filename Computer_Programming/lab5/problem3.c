// WAP to read an integer and find product from 1 to n if n is even else sum

#include <stdio.h>

int main()
{
    int n,sum=0,product=1;
    printf("Enter n: ");
    scanf("%d",&n);
    if(n%2==0)
    {
        for(int i=1;i<=n;i++)
        {
            product = product *i;
        }
        printf("Product = %d\n",product);
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            sum+=i;
        }        
        printf("Sum = %d\n",sum);
    }
    return 0;
}