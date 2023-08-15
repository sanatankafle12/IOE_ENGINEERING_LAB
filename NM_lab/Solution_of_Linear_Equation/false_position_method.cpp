#include <iostream>
#include <cmath>

using namespace std;

#define f(x) x*sin(x)+cos(x)

int main()
{
    float a,b,x1,x2,fa,fb,xn,fxn;
    cout<<"Enter Guesses: ";
    cin>>x1>>x2;
    fa = f(x1);
    fb = f(x2);
    if(fa*fb>0)
    {
        cout<<"non convergent.";
        exit(1);
    }
    if(f(x1)>0)
    {
        b = x1;
        a = x2;
    }
    else
    {
        a = x1;
        b = x2;
    }
    do{
        fa = f(a);
        fb = f(b);
        xn = (a*fb-b*fa)/(fb-fa);
        fxn = f(xn);
        if(fxn>0)
        {
            b = xn;
        }
        else
        {
            a = xn;
        }

    }while(fabs(f(xn))>0.0001);
    cout<<xn;
    return 0;
}