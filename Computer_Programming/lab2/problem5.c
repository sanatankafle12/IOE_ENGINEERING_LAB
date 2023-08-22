/* . Write a prograrite programs to evaluate the following expression:
a. S=x^5 +0.2xy+y^7
b. f = (a+b)^((2x+y)/(p-q)) + c-100
c. r = A/B
d. h = (u/x+v/y)
*/

#include <stdio.h>
#include <math.h>

int main()
{
    float S,x,y,a,b,c,u,v,A,B,p,q,f,r,l,h;
    printf("Enter x,y,a,b,p,q,c,A,B,u,v");
    scanf("%f %f %f %f %f %f %f %f %f %f %f",&x,&y,&a,&b,&p,&q,&c,&A,&B,&u,&v);
    S = pow(x,5) + 0.2 * x * y + y *7;
    l = ((2*x+y)/(p-q));
    f = pow((a+b),l) + c-100;
    r = A/B;
    h = (u/x+v/y);
    printf("S = %.2f \n f = %.2f \n r = %.2f \n h = %.2f \n",S,f,r,h);
    return 0;
}

