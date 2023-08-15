#include <iostream>
#include <cmath>

using namespace std;

#define f(x) x*x*x-2*x-5

int main()
{
    float fa,fb,x1,x2,a,b,xn,e=0.0001;
    int steps = 0;
    cout<<"Enter guesses";
    cin>>x1>>x2;
    a = x1;
    b = x2;
    do
    {
        fa = f(a);
        fb = f(b);
        xn = (a*fb-b*fa)/(fb-fa);
        a = b;
        b = xn;
    }while(fabs(f(xn))>e);
    cout<<xn;
    return 0;
}